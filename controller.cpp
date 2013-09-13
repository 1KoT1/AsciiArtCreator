#include "controller.h"
#include "model.h"
#include <QImage>
#include <QBitmap>
#include <QDebug>

Controller::Controller(Model * model, QObject *parent) :
	QObject(parent),
	m_model (model)
{
}

void Controller::calcAsciiArt(){
	QImage inputImg(m_model->image());
	auto w = qRgb(255, 255, 255);
	auto b = qRgb(0, 0, 0);
	auto img = inputImg.scaled(m_model->asciiArtWight(), m_model->asciiArtWight() * (float)inputImg.height() / inputImg.width()).convertToFormat(QImage::Format_Indexed8, {w, b});
	auto imgData = img.constBits();
	QString res;
	for (int i = 0; i < img.byteCount(); ++i) {
		if (*(imgData + i)) {
			res.append(m_model->blackChar());
		} else {
			res.append(m_model->whiteChar());
		}
		if(i % m_model->asciiArtWight() == 0)
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
