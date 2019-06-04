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

void MainWindow::on_pushButton_clicked()
{
    Parser* myParser = new Parser();
    myParser->parseFile(ui->lineEdit->text());
    qDebug() << myParser->getText();
    myParser->calculateStatistics(ui->lineEdit->text());
    ui->label_output->setText(myParser->getResult());
    qDebug() << myParser->getResult();

    delete myParser;
}
