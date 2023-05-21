#ifndef ROLEENTRYMODEL_HPP
#define ROLEENTRYMODEL_HPP

#include <QtCore>
#include <QColor>
#include <QByteArray>

class RoleEntryRole: public QAbstractListModel
{
    Q_OBJECT
public:
    // define role names to be used
    enum RoleNames{
        NameRole = Qt::UserRole,
        HueRole = Qt::UserRole + 2,
        SaturationRole = Qt::UserRole + 3,
        BrightnessRole = Qt::UserRole + 4
    };
    explicit RoleEntryRole(QObject * parent = 0);
    ~RoleEntryRole();
public:
    // QAbstractItemModel interface 
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &parent, int role) const override;
protected:
    // return the roles mapping to be used by QML
    virtual QHash<int, QByteArray> roleNames() const override;
private:
    QList<QColor> m_data;
    QHash<int, QByteArray> m_roleNames;
    
};

#endif