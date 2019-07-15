#include "dbindexdialog.h"
#include "ui_databaseoutput.h"

DbIndexDialog::DbIndexDialog(QWidget *parent) : QDialog(parent), ui(new Ui::Form)
{
    ui->setupUi(this);
}

DbIndexDialog::~DbIndexDialog()
{
    delete ui;
}


void DbIndexDialog::createList(DBHandler &db)
{
    QSharedPointer<QList<QString>> list = db.readDbIndex();

    for(int i = 0; i < list->size(); ++i){
        ui->listWidget->addItem(list->value(i));
    }

    ui->listWidget->setSpacing(5);
}


