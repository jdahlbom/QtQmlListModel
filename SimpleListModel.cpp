#include "SimpleListModel.h"

#include "DataObject.h"

// You can define custom data roles starting with Qt::UserRole
const int SimpleListModel::FirstNameRole = Qt::UserRole + 1;
const int SimpleListModel::LastNameRole = Qt::UserRole + 2;

SimpleListModel::SimpleListModel(QObject *parent) :
    QAbstractListModel(parent) {
    // Create dummy data for the list
    DataObject *first = new DataObject(QString("Arthur"), QString("Dent"));
    DataObject *second = new DataObject(QString("Ford"), QString("Prefect"));
    DataObject *third = new DataObject(QString("Zaphod"), QString("Beeblebrox"));
    m_items.append(first);
    m_items.append(second);
    m_items.append(third);
}

QHash<int, QByteArray> SimpleListModel::roleNames() const {
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles.insert(FirstNameRole, QByteArray("firstName"));
    roles.insert(LastNameRole, QByteArray("lastName"));
    return roles;
}

int SimpleListModel::rowCount(const QModelIndex &) const {
	return m_items.size();
}

QVariant SimpleListModel::data(const QModelIndex &index,
                                            int role) const {
    if (!index.isValid())
        return QVariant(); // Return Null variant if index is invalid
    if (index.row() > (m_items.size()-1) )
        return QVariant();

    DataObject *dobj = m_items.at(index.row());
    switch (role) {
    case Qt::DisplayRole: // The default display role now displays the first name as well
    case FirstNameRole:
        return QVariant::fromValue(dobj->first);
    case LastNameRole:
        return QVariant::fromValue(dobj->last);
    default:
        return QVariant();
    }
}
