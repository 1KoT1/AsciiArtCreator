#ifndef ONEPIXELONECHAR_H
#define ONEPIXELONECHAR_H

#include "algorith.h"

class OnePixelOneChar : public Algorithm{
	Q_OBJECT
public:
	explicit OnePixelOneChar(const QChar blackChar, const QChar whiteChar, int asciiArtWight, QObject *parent = 0);
	QString run(const QImage &img) const;
	QFuture<QString> runAsinc(const QImage &img) const;
signals:

public slots:
private:
	QChar mBlackChar;
	QChar mWhiteChar;
	int mAsciiArtWight;
};

#endif // ONEPIXELONECHAR_H
