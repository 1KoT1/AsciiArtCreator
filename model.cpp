#include "model.h"
#include <QCoreApplication>
#include "tools.h"

Model::Model(QObject *parent) :
    QObject(parent),
    QQuickImageProvider(QQuickImageProvider::Pixmap),
		m_image(Tools::qmlResPath("AsciiArtGenirator80.png")),
    m_surceImg(QImage(m_image)),
    m_modifedImg(m_surceImg),
    m_modifedImgURI(QString("image://%0/%1").arg(gameModel).arg(modifedImgStr)),
    mAlgorithm(Algorithmes::OnePixelOneChar)
{
}

const QString &Model::image() const{
    return m_image;
}

void Model::setImage(const QString img){
    if(img != m_image){
        m_image = img;
        if(!m_surceImg.load(m_image)){
            m_surceImg = QImage(1, 1, QImage::Format_Mono);
            m_surceImg.fill(0);
        }
        setModifedImg(m_surceImg);
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

Algorithmes::AlgorithmesEnum Model::algorithm() const{
    return mAlgorithm;
}

void Model::setAlgorithm(Algorithmes::AlgorithmesEnum value){
    if(value != mAlgorithm){
        mAlgorithm = value;
        emit algorithmChanged();
    }
}

OnePixelOneCharModel *Model::onePixelOneCharModel(){
    return &mOnePixelOneCharModel;
}

OnePixelMoneyCharsModel *Model::onePixelMoneyCharsModel(){
    return &mOnePixelMoneyCharsModel;
}
