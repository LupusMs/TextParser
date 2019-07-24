/**
 *Shows index of all db entries available - displays "date_time" of an entry
 */
#ifndef DBINDEXDIALOG_H
#define DBINDEXDIALOG_H
#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QScrollArea>
#include <QSharedPointer>
#include <dbhandler.h>
#include "ui_databaseoutput.h"
#include "db_entrydialog.h"

namespace Ui {
    class Form;
}

class DbIndexDialog : public QDialog
{
    Q_OBJECT
    DbEntryDialog *entryDialog;
    DBHandler *db;
public:

     DbIndexDialog(QWidget *parent = nullptr);
    ~DbIndexDialog();
     void createList(DBHandler &db);

signals:

public slots:

private slots:
     void on_closeButton_clicked();
     //creates new dialog with all data for the selected entry
     void on_showButton_clicked();
     void on_deleteButton_clicked();

private:
    Ui::Form *ui;
    //Displaying alert dialog if nothing is selected
    bool checkIfSelected();
};

#endif // DBINDEXDIALOG_H
