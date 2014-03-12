#include <QApplication>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"
#include "model.h"
#include "controller.h"

#include <QFont>
#include <QFontMetrics>
#include <QDebug>

int main(int argc, char *argv[])
{
        QApplication app(argc, argv);

        qmlRegisterType<Algorithmes>("AsciiArtGenirator", 1, 0, "Algorithmes");
		QtQuick2ApplicationViewer viewer;
		auto model = new Model(&app);
        auto controller = new Controller(model, &app);
		controller->calcAsciiArt();
		viewer.engine()->addImageProvider(gameModel, model);
		viewer.rootContext()->setContextProperty(gameModel, model);
		viewer.rootContext()->setContextProperty("controller", controller);
    viewer.setMainQmlFile(QStringLiteral("qml/AsciiArtGenirator/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
