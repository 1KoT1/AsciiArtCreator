#ifndef MODEL_H
#define MODEL_H

#include "algorithmes.h"
#include <QObject>
#include <QImage>
#include <QPixmap>
#include <QtQml>
#include <QQuickImageProvider>

const QLatin1String gameModel("gameModel");
const QLatin1String modifedImgStr("modifedimg");

class Model : public QObject, public QQuickImageProvider
{
    Q_OBJECT
    Q_PROPERTY(QString image READ image NOTIFY imageChanged)
    Q_PROPERTY(QString asciiArt READ asciiArt NOTIFY asciiArtChanged)
    Q_PROPERTY(QString whiteChar READ whiteChar NOTIFY whiteCharChanged)
    Q_PROPERTY(QString blackChar READ blackChar NOTIFY blackCharChanged)
    Q_PROPERTY(int asciiArtWight READ asciiArtWight NOTIFY asciiArtWightChanged)
    Q_PROPERTY(QString modifedImgURI READ modifedImgURI NOTIFY modifedImgURIChanged)
    Q_PROPERTY(int modifedImgHeight READ modifedImgHeight NOTIFY modifedImgChanged)
    Q_PROPERTY(int modifedImgWidth READ modifedImgWidth NOTIFY modifedImgChanged)
    Q_PROPERTY(int algorithm READ algorithm NOTIFY algorithmChanged)

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

    QString modifedImgURI() const;
    void setModifedImgURI(const QString &uri);
    const QImage &modifedImg() const;
    const QImage &sourcedImg() const;
    void setModifedImg(const QImage &img);
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
    int modifedImgWidth() const;
    int modifedImgHeight() const;

    int algorithm() const;
    void setAlgorithm(Algorithmes::AlgorithmesEnum value);
signals:
    void imageChanged();
    void asciiArtChanged();
    void whiteCharChanged();
    void blackCharChanged();
    void asciiArtWightChanged();
    void modifedImgURIChanged();
    void modifedImgChanged();
    void algorithmChanged();

public slots:
private:
    QString m_image;
    QString m_asciiArt;
    QChar m_whiteChar;
    QChar m_blackChar;
    int m_AsciiArtWight;
    QImage m_surceImg;
    QImage m_modifedImg;
    QString m_modifedImgURI;
    Algorithmes::AlgorithmesEnum mAlgorithm;
};

#endif // MODEL_H
