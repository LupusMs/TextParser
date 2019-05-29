#include "test_parser.h"
#include "parser.h"
#include <QTest>

Test_Parser::Test_Parser(QObject* parent) :
    QObject(parent)
{

}

void Test_Parser::testParsing()
{
    Parser parser;
    parser.parseFile("C:/try.txt");
    QVERIFY(parser.getText().length() > 0);
}
