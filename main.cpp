#include "mainwindow.h"
#include <QApplication>
#include <QTest>
#include "test_parser.h"
#include "test_database.h"
//#define TEST
using namespace std;

#ifdef TEST
//QTEST_MAIN(Test_Parser);
QTEST_MAIN(Test_Database);

#else
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

#endif



