#include "controller.h"
#include "model.h"
#include <QImage>
#include <QBitmap>
#include <QDebug>
#include <QFileDialog>
#include <QApplication>
#include <QPainter>
#include <QtConcurrent/QtConcurrent>
#include "onepixelonechar.h"
#include "onepixelmoneychars.h"

Controller::Controller(Model * model, QObject *parent) :
    QObject(parent),
    m_model (model)
{
}

void Controller::calcAsciiArt(){
    if(calcAsciiArtIsRunning())
        return;

    m_model->setCalcAsciiArtState(AlgorithmStates::Running);
    QtConcurrent::run([&](){
        Algorithm *a;
        switch (m_model->algorithm()) {
        case Algorithmes::OnePixelOneChar:
            a = new OnePixelOneChar(m_model->onePixelOneCharModel()->blackChar(), m_model->onePixelOneCharModel()->whiteChar());
            break;
        case Algorithmes::OnePixelMoneyChars:
        default:
            a = new OnePixelMoneyChars(m_model->onePixelMoneyCharsModel()->blackChars(), m_model->onePixelMoneyCharsModel()->whiteChars());
            break;
        }
        m_model->setAsciiArt(a->run(m_model->modifedImg()));
        delete a;
        m_model->setCalcAsciiArtState(AlgorithmStates::Stoping);
    });
}

void Controller::setOnePixelOneCharWhiteChar(const QString &str){
    if(calcAsciiArtIsRunning())
        return;

    if (str.isNull() || str.isEmpty())
        return;
    auto ch = str.at(0);
    if(ch.isNonCharacter())
        return;
    m_model->onePixelOneCharModel()->setWhiteChar(ch);
}

void Controller::setOnePixelOneCharBlackChar(const QString &str){
    if(calcAsciiArtIsRunning())
        return;

    if (str.isNull() || str.isEmpty())
        return;
    auto ch = str.at(0);
    if(ch.isNonCharacter())
        return;
    m_model->onePixelOneCharModel()->setBlackChar(ch);
}

void Controller::setOnePixelMoneyCharsWhiteChars(const QString &ch){
    if(calcAsciiArtIsRunning())
        return;

    m_model->onePixelMoneyCharsModel()->setWhiteChar(ch);
}

void Controller::setOnePixelMoneyCharsBlackChars(const QString &ch){
    if(calcAsciiArtIsRunning())
        return;

    m_model->onePixelMoneyCharsModel()->setBlackChar(ch);
}

void Controller::setImage(const QString img){
    if(calcAsciiArtIsRunning())
        return;

    m_model->setImage(img);
}

void Controller::setImage(){
    if(calcAsciiArtIsRunning())
        return;

    auto fileName = QFileDialog::getOpenFileName(QApplication::activeWindow (),
                                                 trUtf8("Открыть изображение"), "", trUtf8("Изображения (*.png *.jpg *.bmp)"));
    if(fileName.isNull())
        return;
    setImage(fileName);
}

void Controller::setModifedImgHeight(const QString &height){
    if(calcAsciiArtIsRunning())
        return;

    bool ctrl;
    int res = height.toInt(&ctrl);
    if(ctrl)
        setModifedImgHeight(res);
}

void Controller::setModifedImgHeight(int height){
    if(calcAsciiArtIsRunning())
        return;

    modifImage(m_model->modifedImgWidth(), height);
}

void Controller::setModifedImgWidth(const QString &width){
    if(calcAsciiArtIsRunning())
        return;

    bool ok;
    auto res = width.toInt(&ok);
    if(ok)
        setModifedImgWidth(res);
}

void Controller::setModifedImgWidth(int width){
    if(calcAsciiArtIsRunning())
        return;

    modifImage(width, m_model->modifedImgHeight());
}

void Controller::setAlgorithm(int value){
    if(calcAsciiArtIsRunning())
        return;

    auto key = Algorithmes::m().valueToKey(value);
    if(key)
        m_model->setAlgorithm(static_cast<Algorithmes::AlgorithmesEnum>(value));
    else
        m_model->setAlgorithm(Algorithmes::OnePixelOneChar);
}

bool isAsciiArtSimbol(const QChar & ch, const QFontMetrics &fm){
    return ch.isPrint()
            && ch.script() != QChar::Script_Arabic && ch.script() != QChar::Script_Syriac && ch.script() != QChar::Script_Georgian && ch.script() != QChar::Script_Nko && ch.script() != QChar::Script_Hebrew
            && fm.inFont(ch) && fm.boundingRect(ch).x() >= 0;
}

void Controller::printFont(const QFont &f){
    auto h = maxStatisticHeightFont(f);
    QFontMetrics fm(f);
    for(uchar c = 0; c < 255; ++c)
        for(uchar r = 0; r < 255; ++r){
            QChar ch(c, r);
            if(isAsciiArtSimbol(ch, fm)){
                qDebug()<<ch<<fm.boundingRect(ch)<<ch.script();
                auto img = charToImg(ch, f, h);
                img.save(QString("/home/vasya/qqq/%0_%1_%2_%3_%4_%5.png").arg(ch.row()).arg(ch.cell()).arg(fm.boundingRect(ch).x()).arg(fm.boundingRect(ch).y()).arg(fm.boundingRect(ch).width()).arg(fm.boundingRect(ch).height()));
            }
        }
}

int Controller::maxHeightFont(const QFont &f){
    int res = 0;
    QFontMetrics fm(f);
    for(uchar c = 0; c < 255; ++c)
        for(uchar r = 0; r < 255; ++r){
            QChar ch(c, r);
            if(isAsciiArtSimbol(ch, fm))
                if(fm.boundingRect(ch).height() > res)
                    res = fm.boundingRect(ch).height();
        }
    return res;
}

qreal Controller::averageHeightFont(const QFont &f){
    int count = 0;
    qreal summ = 0;
    QFontMetrics fm(f);
    for(uchar c = 0; c < 255; ++c)
        for(uchar r = 0; r < 255; ++r){
            QChar ch(c, r);
            if(isAsciiArtSimbol(ch, fm)){
                count++;
                summ += fm.boundingRect(ch).height();
            }
        }
    return summ / count;
}

int Controller::maxStatisticHeightFont(const QFont &f, qreal limit){
    auto a = averageHeightFont(f);
    int res = 0;
    QFontMetrics fm(f);
    for(uchar c = 0; c < 255; ++c)
        for(uchar r = 0; r < 255; ++r){
            QChar ch(c, r);
            if(isAsciiArtSimbol(ch, fm))
                if(fm.boundingRect(ch).height() > res && fm.boundingRect(ch).height() / a <= 1.3)
                    res = fm.boundingRect(ch).height();
        }
    return res;
}

QImage Controller::charToImg(const QChar &ch, const QFont &f, int height){
    QFontMetrics fm(f);
    auto r = fm.boundingRect(ch);
    QImage img(r.width() + r.x(), height, QImage::Format_RGB32);
    img.fill(Qt::white);
    QPainter painter(&img);
    painter.setFont(f);
    painter.setPen(QPen(Qt::black, 1));
    painter.drawText(0, -r.y(), ch);
    return img;
}

void Controller::modifImage(int newWidth, int newHeight){
    m_model->setModifedImg(m_model->sourcedImg().scaled(newWidth, newHeight));
}

bool Controller::calcAsciiArtIsRunning(){
    return m_model->calcAsciiArtState() == AlgorithmStates::Running;
}
