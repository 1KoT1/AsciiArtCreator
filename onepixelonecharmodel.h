#ifndef ONEPIXELONECHARMODEL_H
#define ONEPIXELONECHARMODEL_H

#include <QObject>

class OnePixelOneCharModel : public QObject{
    Q_OBJECT
    Q_PROPERTY(QString whiteChar READ whiteChar NOTIFY whiteCharChanged)
    Q_PROPERTY(QString blackChar READ blackChar NOTIFY blackCharChanged)
public:
    explicit OnePixelOneCharModel(QObject *parent = 0);

    const QChar & whiteChar() const;
    void setWhiteChar(const QChar & ch);
    const QChar & blackChar() const;
    void setBlackChar(const QChar &ch);

signals:
    void whiteCharChanged();
    void blackCharChanged();

public slots:
private:
    QChar m_whiteChar;
    QChar m_blackChar;

};

#endif // ONEPIXELONECHARMODEL_H
