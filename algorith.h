#ifndef ALGORITH_H
#define ALGORITH_H

#include <QObject>
#include <QImage>
#include <QFuture>

class Algorithm : public QObject
{
	Q_OBJECT
public:
	explicit Algorithm(QObject *parent = 0);
	virtual QString run(const QImage &img) const = 0;
	virtual QFuture<QString> runAsinc(const QImage &img) const = 0;
signals:
public slots:

};

#endif // ALGORITH_H
