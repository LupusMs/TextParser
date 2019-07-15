#include "dbindexdialog.h"
#include "ui_databaseoutput.h"

DbIndexDialog::DbIndexDialog(QWidget *parent) : QDialog(parent), ui(new Ui::Form)
{
    ui->setupUi(this);


    for(int i = 0; i < 100; ++i){

        ui->listWidget->addItem("test");

    }





}

DbIndexDialog::~DbIndexDialog()
{
    delete ui;
}
