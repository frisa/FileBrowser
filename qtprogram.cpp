#include <QCoreApplication>
#include <iostream>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    std::cout << "The Qt console application has started" << std::endl;
    return app.exec();
}