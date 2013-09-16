#include "model.h"
#include <QCoreApplication>

Model::Model(QObject *parent) :
	QObject(parent),
	m_image(qApp->applicationDirPath() + "/qml/AsciiArtGenirator/AsciiArtGenirator80.png"),
	m_whiteChar('_'),
	m_blackChar('@'),
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

void Model::setAasciiArtWight(int w){
	if(w != m_AsciiArtWight){
		m_AsciiArtWight = w;
		emit asciiArtWightChanged();
	}
}

const QChar &Model::whiteChar() const{
	return m_whiteChar;
}

void Model::setWhiteChar(const QChar &ch){
	if(ch != m_whiteChar){
		m_whiteChar = ch;
		emit whiteCharChanged();
	}
}

void Model::setBlackChar(const QChar &ch){
	if(ch != m_blackChar){
		m_blackChar = ch;
		emit blackCharChanged();
	}
}

const QChar &Model::blackChar() const{
	return m_blackChar;
}
