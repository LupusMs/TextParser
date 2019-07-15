#ifndef DBINDEXDIALOG_H
#define DBINDEXDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QScrollArea>


namespace Ui {
    class Form;
}

class DbIndexDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DbIndexDialog(QWidget *parent = nullptr);
    ~DbIndexDialog();

signals:

public slots:

private:
    Ui::Form *ui;
};

#endif // DBINDEXDIALOG_H
