#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "algorithmes.h"
#include <QObject>

#include <QFontMetrics>

class Model;

class Controller : public QObject
{
	Q_OBJECT
public:
	explicit Controller(Model *model, QObject *parent = 0);
	
	Q_INVOKABLE void calcAsciiArt();


    Q_INVOKABLE void setOnePixelOneCharWhiteChar(const QString &ch);
    Q_INVOKABLE void setOnePixelOneCharBlackChar(const QString &ch);
    Q_INVOKABLE void setOnePixelMoneyCharsWhiteChars(const QString &ch);
    Q_INVOKABLE void setOnePixelMoneyCharsBlackChars(const QString &ch);
	/** Задать адрес файла картинки.*/
	Q_INVOKABLE void setImage(const QString img);
	/** Выбрать файл картинки.*/
    Q_INVOKABLE void setImage();
    /** Изменить высоту картинки.*/
    Q_INVOKABLE void setModifedImgHeight(const QString &height);
    /** Изменить высоту картинки.*/
    Q_INVOKABLE void setModifedImgHeight(int height);
    /** Изменить ширину картинки.*/
    Q_INVOKABLE void setModifedImgWidth(const QString &width);
    /** Изменить ширину картинки.*/
    Q_INVOKABLE void setModifedImgWidth(int width);
    Q_INVOKABLE void setAlgorithm(int value);

    static void printFont(const QFont &f);
    static int maxHeightFont(const QFont &f);
    static qreal averageHeightFont(const QFont &f);
    static int maxStatisticHeightFont(const QFont &f, qreal limit = 1.3);
    static QImage charToImg(const QChar &ch, const QFont &f, int height);
signals:
	
public slots:
	
private:
	Model * m_model;

    void modifImage(int newWidth, int newHeight);
};

#endif // CONTROLLER_H
