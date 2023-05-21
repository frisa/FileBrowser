#include "DataEntryModel.hpp"
#include <QColor>

DataEntryModel::DataEntryModel(QObject *parent)
{
    // this is the defualt initialization
    m_data = QColor::colorNames();
}

DataEntryModel::~DataEntryModel()
{
}

int DataEntryModel::rowCount(const QModelIndex &parent) const
{
    return m_data.count();
}

QVariant DataEntryModel::data(const QModelIndex &index, int role) const
{
    // the index return the requested row and column
    int row = index.row();

    // boundary check for the list
    if ((row >= m_data.count()) || (row < 0)){
        return QVariant();
    }

    switch(role){
        case Qt::DisplayRole:
        {
            return m_data.value(row);
        }
        default:
        {
            return QVariant();
        }
    }
}
