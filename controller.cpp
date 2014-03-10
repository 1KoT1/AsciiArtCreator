#include "controller.h"
#include "model.h"
#include <QImage>
#include <QBitmap>
#include <QDebug>
#include <QFileDialog>
#include <QApplication>
#include <QPainter>
#include "onepixelonechar.h"

Controller::Controller(Model * model, QObject *parent) :
	QObject(parent),
	m_model (model)
{
}

void Controller::calcAsciiArt(){
	auto img = m_model->modifedImg().scaled(m_model->asciiArtWight(), m_model->asciiArtWight() * (float)m_model->modifedImg().height() / m_model->modifedImg().width()).convertToFormat(QImage::Format_Indexed8, {qRgb(255, 255, 255), qRgb(0, 0, 0)});
	OnePixelOneChar a(m_model->blackChar(), m_model->whiteChar(), m_model->asciiArtWight());
	m_model->setAsciiArt(a.run(img));
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
