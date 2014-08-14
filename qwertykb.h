#ifndef QWERTYKB_H
#define QWERTYKB_H
#include <QMetaType>
#include <QWidget>

namespace Ui {
class QwertyKb;
}

class QwertyKb : public QWidget
{
    Q_OBJECT
    
public:
    explicit QwertyKb(QWidget *parent = 0);
    QwertyKb(const QwertyKb&);
    QString getKey();
    ~QwertyKb();
    void show();


public slots:
    void receiveKeys(QString key);
    void switchToNumPad();
    void switchToQwerty();
    void backSpace();
    void closeQwerty();
    void showName();



    
private:
    Ui::QwertyKb *ui;
    QString charkey;
};
Q_DECLARE_METATYPE(QwertyKb)
#endif // QWERTYKB_H
