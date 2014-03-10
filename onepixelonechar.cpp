#include "onepixelonechar.h"
#include <QtConcurrent/QtConcurrentRun>

OnePixelOneChar::OnePixelOneChar(const QChar blackChar, const QChar whiteChar, int asciiArtWight, QObject *parent) :
	Algorithm(parent),
	mBlackChar(blackChar),
	mWhiteChar(whiteChar),
	mAsciiArtWight(asciiArtWight)
{}

QString OnePixelOneChar::run(const QImage &img) const{
	auto imgData = img.constBits();
	QString res;
	for (int i = 0; i < img.byteCount(); ++i) {
		if (*(imgData + i)) {
			res.append(mBlackChar);
		} else {
			res.append(mWhiteChar);
		}
		if(i && i % mAsciiArtWight == 0)
			res.append('\n');
	}
	return res;
}

QFuture<QString> OnePixelOneChar::runAsinc(const QImage &img) const{
	return QtConcurrent::run(this, &OnePixelOneChar::run, img);
}
