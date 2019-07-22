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
//Deleting selected entry from a database
void DbIndexDialog::on_deleteButton_clicked()
{
    //Notifying user if no entry is selected
    if(checkIfSelected() == true){
        QMessageBox msgBox;
        QString* msg = new QString("Delete entry ");
        msg->append(ui->listWidget->selectedItems().value(0)->text());
        msgBox.setText(*msg);
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
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
