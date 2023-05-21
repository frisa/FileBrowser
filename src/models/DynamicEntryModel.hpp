#ifndef DYNAMICENTRYMODEL_H
#define DYNAMICENTRYMODEL_H

#include <QtCore>

struct DataEntry
{
    QString name;
    QString description;
};

class DynamicEntryModel : public QAbstractListModel
{
    Q_OBJECT
    QList<DataEntry> m_data;

public:
    enum RoleNames
    {
        NameRole = Qt::UserRole,
        DescriptionRole = Qt::UserRole + 2,
    };
    explicit DynamicEntryModel(const QObject *parent = 0);
    ~DynamicEntryModel();

public:
    // QAbstractItemModel interface implementation
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;

protected:
    virtual QHash<int, QByteArray> roleNames() const override;

private:
    QHash<int, QByteArray> m_roleNames;

public:
    // provide the size of the model
    Q_PROPERTY(int pCount READ getCount NOTIFY countChanged)
    int getCount();
    // get the value at the index
    Q_INVOKABLE DataEntry get(int index);
    // modifiers to be implemented
    Q_INVOKABLE void insert(int index, const QString &value);
    Q_INVOKABLE void append(const QString &value);
    Q_INVOKABLE void remove(int index);
    Q_INVOKABLE void clear();
signals:
    void countChanged(int count);
};

#endif