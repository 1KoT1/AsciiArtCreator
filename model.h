#ifndef MODEL_H
#define MODEL_H

#include "algorithmes.h"
#include "onepixelonecharmodel.h"
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
    Q_PROPERTY(int asciiArtWight READ asciiArtWight NOTIFY asciiArtWightChanged)
    Q_PROPERTY(QString modifedImgURI READ modifedImgURI NOTIFY modifedImgURIChanged)
    Q_PROPERTY(int modifedImgHeight READ modifedImgHeight NOTIFY modifedImgChanged)
    Q_PROPERTY(int modifedImgWidth READ modifedImgWidth NOTIFY modifedImgChanged)
    Q_PROPERTY(int algorithm READ algorithm NOTIFY algorithmChanged)
    Q_PROPERTY(QObject* onePixelOneCharModel READ onePixelOneCharModel NOTIFY onePixelOneCharModelChanged)

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
    OnePixelOneCharModel *onePixelOneCharModel();
signals:
    void imageChanged();
    void asciiArtChanged();
    void asciiArtWightChanged();
    void modifedImgURIChanged();
    void modifedImgChanged();
    void algorithmChanged();
    void onePixelOneCharModelChanged();

public slots:
private:
    QString m_image;
    QString m_asciiArt;
    int m_AsciiArtWight;
    QImage m_surceImg;
    QImage m_modifedImg;
    QString m_modifedImgURI;
    Algorithmes::AlgorithmesEnum mAlgorithm;
    OnePixelOneCharModel mOnePixelOneCharModel;
};

#endif // MODEL_H
