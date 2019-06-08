#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
}

MainWindow::~MainWindow()
{
    delete ui;
}

// OK button clicked, starting parsing and analysing
void MainWindow::on_pushButton_clicked()
{
    Parser* myParser = new Parser();   
    myParser->parseFile(ui->lineEdit->text());    
    myParser->calculateStatistics(ui->lineEdit->text());
    ui->textBrowser->setText(myParser->getResult());



    delete myParser;
}

// Selecting file
void MainWindow::on_pushButton_choose_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Select file"), "/", tr("Text files (*.txt);"));
    ui->lineEdit->setText(fileName);
}
