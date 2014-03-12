#include "onepixelmoneycharsmodel.h"

OnePixelMoneyCharsModel::OnePixelMoneyCharsModel(QObject *parent) :
    QObject(parent),
    m_whiteChar("___"),
    m_blackChar("@@")
{}


const QString &OnePixelMoneyCharsModel::whiteChars() const{
    return m_whiteChar;
}

void OnePixelMoneyCharsModel::setWhiteChar(const QString &ch){
    if(ch != m_whiteChar){
        m_whiteChar = ch;
        emit whiteCharChanged();
    }
}

const QString &OnePixelMoneyCharsModel::blackChars() const{
    return m_blackChar;
}

void OnePixelMoneyCharsModel::setBlackChar(const QString &ch){
    if(ch != m_blackChar){
        m_blackChar = ch;
        emit blackCharChanged();
    }
}
