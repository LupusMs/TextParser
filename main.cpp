#include "mainwindow.h"
#include <QApplication>
#include <QTest>
#include "test_parser.h"
using namespace std;

// Uncomment for normal run

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


// TEST
/*
int main(int argc, char *argv[])
{
    freopen("testing_log.log", "w", stdout);
    QApplication a(argc, argv);

    QTest::qExec(new Test_Parser, argc, argv);

    return 0;
}*/
