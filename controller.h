#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Model;

class Controller : public QObject
{
	Q_OBJECT
public:
	explicit Controller(Model *model, QObject *parent = 0);
	
	Q_INVOKABLE void calcAsciiArt();


	Q_INVOKABLE void setWhiteChar(const QString &ch);
	Q_INVOKABLE void setBlackChar(const QString &ch);
	Q_INVOKABLE void setAsciiArtWight(const QString w);
	/** Задать адрес файла картинки.*/
	Q_INVOKABLE void setImage(const QString img);
	/** Выбрать файл картинки.*/
	Q_INVOKABLE void setImage();
signals:
	
public slots:
	
private:
	Model * m_model;
};

#endif // CONTROLLER_H
