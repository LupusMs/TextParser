#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_databaseoutput.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    myParser = new Parser(this);
    db = new DBHandler(this);

    //Creating new DB or connecting to excisting DB here
    if (db->connect() == false){
        QMessageBox msgBox;
        msgBox.setText("Cannot connect or create Database");
        msgBox.exec();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    dialog->close();
    delete dialog;
}

// OK button clicked, starting parsing and analysing
void MainWindow::on_pushButton_clicked()
{
    //Vars to calculate elapsed time
    long long start = QDateTime::currentMSecsSinceEpoch();

    QString path = ui->lineEdit->text();
    int length =  ui->spinBox->value();

    //To prevent parsing the same file twice
    if(path != lastAddedFile){
       myParser->parseFile(path);
       myParser->calculateStatistics(length);
       ui->statusBar->showMessage("Parsing...", 300);
    }

    myParser->filterHash(length);
    lastAddedFile = path;
    ui->textBrowser->setText(myParser->getResult());
    QString includedFiles;
    for(QString file : *myParser->getFiles()){
        includedFiles.append(file + "<br></br>");
    }

    ui->textBrowser_includedFiles->setText(includedFiles);

    long long end = QDateTime::currentMSecsSinceEpoch();
    long long elapsed_seconds = end-start;
    myParser->setElapsedTime(elapsed_seconds);
    ui->statusBar->showMessage("Elapsed time: " + QString::number(elapsed_seconds) + " ms", 10000);
}

// Selecting file
void MainWindow::on_pushButton_choose_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Select file"), "/", tr("Text files(*.txt)"));
    ui->lineEdit->setText(fileName);
}

//Recreate Parser object
void MainWindow::on_actionRemove_all_files_triggered()
{
   ui->textBrowser->clear();  
   ui->textBrowser_includedFiles->clear();
   lastAddedFile = "null";
   delete myParser;
   myParser = new Parser(this);
}

//Saving to a DataBase
void MainWindow::on_actionSave_triggered()
{
    db->writeData(myParser->output, myParser->getElapsedTime(), myParser->getFiles(), ui->spinBox->value());
}

//TODO Implement DB history output
void MainWindow::on_actionView_History_triggered()
{
    dialog = new DbIndexDialog(this);
    dialog->createList(*db);
    dialog->show();
}
