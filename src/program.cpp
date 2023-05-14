#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFileSystemModel>

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // setup the file system model
    QFileSystemModel* fileSysModel = new QFileSystemModel();
    fileSysModel->setRootPath(QDir::currentPath());
    engine.rootContext()->setContextProperty("fileSystemModel", fileSysModel);

    // setup QML path to the QML engine
    const QUrl url(u"qrc:qt/qml/ui/main/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl){
      if (!obj && url == objUrl)
      {
        QCoreApplication::exit(-1);
      }
      }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}