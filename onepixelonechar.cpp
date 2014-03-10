#include "onepixelonechar.h"
#include <QtConcurrent/QtConcurrentRun>

OnePixelOneChar::OnePixelOneChar(const QChar blackChar, const QChar whiteChar, int asciiArtWight, QObject *parent) :
	Algorithm(parent),
	mBlackChar(blackChar),
	mWhiteChar(whiteChar),
	mAsciiArtWight(asciiArtWight)
{}

QString OnePixelOneChar::run(const QImage &imgsrc) const{
    auto img = imgsrc.convertToFormat(QImage::Format_Indexed8, {qRgb(255, 255, 255), qRgb(0, 0, 0)});
    QString res;
    for(int i = 0; i < img.height(); ++i){
        for(int j = 0; j < img.width(); ++j){
            if(img.pixel(j, i) == qRgb(0, 0, 0))
                res.append(mBlackChar);
            else
                res.append(mWhiteChar);
        }
        res.append('\n');
    }
	return res;
}

QFuture<QString> OnePixelOneChar::runAsinc(const QImage &img) const{
	return QtConcurrent::run(this, &OnePixelOneChar::run, img);
}
