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
    myParser->parseFile(path);
    myParser->calculateStatistics(path, length);
    ui->textBrowser->setText(myParser->getResult());    
}

// Selecting file
void MainWindow::on_pushButton_choose_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Select file"), "/", tr("Text files (*.txt);"));
    ui->lineEdit->setText(fileName);
}
