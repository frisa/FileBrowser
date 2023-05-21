#include "RoleEntryModel.hpp"

RoleEntryRole::RoleEntryRole(QObject *parent) : QAbstractListModel(parent)
{
    m_roleNames[NameRole] = "name";
    m_roleNames[HueRole] = "hue";
    m_roleNames[SaturationRole] = "saturation";
    m_roleNames[BrightnessRole] = "brightness";

    for (const QString &name : QColor::colorNames())
    {
        m_data.append(QColor(name));
    }
}

RoleEntryRole::~RoleEntryRole()
{
}

int RoleEntryRole::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.count();
    return 0;
}

QVariant RoleEntryRole::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if (row < 0 || row >= m_data.count())
    {
        return QVariant();
    }
    const QColor &color = m_data.at(row);
    qDebug() << row << role << color;
    switch (role)
    {
    case NameRole:
        return color.name();
    case HueRole:
        return color.hueF();
    case SaturationRole:
        return color.saturationF();
    case BrightnessRole:
        return color.lightnessF();
    }
    return QVariant();
}

QHash<int, QByteArray> RoleEntryRole::roleNames() const
{
    return m_roleNames;
}
