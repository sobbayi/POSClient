#ifndef POSMAINTABLEMODEL_H
#define POSMAINTABLEMODEL_H

#include <QTableView>
#include <QPair>
 #include <QList>

class POSMainTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit POSMainTableModel(QObject *parent = 0);
    POSMainTableModel(QList< QPair<QString, QString> > listofPairs, QObject *parent=0);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
    bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QList< QPair<QString, QString> > getList();

signals:
    
public slots:

private:
    QList< QPair<QString, QString> > listOfPairs;
    
};

#endif // POSMAINTABLEMODEL_H
