#ifndef ONEPIXELONECHAR_H
#define ONEPIXELONECHAR_H

#include "algorith.h"

class OnePixelOneChar : public Algorithm{
	Q_OBJECT
public:
    explicit OnePixelOneChar(const QChar blackChar, const QChar whiteChar, QObject *parent = 0);
    QString run(const QImage &img) const;
signals:

public slots:
private:
	QChar mBlackChar;
    QChar mWhiteChar;
};

#endif // ONEPIXELONECHAR_H
