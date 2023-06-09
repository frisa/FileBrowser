#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include <QString>

class FileSystemCls : public QObject{
    Q_OBJECT
    Q_PROPERTY(QString currentPath READ currentPath NOTIFY currentPathChanged)

private:
    QString m_currentPath;

public:
    FileSystemCls(): m_currentPath("/root"){};
    QString currentPath() const;

public slots:
    void doGetCurrentPath();

signals:
    void currentPathChanged();
};

#endif