#include "db_indexdialog.h"
#include "ui_databaseoutput.h"

DbIndexDialog::DbIndexDialog(QWidget *parent) : QDialog(parent), ui(new Ui::Form)
{
    ui->setupUi(this);
}

DbIndexDialog::~DbIndexDialog()
{
    delete ui;    
    delete entryDialog;
}


void DbIndexDialog::createList(DBHandler &db)
{
    QSharedPointer<QList<QString>> list = db.readDbIndex();

    for(int i = 0; i < list->size(); ++i){
        ui->listWidget->addItem(list->value(i));
    }

    ui->listWidget->setSpacing(5);
    list->clear();
}



void DbIndexDialog::on_closeButton_clicked()
{    
    close();
}

/**
 * creates new dialog with all data for the selected entry
 * @brief DbIndexDialog::on_showButton_clicked
 */
void DbIndexDialog::on_showButton_clicked()
{
    //if user selected an entry
    if(!ui->listWidget->selectedItems().isEmpty()){
        entryDialog = new DbEntryDialog(this);
        entryDialog->setModal(true);
        QString caption = ui->listWidget->selectedItems().constFirst()->text();
        qDebug()<<caption;
        entryDialog->setCaption(caption);
        entryDialog->show();
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Please, select an entry from the list");
        msgBox.exec();
    }
}
