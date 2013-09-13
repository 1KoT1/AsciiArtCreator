#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"
#include "model.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

		QtQuick2ApplicationViewer viewer;
		auto model = new Model(&app);
		auto controller = new Controller(model, &app);
		controller->calcAsciiArt();
		viewer.rootContext()->setContextProperty("gameModel", model);
		viewer.rootContext()->setContextProperty("controller", controller);
    viewer.setMainQmlFile(QStringLiteral("qml/AsciiArtGenirator/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
