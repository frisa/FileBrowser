#include <QDebug>
#include <filesystem>
#include "FileSystem.hpp"

void FileSystemCls::doGetCurrentPath()
{
    qDebug() << "Get current path has been called";
}

QString FileSystemCls::currentPath() const
{
    std::filesystem::path currentPath;
    currentPath = std::filesystem::current_path();
    return QString(currentPath.c_str());
}
