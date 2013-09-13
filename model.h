#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString image READ image NOTIFY imageChanged)
	Q_PROPERTY(QString asciiArt READ asciiArt NOTIFY asciiArtChanged)

public:
	explicit Model(QObject *parent = 0);
	
	/** Адрес файла картинки.*/
	const QString & image() const;
	/** Задать адрес файла картинки.*/
	void setImage(const QString img);

	/** Результат вычислений.*/
	const QString & asciiArt() const;
	/** Задать результат вычислений.*/
	void setAsciiArt(const QString art);
signals:
	void imageChanged();
	void asciiArtChanged();
	
public slots:
private:
	QString m_image;
	QString m_asciiArt;
	QChar m_whiteChar;
	QChar m_blackChar;
};

#endif // MODEL_H
