#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"
#include "model.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

		QtQuick2ApplicationViewer viewer;
		auto model = new Model(&app);
		viewer.rootContext()->setContextProperty("gameModel", model);
    viewer.setMainQmlFile(QStringLiteral("qml/AsciiArtGenirator/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
