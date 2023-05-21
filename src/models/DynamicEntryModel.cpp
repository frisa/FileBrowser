#include "DynamicEntryModel.hpp"

DynamicEntryModel::DynamicEntryModel(const QObject *parent)
{
    m_roleNames[RoleNames::NameRole] = "name";
    m_roleNames[RoleNames::DescriptionRole] = "description";
    m_data.append(DataEntry{"name1", "description1"});
    m_data.append(DataEntry{"name2", "description2"});
}

DynamicEntryModel::~DynamicEntryModel()
{
}

int DynamicEntryModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.count();
}

QVariant DynamicEntryModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if (row < 0 || row >= m_data.count())
    {
        return QVariant();
    }
    const DataEntry &value = m_data.at(row);
    qDebug() << "ROW:" << row << "ROLE:" << role;
    switch (role)
    {
    case NameRole:
        qDebug() << "VALUE: " << value.name;
        return value.name;
    case DescriptionRole:
        qDebug() << "VALUE: " << value.description;
        return value.description;
    }
    return QVariant();
}

QHash<int, QByteArray> DynamicEntryModel::roleNames() const
{
    return m_roleNames;
}

int DynamicEntryModel::getCount()
{
    return m_data.count();
}

Q_INVOKABLE DataEntry DynamicEntryModel::get(int index)
{
    if (index < 0 || index >= m_data.count())
    {
        return DataEntry();
    }
    return m_data.at(index);
}

Q_INVOKABLE void DynamicEntryModel::insert(int index, const QString &value)
{
    if (index < 0 || index > m_data.count())
    {
        return;
    }
    DataEntry entry{value, "Added"};
    // view protocol (begin => manipulate => end]
    emit beginInsertRows(QModelIndex(), index, index);
    m_data.insert(index, entry);
    emit endInsertRows();
    // update our count property
    emit countChanged(m_data.count());
}

Q_INVOKABLE void DynamicEntryModel::append(const QString &value)
{
    insert(getCount(), value);
}

Q_INVOKABLE void DynamicEntryModel::remove(int index)
{
    if (index < 0 || index >= m_data.count())
    {
        return;
    }
    emit beginRemoveRows(QModelIndex(), index, index);
    m_data.removeAt(index);
    emit endRemoveRows();
    // do not forget to update our count property
    emit countChanged(m_data.count());
}

Q_INVOKABLE void DynamicEntryModel::clear()
{
    return Q_INVOKABLE void();
}
