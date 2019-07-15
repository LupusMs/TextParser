#ifndef DBINDEXDIALOG_H
#define DBINDEXDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QScrollArea>
#include <QSharedPointer>
#include <dbhandler.h>

namespace Ui {
    class Form;
}

class DbIndexDialog : public QDialog
{
    Q_OBJECT
public:

     DbIndexDialog(QWidget *parent = nullptr);
    ~DbIndexDialog();
     void createList(DBHandler &db);

signals:

public slots:

private:
    Ui::Form *ui;
};

#endif // DBINDEXDIALOG_H
