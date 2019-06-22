#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myParser = new Parser();
}

MainWindow::~MainWindow()
{
    delete myParser;
    delete ui;
}

// OK button clicked, starting parsing and analysing
void MainWindow::on_pushButton_clicked()
{
    QString path = ui->lineEdit->text();
    int length =  ui->spinBox->value();

    //To prevent parsing the same file twice
    if(path != lastAddedFile){
       myParser->parseFile(path);
       myParser->calculateStatistics(length);
    }
    else {
       myParser->filterHash(length);
    }
    lastAddedFile = path;
    ui->textBrowser->setText(myParser->getResult());
    QString includedFiles;
    for(QString file : *myParser->getFiles()){
        includedFiles.append(file + "<br></br>");
    }

    ui->textBrowser_includedFiles->setText(includedFiles);

}

// Selecting file
void MainWindow::on_pushButton_choose_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Select file"), "/", tr("Text files (*.txt);"));
    ui->lineEdit->setText(fileName);
}

//Recreate Parser object
void MainWindow::on_actionRemove_all_files_triggered()
{
   ui->textBrowser->clear();  
   ui->textBrowser_includedFiles->clear();
   delete(myParser);
   myParser = new Parser();
}

void MainWindow::on_pushButton_2_clicked()
{
    QList<QString>* files = myParser->getFiles();
    files->removeAt(1);
}
