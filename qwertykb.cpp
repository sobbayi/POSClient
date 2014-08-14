#include <QSignalMapper>
#include <QMessageBox>
#include <QInputContext>
#include "qwertykb.h"
#include "ui_qwertykb.h"
#include <iostream>

QwertyKb::QwertyKb(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QwertyKb)
{
    ui->setupUi(this);
    charkey = "";

    QSignalMapper* signalMapper = new QSignalMapper (this) ;

    ui->pb1->setVisible(false);
    ui->pb2->setVisible(false);
    ui->pb3->setVisible(false);
    ui->pb4->setVisible(false);
    ui->pb5->setVisible(false);
    ui->pb6->setVisible(false);
    ui->pb7->setVisible(false);
    ui->pb8->setVisible(false);
    ui->pb9->setVisible(false);
    ui->pb0->setVisible(false);
    ui->pbSpace_2->setVisible(false);
    ui->pbDash->setVisible(false);

    ui->pbLetter->setVisible(false);
    ui->pbBack_2->setVisible(false);
    ui->pbEnter_2->setVisible(false);


    connect(ui->pbA, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbB, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbC, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbComma, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbD, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbDot, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbE, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbF, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbG, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbH, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbI, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbJ, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbK, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbL, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbM, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbN, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbO, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbQ, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbR, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbS, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbSpace, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbT, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbU, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbV, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbW, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbX, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbY, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbZ, SIGNAL(pressed()), signalMapper, SLOT(map()));

    connect(ui->pbNum, SIGNAL(pressed()), this, SLOT(switchToNumPad()));
    connect(ui->pbBack, SIGNAL(pressed()), this, SLOT(backSpace()));
    connect(ui->pbEnter, SIGNAL(pressed()), this, SLOT(closeQwerty()));

    // for numpad
    connect(ui->pb1, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pb2, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pb3, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pb4, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pb5, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pb6, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pb7, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pb8, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pb9, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pb0, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbSpace_2, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->pbDash, SIGNAL(pressed()), signalMapper, SLOT(map()));

    connect(ui->pbLetter, SIGNAL(pressed()), this, SLOT(switchToQwerty()));
    connect(ui->pbBack_2, SIGNAL(pressed()), this, SLOT(backSpace()));
    connect(ui->pbEnter_2, SIGNAL(pressed()), this, SLOT(closeQwerty()));

    signalMapper->setMapping(ui->pbA, tr("a"));
    signalMapper->setMapping(ui->pbB, tr("b")) ;
    signalMapper->setMapping(ui->pbC, tr("c")) ;
    signalMapper->setMapping(ui->pbComma, tr(",")) ;
    signalMapper->setMapping(ui->pbD, tr("d")) ;
    signalMapper->setMapping(ui->pbDot, tr(".")) ;
    signalMapper->setMapping(ui->pbE, tr("e")) ;
    signalMapper->setMapping(ui->pbF, tr("f")) ;
    signalMapper->setMapping(ui->pbG, tr("g")) ;
    signalMapper->setMapping(ui->pbH, tr("h")) ;
    signalMapper->setMapping(ui->pbI, tr("i")) ;
    signalMapper->setMapping(ui->pbJ, tr("j")) ;
    signalMapper->setMapping(ui->pbK, tr("k")) ;
    signalMapper->setMapping(ui->pbL, tr("l")) ;
    signalMapper->setMapping(ui->pbM, tr("m")) ;
    signalMapper->setMapping(ui->pbN, tr("n")) ;
    signalMapper->setMapping(ui->pbO, tr("o")) ;
    signalMapper->setMapping(ui->pbP, tr("p")) ;
    signalMapper->setMapping(ui->pbQ, tr("q")) ;
    signalMapper->setMapping(ui->pbR, tr("r")) ;
    signalMapper->setMapping(ui->pbS, tr("s")) ;
    signalMapper->setMapping(ui->pbSpace, tr(" ")) ;
    signalMapper->setMapping(ui->pbT, tr("t")) ;
    signalMapper->setMapping(ui->pbU, tr("u")) ;
    signalMapper->setMapping(ui->pbV, tr("v")) ;
    signalMapper->setMapping(ui->pbW, tr("w")) ;
    signalMapper->setMapping(ui->pbX, tr("x")) ;
    signalMapper->setMapping(ui->pbY, tr("y")) ;
    signalMapper->setMapping(ui->pbZ, tr("z")) ;

    signalMapper->setMapping(ui->pb1, tr("1"));
    signalMapper->setMapping(ui->pb2, tr("2"));
    signalMapper->setMapping(ui->pb3, tr("3"));
    signalMapper->setMapping(ui->pb4, tr("4"));
    signalMapper->setMapping(ui->pb5, tr("5"));
    signalMapper->setMapping(ui->pb6, tr("6"));
    signalMapper->setMapping(ui->pb7, tr("7"));
    signalMapper->setMapping(ui->pb8, tr("8"));
    signalMapper->setMapping(ui->pb9, tr("9"));
    signalMapper->setMapping(ui->pb0, tr("0"));
    signalMapper->setMapping(ui->pbSpace_2, tr(" "));
    signalMapper->setMapping(ui->pbDash, tr("-"));

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(receiveKeys(QString))) ;
    setVisible(false);


}

