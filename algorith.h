#ifndef ALGORITH_H
#define ALGORITH_H

#include <QObject>
#include <QImage>

class Algorith : public QObject
{
	Q_OBJECT
public:
	explicit Algorith(QObject *parent = 0);
	virtual QString run(const QImage &img) const = 0;
	virtual void runAsinc(const QImage &img) const = 0;
signals:
	void done(const QString &res);
public slots:

};

#endif // ALGORITH_H
