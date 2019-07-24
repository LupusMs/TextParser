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
    this->db = &db;
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
    if(checkIfSelected() == true){
        entryDialog = new DbEntryDialog(this);
        entryDialog->setModal(true);
        QString caption = ui->listWidget->selectedItems().constFirst()->text();
        entryDialog->setCaption(caption);
        entryDialog->setTableData(db->readDbData(caption));
        entryDialog->show();
    }    
}

//TODO Implement slots for buttons
//TODO delete item from list
//Deleting selected entry from a database
void DbIndexDialog::on_deleteButton_clicked()
{
    //if user selected an entry
    if(checkIfSelected() == true){
        QMessageBox msgBox;
        QString* msg = new QString("Delete entry ");
        msg->append(ui->listWidget->selectedItems().value(0)->text());
        msgBox.setText(*msg);
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);

        //Deleting selected entry & updating list of current available entries
        if(msgBox.exec() == QMessageBox::Ok)
        {
            QString* entry = new QString(ui->listWidget->selectedItems().value(0)->text());
            db->deleteEntry(*entry);
            for(int i = 0; i < ui->listWidget->count(); ++i){
                if (ui->listWidget->item(i)->text() == entry){                    
                    qDeleteAll(ui->listWidget->selectedItems());
                    qDebug()<< "removing entry from listWidget";
                }
            }            
        }
    }


}

/** Checking if anything is selected, otherwise showing an alert dialog
 * @brief DbIndexDialog::checkIfSelected
 * @return true if selected, false if not selected
 */
bool DbIndexDialog::checkIfSelected()
{
    if(ui->listWidget->selectedItems().isEmpty()){
        QMessageBox msgBox;
        msgBox.setText("Please, select an entry from the list");
        msgBox.exec();
        return false;
    }
    return true;
}
