#ifndef ONEPIXELMONEYCHARS_H
#define ONEPIXELMONEYCHARS_H

#include "algorith.h"

class OnePixelMoneyChars : public Algorithm{
    Q_OBJECT
public:
    explicit OnePixelMoneyChars(const QString &blackChar, const QString &whiteChar, QObject *parent = 0);
    QString run(const QImage &img) const;
    QFuture<QString> runAsinc(const QImage &img) const;
signals:

public slots:
private:
    QString mBlackChar;
    QString mWhiteChar;
};

#endif // ONEPIXELMONEYCHARS_H
