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
    ui->label_output->setText(ui->label_output->text() + " : success " + myParser->parseFile(ui->lineEdit->text()));
    delete myParser;
}
