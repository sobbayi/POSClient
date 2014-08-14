
#ifndef MAINTABLEDELEGATE_H
#define MAINTABLEDELEGATE_H

#include <QModelIndex>
#include <QPixmap>
#include <QSize>
#include <QItemDelegate>

QT_FORWARD_DECLARE_CLASS(QPainter)

class MainTableDelegate : public QItemDelegate
{
public:
    MainTableDelegate(QObject *parent);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    bool editorEvent(QEvent *event, QAbstractItemModel *model,
                     const QStyleOptionViewItem &option,
                     const QModelIndex &index);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const;

private:
    QPixmap star;
};

#endif
