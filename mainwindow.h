#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include <QScrollArea>
#include <QFileDialog>
#include <QSpinBox>
#include "parser.h"
#include "dbhandler.h"
#include <chrono>
#include <QTime>
#include "db_indexdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT;
    Parser* myParser;
    QString lastAddedFile;
    DBHandler* db;
    DbIndexDialog *dialog;


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_choose_clicked();

    void on_actionRemove_all_files_triggered();



    void on_actionSave_triggered();

    void on_actionView_History_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
