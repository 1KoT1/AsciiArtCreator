#include "onepixelonecharmodel.h"

OnePixelOneCharModel::OnePixelOneCharModel(QObject *parent) :
    QObject(parent),
    m_whiteChar('_'),
    m_blackChar('@')
{}


const QChar &OnePixelOneCharModel::whiteChar() const{
    return m_whiteChar;
}

void OnePixelOneCharModel::setWhiteChar(const QChar &ch){
    if(ch != m_whiteChar){
        m_whiteChar = ch;
        emit whiteCharChanged();
    }
}

const QChar &OnePixelOneCharModel::blackChar() const{
    return m_blackChar;
}

void OnePixelOneCharModel::setBlackChar(const QChar &ch){
    if(ch != m_blackChar){
        m_blackChar = ch;
        emit blackCharChanged();
    }
}
