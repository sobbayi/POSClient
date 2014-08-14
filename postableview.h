#ifndef POSTABLEVIEW_H
#define POSTABLEVIEW_H

#include <QTableView>
#include <QItemDelegate>
#include "posmaintablemodel.h"


class POSTableView : public QTableView
{
    Q_OBJECT
public:
    explicit POSTableView(QWidget *parent = 0);
    
signals:
    
public slots:


    
};

#endif // POSTABLEVIEW_H
