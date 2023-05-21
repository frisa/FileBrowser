#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>

// Models
#include <QFileSystemModel>
#include "models/DataEntryModel.hpp"
#include "models/RoleEntryModel.hpp"
#include "models/DynamicEntryModel.hpp"

// custom header files
#include "SystemInfo.hpp"

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQuickStyle::setStyle("macOS"); //this will force the macOS style an all platforms

    // setup the file system model
    QFileSystemModel* fileSysModel = new QFileSystemModel();
    fileSysModel->setRootPath(QDir::currentPath());
    engine.rootContext()->setContextProperty("fileSystemModel", fileSysModel);

    // register the DataEntryModel
    qmlRegisterType<DataEntryModel>("models.sys", 1, 0, "DataEntryModel");

    // register the RoleEntryModel
    qmlRegisterType<RoleEntryModel>("models.sys", 1, 0, "RoleEntryModel");

    // register dynamic model
    qmlRegisterType<DynamicEntryModel>("models.sys", 1, 0, "DynamicEntryModel");

    // setup system info
    SystemInfo* sysInfo = new SystemInfo();
    engine.rootContext()->setContextProperty("sysInfo", sysInfo);

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