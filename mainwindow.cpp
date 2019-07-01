#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myParser = new Parser();
    db = new DBHandler();

    //Creating new DB or connecting to excisting DB here
    if (db->connect() == false){
        QMessageBox msgBox;
        msgBox.setText("Cannot connect or create Database");
        msgBox.exec();
    }
}

MainWindow::~MainWindow()
{
    delete myParser;
    delete ui;
    delete db;
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
    //Following carshing on Linux. Temporaly fix
    #ifdef Q_OS_WIN
    else {
      myParser->filterHash(length);
     }
    #endif
    lastAddedFile = path;
    ui->textBrowser->setText(myParser->getResult());
    QString includedFiles;
    for(QString file : *myParser->getFiles()){
        includedFiles.append(file + "<br></br>");
    }

    ui->textBrowser_includedFiles->setText(includedFiles);

    long long end = QDateTime::currentMSecsSinceEpoch();
    long long elapsed_seconds = end-start;
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
   delete(myParser);
   myParser = new Parser();
}

