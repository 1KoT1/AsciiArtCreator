#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString image READ image NOTIFY imageChanged)
	Q_PROPERTY(QString asciiArt READ asciiArt NOTIFY asciiArtChanged)
	Q_PROPERTY(QString whiteChar READ whiteChar NOTIFY whiteCharChanged)
	Q_PROPERTY(QString blackChar READ blackChar NOTIFY blackCharChanged)
	Q_PROPERTY(int asciiArtWight READ asciiArtWight NOTIFY asciiArtWightChanged)

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

	/** Ширина результата в символах */
	int asciiArtWight() const;
	void setAasciiArtWight(int w);

	const QChar & whiteChar() const;
	void setWhiteChar(const QChar & ch);
	const QChar & blackChar() const;
	void setBlackChar(const QChar &ch);
signals:
	void imageChanged();
	void asciiArtChanged();
	void whiteCharChanged();
	void blackCharChanged();
	void asciiArtWightChanged();

public slots:
private:
	QString m_image;
	QString m_asciiArt;
	QChar m_whiteChar;
	QChar m_blackChar;
	int m_AsciiArtWight;
};

#endif // MODEL_H
