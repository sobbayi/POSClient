#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "postableview.h"
#include "admindlg.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // setFixedSize(600, 800);
   // setWindowFlags(Qt::FramelessWindowHint);
    isadminable = false;

    ui->activateItemsActBut->setVisible(false);
    ui->cancelActivateActBut->setVisible(false);
    ui->cancelOutgoingActBut->setVisible(false);
    ui->cancelIncomingActBut->setVisible(false);
    ui->finalSaleCancelActBut->setVisible(false);
    ui->forensicsDoneActBut->setVisible(false);
    ui->registerSaleActBut->setVisible(false);
    ui->reportCounterfeitActBut->setVisible(false);
    ui->returnsActBut->setVisible(false);
    ui->returnsCancelActBut->setVisible(false);
    ui->returnedItemsFrame->setVisible(false);
    ui->forensicsFrame1->setVisible(false);
    ui->forensicsFrame2->setVisible(false);
    ui->returnedItemsOKBut->setVisible(false);


    //make and move the keyboard to the base of the page
    //and keep it there for the lifespan of the

    model = new POSMainTableModel(ui->tableView);

    ui->tableView->setModel(model);
    model->insertRows(0, 20);
    ui->tableView->setItemDelegate(new MainTableDelegate(ui->tableView));
   // ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->horizontalHeader()->stretchSectionCount();

    kb = new QwertyKb();
    kb->move(0, 515);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete kb;
}

void MainWindow::on_transferOwnershipBut_pressed()
{
    ui->activateItemsActBut->setVisible(false);
    ui->cancelActivateActBut->setVisible(false);
    ui->cancelOutgoingActBut->setVisible(false);
    ui->cancelIncomingActBut->setVisible(false);
    ui->finalSaleCancelActBut->setVisible(false);
    ui->forensicsDoneActBut->setVisible(false);
    ui->registerSaleActBut->setVisible(false);
    ui->reportCounterfeitActBut->setVisible(false);
    ui->returnsActBut->setVisible(false);
    ui->returnsCancelActBut->setVisible(false);
    ui->transferOwnershipActBut->setVisible(true);
    ui->cancelOwnershipTransferActBut->setVisible(true);
    ui->recipientCombo->setVisible(true);
    ui->returnedItemsFrame->setVisible(false);
    ui->forensicsFrame1->setVisible(false);
    ui->forensicsFrame2->setVisible(false);
    ui->returnedItemsOKBut->setVisible(false);
    ui->tableView->setGeometry(2, 40, 596, 371);
    ui->tableView->setVisible(true);
    ui->headerLabel->setText(tr("TRANSFER OWNERSHIP"));
}

void MainWindow::on_outgoingTransfersBut_pressed()
{
    ui->activateItemsActBut->setVisible(false);
    ui->cancelActivateActBut->setVisible(false);
    ui->cancelOutgoingActBut->setVisible(true);
    ui->cancelIncomingActBut->setVisible(false);
    ui->finalSaleCancelActBut->setVisible(false);
    ui->forensicsDoneActBut->setVisible(false);
    ui->registerSaleActBut->setVisible(false);
    ui->reportCounterfeitActBut->setVisible(false);
    ui->returnsActBut->setVisible(false);
    ui->returnsCancelActBut->setVisible(false);
    ui->transferOwnershipActBut->setVisible(false);
    ui->cancelOwnershipTransferActBut->setVisible(false);
    ui->recipientCombo->setVisible(false);
    ui->returnedItemsFrame->setVisible(false);
    ui->forensicsFrame1->setVisible(false);
    ui->forensicsFrame2->setVisible(false);
    ui->returnedItemsOKBut->setVisible(false);
    ui->tableView->setGeometry(2, 40, 596, 371);
    ui->tableView->setVisible(true);
    ui->headerLabel->setText(tr("OUTGOING TRANSFERS"));
}

void MainWindow::on_incomingTransfersBut_pressed()
{
    ui->activateItemsActBut->setVisible(false);
    ui->cancelActivateActBut->setVisible(false);
    ui->cancelOutgoingActBut->setVisible(false);
    ui->cancelIncomingActBut->setVisible(true);
    ui->finalSaleCancelActBut->setVisible(false);
    ui->forensicsDoneActBut->setVisible(false);
    ui->registerSaleActBut->setVisible(false);
    ui->reportCounterfeitActBut->setVisible(false);
    ui->returnsActBut->setVisible(false);
    ui->returnsCancelActBut->setVisible(false);
    ui->transferOwnershipActBut->setVisible(false);
    ui->cancelOwnershipTransferActBut->setVisible(false);
    ui->recipientCombo->setVisible(false);
    ui->returnedItemsFrame->setVisible(false);
    ui->forensicsFrame1->setVisible(false);
    ui->forensicsFrame2->setVisible(false);
    ui->returnedItemsOKBut->setVisible(false);
    ui->tableView->setGeometry(2, 40, 596, 371);
    ui->tableView->setVisible(true);
    ui->headerLabel->setText(tr("INCOMING TRANSFERS"));
}

