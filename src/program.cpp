#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFileSystemModel>
#include "FileSystem.hpp"

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    FileSystemCls* fileSys = new FileSystemCls();
    QFileSystemModel* fileSysModel = new QFileSystemModel();
    fileSysModel->setRootPath(QDir::currentPath());
    // reigister the data models to the UI
    engine.rootContext()->setContextProperty("fileSystemModel", fileSysModel);
    engine.rootContext()->setContextProperty("fileSystem", fileSys);
    engine.load(QUrl::fromLocalFile("../qml/main.qml"));
    return app.exec();
}