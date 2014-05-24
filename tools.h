#ifndef TOOLS_H
#define TOOLS_H

#include <QObject>

#define path "qml/AsciiArtGenirator"

class Tools : public QObject{
	Q_OBJECT
public:
	explicit Tools(QObject *parent = 0) :
		QObject(parent)
	{}

	Q_INVOKABLE static QString qmlResPath(const QString &name) {
#ifdef Q_OS_ANDROID
		return QString("assets:/%0/%1").arg(path).arg(name);
#else
		return QString("./%0/%1").arg(path).arg(name);
#endif
	}

signals:

public slots:

};

#endif // TOOLS_H
