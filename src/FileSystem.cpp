#include "../inc/FileSystem.hpp"
#include <QDebug>

void FileSystemCls::doGetCurrentPath()
{
    qDebug() << "Get current path has been called";
}

void FileSystemCls::setCurrentPath(const QString& value)
{
    m_currentPath = value;
}

QString FileSystemCls::currentPath() const
{
    return m_currentPath;
}
