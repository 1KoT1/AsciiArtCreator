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
signals:
	
public slots:
	
private:
	Model * m_model;
};

#endif // CONTROLLER_H
