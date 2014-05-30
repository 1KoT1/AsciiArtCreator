#ifndef MODEL_H
#define MODEL_H

#include "algorithmes.h"
#include "algorithmstate.h"
#include "onepixelonecharmodel.h"
#include "onepixelmoneycharsmodel.h"
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
    Q_PROPERTY(QString modifedImgURI READ modifedImgURI NOTIFY modifedImgURIChanged)
    Q_PROPERTY(int modifedImgHeight READ modifedImgHeight NOTIFY modifedImgChanged)
    Q_PROPERTY(int modifedImgWidth READ modifedImgWidth NOTIFY modifedImgChanged)
    Q_PROPERTY(Algorithmes::AlgorithmesEnum algorithm READ algorithm NOTIFY algorithmChanged)
    Q_PROPERTY(QObject* onePixelOneCharModel READ onePixelOneCharModel NOTIFY onePixelOneCharModelChanged)
    Q_PROPERTY(QObject* onePixelMoneyCharsModel READ onePixelMoneyCharsModel NOTIFY onePixelMoneyCharsModelChanged)
    Q_PROPERTY(AlgorithmStates::AlgorithmStateEnum calcAsciiArtState READ calcAsciiArtState WRITE setCalcAsciiArtState NOTIFY calcAsciiArtStateChanged)

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

    QString modifedImgURI() const;
    void setModifedImgURI(const QString &uri);
    const QImage &modifedImg() const;
    const QImage &sourcedImg() const;
    void setModifedImg(const QImage &img);
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
    int modifedImgWidth() const;
    int modifedImgHeight() const;

    Algorithmes::AlgorithmesEnum algorithm() const;
    void setAlgorithm(Algorithmes::AlgorithmesEnum value);
    OnePixelOneCharModel *onePixelOneCharModel();
    OnePixelMoneyCharsModel *onePixelMoneyCharsModel();

    AlgorithmStates::AlgorithmStateEnum calcAsciiArtState() const;
    void setCalcAsciiArtState(AlgorithmStates::AlgorithmStateEnum state);
signals:
    void imageChanged();
    void asciiArtChanged();
    void modifedImgURIChanged();
    void modifedImgChanged();
    void algorithmChanged();
    void onePixelOneCharModelChanged();
    void onePixelMoneyCharsModelChanged();
    void calcAsciiArtStateChanged();

public slots:
private:
    QString m_image;
    QString m_asciiArt;
    QImage m_surceImg;
    QImage m_modifedImg;
    QString m_modifedImgURI;
    Algorithmes::AlgorithmesEnum mAlgorithm;
    OnePixelOneCharModel mOnePixelOneCharModel;
    OnePixelMoneyCharsModel mOnePixelMoneyCharsModel;
    AlgorithmStates::AlgorithmStateEnum mCalcAsciiArtState;
};

#endif // MODEL_H
