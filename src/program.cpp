#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFileSystemModel>

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QFileSystemModel* fileSysModel = new QFileSystemModel();
    fileSysModel->setRootPath(QDir::currentPath());
    engine.rootContext()->setContextProperty("fileSystemModel", fileSysModel);
    engine.load(QUrl::fromLocalFile("../qml/main.qml"));
    return app.exec();
}