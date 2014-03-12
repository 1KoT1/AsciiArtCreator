#ifndef ONEPIXELMONEYCHARSMODEL_H
#define ONEPIXELMONEYCHARSMODEL_H

#include <QObject>

class OnePixelMoneyCharsModel : public QObject{
    Q_OBJECT
    Q_PROPERTY(QString whiteChars READ whiteChars NOTIFY whiteCharChanged)
    Q_PROPERTY(QString blackChars READ blackChars NOTIFY blackCharChanged)
public:
    explicit OnePixelMoneyCharsModel(QObject *parent = 0);

    const QString & whiteChars() const;
    void setWhiteChar(const QString & ch);
    const QString & blackChars() const;
    void setBlackChar(const QString &ch);

signals:
    void whiteCharChanged();
    void blackCharChanged();

public slots:
private:
    QString m_whiteChar;
    QString m_blackChar;

};

#endif // ONEPIXELMONEYCHARSMODEL_H
