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
/**
 *Shows list of db entries - date_time when entry is created
 */
namespace Ui {
    class Form;
}

class DbIndexDialog : public QDialog
{
    Q_OBJECT
    DbEntryDialog *entryDialog;
public:

     DbIndexDialog(QWidget *parent = nullptr);
    ~DbIndexDialog();
     void createList(DBHandler &db);

signals:

public slots:

private slots:
     void on_closeButton_clicked();
     void on_showButton_clicked();

private:
    Ui::Form *ui;
};

#endif // DBINDEXDIALOG_H
