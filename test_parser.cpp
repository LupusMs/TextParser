#include "test_parser.h"
#include "parser.h"
#include <QTest>
#include<QDebug>


Test_Parser::Test_Parser(QObject* parent) :
    QObject(parent)
{

}

/**
 *Testing if the program can read a txt file
 * @brief Test_Parser::testParsing
 */
void Test_Parser::testParsing()
{
    Parser* parser = new Parser();
    //PATH to a sample file here
    parser->parseFile(QDir().absoluteFilePath("C:/try.txt"));
    QVERIFY(parser->getText().length() > 0);
    delete(parser);
}

/**
 *Testing the final output
 * @brief Test_Parser::testResult
 */
void Test_Parser::testResult()
{
    Parser* parser = new Parser();
    parser->calculateStatistics("C:/try.txt");
    QVERIFY(parser->getResult() == QString("der : 10 <br></br><br></br>- : 8 <br></br><br></br>Tochter : 6 <br></br><br></br>ist : 4 <br></br><br></br>ins : 3 <br></br><br></br>aufeinander : 2 <br></br><br></br>nichts.\r\nIn : 1 <br></br><br></br>"));
    delete(parser);
}
