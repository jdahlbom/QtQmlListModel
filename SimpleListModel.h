#include<QObject>
#include<QModelIndex>

class DataObject;

class SimpleListModel : public QAbstractListModel {
	Q_OBJECT
	public:
		SimpleListModel(QObject *parent=0);
		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
		int rowCount(const QModelIndex &parent = QModelIndex()) const;
        QHash<int, QByteArray> roleNames() const;

	private:
		Q_DISABLE_COPY(SimpleListModel);
		QList<DataObject*> m_items;
		static const int FirstNameRole;
		static const int LastNameRole;
};
