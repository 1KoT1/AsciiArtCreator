#include "model.h"
#include <QCoreApplication>

Model::Model(QObject *parent) :
	QObject(parent),
	m_image("AsciiArtGenirator80.png"),
	m_whiteChar('@'),
	m_blackChar('_'),
	m_AsciiArtWight(80)
{
}

const QString &Model::image() const{
	return m_image;
}

void Model::setImage(const QString img){
	if(img != m_image){
		m_image = img;
		emit imageChanged();
	}
}

const QString &Model::asciiArt() const{
return m_asciiArt;
}

void Model::setAsciiArt(const QString art){
	if(art != m_asciiArt){
		m_asciiArt = art;
		emit asciiArtChanged();
	}
}

int Model::asciiArtWight() const{
	return m_AsciiArtWight;
}

const QChar &Model::whiteChar() const{
	return m_whiteChar;
}

const QChar &Model::blackChar() const{
	return m_blackChar;
}
