#include "model.h"
#include <QCoreApplication>

Model::Model(QObject *parent) :
	QObject(parent),
	QQuickImageProvider(QQuickImageProvider::Pixmap),
    m_image("qml/AsciiArtGenirator/AsciiArtGenirator80.png"),
	m_whiteChar('_'),
	m_blackChar('@'),
	m_AsciiArtWight(80),
    m_surceImg(QImage(m_image)),
    m_modifedImg(m_surceImg),
    m_modifedImgURI(QString("image://%0/%1").arg(gameModel).arg(modifedImgStr))
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

QString Model::modifedImgURI() const{
    return m_modifedImgURI;
}

void Model::setModifedImgURI(const QString &uri){
    if(uri != m_modifedImgURI){
        m_modifedImgURI = uri;
        emit modifedImgURIChanged();
    }
}

const QImage &Model::modifedImg() const {
    return m_modifedImg;
}

const QImage &Model::sourcedImg() const{
    return m_surceImg;
}

void Model::setModifedImg(const QImage &img)
{
    m_modifedImg = img;
    emit modifedImgChanged();
}

QPixmap Model::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) {
    if(id == modifedImgStr) {
		if (size)
			*size = m_modifedImg.size();

		if(requestedSize.width() < 0 || requestedSize.height() < 0 || requestedSize == m_modifedImg.size())
			return QPixmap::fromImage(m_modifedImg);
		else {
			auto pmap = QPixmap::fromImage(m_modifedImg);
			pmap.scaled(requestedSize);
			return pmap;
		}
	}
	else
        return QQuickImageProvider::requestPixmap(id, size, requestedSize);
}

int Model::modifedImgWidth() const{
    return m_modifedImg.width();
}

int Model::modifedImgHeight() const{
    return m_modifedImg.height();
}

const QChar &Model::blackChar() const{
	return m_blackChar;
}
