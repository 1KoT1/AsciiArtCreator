#include "controller.h"
#include "model.h"
#include <QImage>
#include <QBitmap>
#include <QDebug>
#include <QFileDialog>
#include <QApplication>

Controller::Controller(Model * model, QObject *parent) :
	QObject(parent),
	m_model (model)
{
}

void Controller::calcAsciiArt(){
    auto img = m_model->modifedImg().scaled(m_model->asciiArtWight(), m_model->asciiArtWight() * (float)m_model->modifedImg().height() / m_model->modifedImg().width()).convertToFormat(QImage::Format_Indexed8, {qRgb(255, 255, 255), qRgb(0, 0, 0)});
	auto imgData = img.constBits();
	QString res;
	for (int i = 0; i < img.byteCount(); ++i) {
		if (*(imgData + i)) {
			res.append(m_model->blackChar());
		} else {
			res.append(m_model->whiteChar());
		}
		if(i && i % m_model->asciiArtWight() == 0)
			res.append('\n');
	}
	m_model->setAsciiArt(res);
}

void Controller::setWhiteChar(const QString &str){
	if (str.isNull() || str.isEmpty())
		return;
	auto ch = str.at(0);
	if(ch.isNonCharacter())
		return;
	m_model->setWhiteChar(ch);
}

void Controller::setBlackChar(const QString &str){
	if (str.isNull() || str.isEmpty())
		return;
	auto ch = str.at(0);
	if(ch.isNonCharacter())
		return;
	m_model->setBlackChar(ch);
}

void Controller::setAsciiArtWight(const QString w){
	bool ok;
	auto res = w.toInt(&ok);
	if(ok)
		m_model->setAasciiArtWight(res);
}

void Controller::setImage(const QString img){
	m_model->setImage(img);
}

void Controller::setImage(){
	auto fileName = QFileDialog::getOpenFileName(QApplication::activeWindow (),
			trUtf8("Открыть изображение"), "", trUtf8("Изображения (*.png *.jpg *.bmp)"));
	if(fileName.isNull())
		return;
    setImage(fileName);
}

void Controller::setModifedImgHeight(const QString &height){
    bool ctrl;
    int res = height.toInt(&ctrl);
    if(ctrl)
        setModifedImgHeight(res);
}

void Controller::setModifedImgHeight(int height){
    modifImage(m_model->modifedImgWidth(), height);
}

void Controller::setModifedImgWidth(const QString &width){
    bool ok;
    auto res = width.toInt(&ok);
    if(ok)
        setModifedImgWidth(res);
}

void Controller::setModifedImgWidth(int width){
    modifImage(width, m_model->modifedImgHeight());
}

bool isAsciiArtSimbol(const QChar & ch, const QFontMetrics &fm){
    return ch.isPrint()
            && ch.script() != QChar::Script_Arabic && ch.script() != QChar::Script_Syriac && ch.script() != QChar::Script_Georgian && ch.script() != QChar::Script_Nko && ch.script() != QChar::Script_Hebrew
            && fm.inFont(ch) && fm.boundingRect(ch).x() >= 0;
}

void Controller::printFont(const QFont &f){
    QFontMetrics fm(f);
    for(uchar c = 0; c < 255; ++c)
        for(uchar r = 0; r < 255; ++r){
            QChar ch(c, r);
            if(isAsciiArtSimbol(ch, fm))
                qDebug()<<ch<<fm.boundingRect(ch)<<ch.script();
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

void Controller::modifImage(int newWidth, int newHeight){
    m_model->setModifedImg(m_model->sourcedImg().scaled(newWidth, newHeight));
}
