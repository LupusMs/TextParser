#include "db_entrydialog.h"
#include "ui_db_entrydialog.h"

DbEntryDialog::DbEntryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DbEntryDialog)
{
    ui->setupUi(this);
}

DbEntryDialog::~DbEntryDialog()
{
    delete ui;
}

void DbEntryDialog::setCaption(QString caption)
{
    ui->label->setText(caption);
}

/** Filling a table with Books, Min word length and Parsig time
 * @brief DbEntryDialog::setTableData
 * @param db
 */
void DbEntryDialog::setTableData(QSharedPointer<QList<QString>> data)
{
    QTableWidgetItem *newItem1 = new QTableWidgetItem(data->value(0));    
    QTableWidgetItem *newItem2 = new QTableWidgetItem(data->value(1));
    QTableWidgetItem *newItem3 = new QTableWidgetItem(data->value(2));
    ui->tableWidget->setItem(0, 0, newItem1);    
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->setItem(0, 1, newItem2);
    ui->tableWidget->setItem(0, 2, newItem3);
    ui->textBrowser->setText(data->value(3));
}
