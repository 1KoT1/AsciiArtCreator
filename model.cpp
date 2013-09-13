#include "model.h"

Model::Model(QObject *parent) :
	QObject(parent),
	m_whiteChar('@'),
	m_blackChar('_')
{
}

const QString &Model::image() const{
	return m_asciiArt;
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
