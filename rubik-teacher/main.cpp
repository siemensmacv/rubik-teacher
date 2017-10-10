#include "MainWindow.h"
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include <QQuickStyle>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	MainWindow w;

    QGuiApplication::setApplicationName("rubik-teacher");
    QGuiApplication::setOrganizationName("MACV");
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QSettings settings;
    QString style = QQuickStyle::name();
    if (!style.isEmpty())
        settings.setValue("style", style);
    else
        QQuickStyle::setStyle(settings.value("style").toString());

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("availableStyles", QQuickStyle::availableStyles());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //w.show();
	return a.exec();
}
