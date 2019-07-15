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
