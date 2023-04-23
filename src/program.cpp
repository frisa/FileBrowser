#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "../inc/FileSystem.hpp"

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    FileSystemCls* fileSys = new FileSystemCls();
    engine.rootContext()->setContextProperty("fileSystem", fileSys);
    engine.load(QUrl::fromLocalFile("../qml/main.qml"));
    return app.exec();
}