QwertyKb::QwertyKb(const QwertyKb&)
{
}

QwertyKb::~QwertyKb()
{
    delete ui;
}

void QwertyKb::show()
{
    setVisible(true);
}

void QwertyKb::receiveKeys(QString key)
{
    this->charkey = key;

}

QString QwertyKb::getKey()
{

    return this->charkey;
}

void QwertyKb::switchToNumPad()
{
    ui->pb1->setVisible(true);
    ui->pb2->setVisible(true);
    ui->pb3->setVisible(true);
    ui->pb4->setVisible(true);
    ui->pb5->setVisible(true);
    ui->pb6->setVisible(true);
    ui->pb7->setVisible(true);
    ui->pb8->setVisible(true);
    ui->pb9->setVisible(true);
    ui->pb0->setVisible(true);
    ui->pbSpace_2->setVisible(true);
    ui->pbDash->setVisible(true);

    ui->pbLetter->setVisible(true);
    ui->pbBack_2->setVisible(true);
    ui->pbEnter_2->setVisible(true);

    ui->pbA->setVisible(false);
    ui->pbB->setVisible(false);
    ui->pbC->setVisible(false);
    ui->pbComma->setVisible(false);
    ui->pbD->setVisible(false);
    ui->pbDot->setVisible(false);
    ui->pbE->setVisible(false);
    ui->pbF->setVisible(false);
    ui->pbG->setVisible(false);
    ui->pbH->setVisible(false);
    ui->pbI->setVisible(false);
    ui->pbJ->setVisible(false);
    ui->pbK->setVisible(false);
    ui->pbL->setVisible(false);
    ui->pbM->setVisible(false);
    ui->pbN->setVisible(false);
    ui->pbO->setVisible(false);
    ui->pbQ->setVisible(false);
    ui->pbR->setVisible(false);
    ui->pbS->setVisible(false);
    ui->pbSpace->setVisible(false);
    ui->pbT->setVisible(false);
    ui->pbU->setVisible(false);
    ui->pbV->setVisible(false);
    ui->pbW->setVisible(false);
    ui->pbX->setVisible(false);
    ui->pbY->setVisible(false);
    ui->pbZ->setVisible(false);
    ui->pbNum->setVisible(false);
    ui->pbBack->setVisible(false);
    ui->pbEnter->setVisible(false);
}

void QwertyKb::switchToQwerty()
{

    ui->pbA->setVisible(true);
    ui->pbB->setVisible(true);
    ui->pbC->setVisible(true);
    ui->pbComma->setVisible(true);
    ui->pbD->setVisible(true);
    ui->pbDot->setVisible(true);
    ui->pbE->setVisible(true);
    ui->pbF->setVisible(true);
    ui->pbG->setVisible(true);
    ui->pbH->setVisible(true);
    ui->pbI->setVisible(true);
    ui->pbJ->setVisible(true);
    ui->pbK->setVisible(true);
    ui->pbL->setVisible(true);
    ui->pbM->setVisible(true);
    ui->pbN->setVisible(true);
    ui->pbO->setVisible(true);
    ui->pbQ->setVisible(true);
    ui->pbR->setVisible(true);
    ui->pbS->setVisible(true);
    ui->pbSpace->setVisible(true);
    ui->pbT->setVisible(true);
    ui->pbU->setVisible(true);
    ui->pbV->setVisible(true);
    ui->pbW->setVisible(true);
    ui->pbX->setVisible(true);
    ui->pbY->setVisible(true);
    ui->pbZ->setVisible(true);
    ui->pbNum->setVisible(true);
    ui->pbBack->setVisible(true);
    ui->pbEnter->setVisible(true);


    ui->pb1->setVisible(false);
    ui->pb2->setVisible(false);
    ui->pb3->setVisible(false);
    ui->pb4->setVisible(false);
    ui->pb5->setVisible(false);
    ui->pb6->setVisible(false);
    ui->pb7->setVisible(false);
    ui->pb8->setVisible(false);
    ui->pb9->setVisible(false);
    ui->pb0->setVisible(false);
    ui->pbSpace_2->setVisible(false);
    ui->pbDash->setVisible(false);

    ui->pbLetter->setVisible(false);
    ui->pbBack_2->setVisible(false);
    ui->pbEnter_2->setVisible(false);
}

void QwertyKb::backSpace()
{

}

void QwertyKb::closeQwerty()
{
  //  this->findChild()->page()->evaluateJavaScript("add_message(); null");
}


void QwertyKb::showName()
{
    QMessageBox msgBox;
    msgBox.setText("testing");
    msgBox.exec();
}
