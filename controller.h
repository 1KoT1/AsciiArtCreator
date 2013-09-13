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
signals:
	
public slots:
	
private:
	Model * m_model;
};

#endif // CONTROLLER_H
