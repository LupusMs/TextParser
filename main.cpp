#include "mainwindow.h"
#include <QApplication>
#include <QTest>
#include "test_parser.h"
#define TEST
using namespace std;

#ifdef TEST
int main(int argc, char *argv[])
{
    freopen("testing_log.log", "w", stdout);
    QApplication a(argc, argv);

    QTest::qExec(new Test_Parser, argc, argv);

    return 0;
}

#else
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

#endif



