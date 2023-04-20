#include <QCoreApplication>
#include <QString>

#include <iostream>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    std::cout << "The Qt console application has started" << std::endl;
    QString application_directory_path = app.applicationDirPath();
    QString application_file_path = app.applicationFilePath();
    QString application_name = app.applicationName();
    qint64 application_pid = app.applicationPid();

    // print out some information about the application
    std::cout << "Application directory path: " << application_directory_path.toStdString() << std::endl;
    std::cout << "Application file path: " << application_file_path.toStdString() << std::endl;
    std::cout << "Application name: " << application_name.toStdString() << std::endl;
    std::cout << "Application PID: " << application_pid << std::endl;
    return app.exec();
}