void MainWindow::on_finalSaleBut_pressed()
{
    ui->activateItemsActBut->setVisible(false);
    ui->cancelActivateActBut->setVisible(false);
    ui->cancelOutgoingActBut->setVisible(false);
    ui->cancelIncomingActBut->setVisible(false);
    ui->finalSaleCancelActBut->setVisible(true);
    ui->forensicsDoneActBut->setVisible(false);
    ui->registerSaleActBut->setVisible(true);
    ui->reportCounterfeitActBut->setVisible(false);
    ui->returnsActBut->setVisible(false);
    ui->returnsCancelActBut->setVisible(false);
    ui->transferOwnershipActBut->setVisible(false);
    ui->cancelOwnershipTransferActBut->setVisible(false);
    ui->recipientCombo->setVisible(false);
    ui->returnedItemsFrame->setVisible(false);
    ui->forensicsFrame1->setVisible(false);
    ui->forensicsFrame2->setVisible(false);
    ui->returnedItemsOKBut->setVisible(false);
    ui->tableView->setGeometry(2, 40, 596, 371);
    ui->tableView->setVisible(true);
    ui->headerLabel->setText(tr("FINAL SALE"));
}

void MainWindow::on_returnedItemsBut_pressed()
{
    ui->activateItemsActBut->setVisible(false);
    ui->cancelActivateActBut->setVisible(false);
    ui->cancelOutgoingActBut->setVisible(false);
    ui->cancelIncomingActBut->setVisible(false);
    ui->finalSaleCancelActBut->setVisible(false);
    ui->forensicsDoneActBut->setVisible(false);
    ui->registerSaleActBut->setVisible(false);
    ui->reportCounterfeitActBut->setVisible(false);
    ui->returnsActBut->setVisible(true);
    ui->returnsCancelActBut->setVisible(true);
    ui->transferOwnershipActBut->setVisible(false);
    ui->cancelOwnershipTransferActBut->setVisible(false);
    ui->recipientCombo->setVisible(false);
    ui->returnedItemsFrame->setVisible(true);
    ui->returnedItemsOKBut->setVisible(true);
    ui->forensicsFrame1->setVisible(false);
    ui->forensicsFrame2->setVisible(false);
    ui->tableView->setGeometry(2, 130, 596, 281);
    ui->tableView->setVisible(true);
    ui->headerLabel->setText(tr("RETURNED ITEMS"));
}

void MainWindow::on_forensicsBut_pressed()
{
    ui->activateItemsActBut->setVisible(false);
    ui->cancelActivateActBut->setVisible(false);
    ui->cancelOutgoingActBut->setVisible(false);
    ui->cancelIncomingActBut->setVisible(false);
    ui->finalSaleCancelActBut->setVisible(false);
    ui->forensicsDoneActBut->setVisible(true);
    ui->registerSaleActBut->setVisible(false);
    ui->reportCounterfeitActBut->setVisible(true);
    ui->returnsActBut->setVisible(false);
    ui->returnsCancelActBut->setVisible(false);
    ui->transferOwnershipActBut->setVisible(false);
    ui->cancelOwnershipTransferActBut->setVisible(false);
    ui->recipientCombo->setVisible(false);
    ui->tableView->setVisible(false);
    ui->returnedItemsFrame->setVisible(false);
    ui->returnedItemsOKBut->setVisible(false);
    ui->forensicsFrame1->setVisible(true);
    ui->forensicsFrame2->setVisible(true);


    ui->headerLabel->setText(tr("FORENSICS"));
}

void MainWindow::on_activateItemsBut_pressed()
{
    ui->activateItemsActBut->setVisible(true);
    ui->cancelActivateActBut->setVisible(true);
    ui->cancelOutgoingActBut->setVisible(false);
    ui->cancelIncomingActBut->setVisible(false);
    ui->finalSaleCancelActBut->setVisible(false);
    ui->forensicsDoneActBut->setVisible(false);
    ui->registerSaleActBut->setVisible(false);
    ui->reportCounterfeitActBut->setVisible(false);
    ui->returnsActBut->setVisible(false);
    ui->returnsCancelActBut->setVisible(false);
    ui->transferOwnershipActBut->setVisible(false);
    ui->cancelOwnershipTransferActBut->setVisible(false);
    ui->recipientCombo->setVisible(false);
    ui->returnedItemsFrame->setVisible(false);
    ui->forensicsFrame1->setVisible(false);
    ui->forensicsFrame2->setVisible(false);
    ui->returnedItemsOKBut->setVisible(false);
    ui->tableView->setGeometry(2, 40, 596, 371);
    ui->tableView->setVisible(true);
    ui->headerLabel->setText(tr("ACTIVATE ITEMS"));
}

void MainWindow::on_adminBut_pressed()
{
    adminLogin = new AdminLoginDlg(this);
    adminLogin->exec();
    if(!isadminable){
        adminDlg *dlg = new adminDlg(this);
        dlg->exec();
    }

}
