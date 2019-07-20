#include "test_parser.h"
#include "parser.h"
#include "test_minlength.h"
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
    qDebug()<<"testParsing";
    Parser* parser = new Parser();
    //PATH to a sample file here
    parser->parseFile(QDir().absoluteFilePath("/home/lupus/Desktop/text.txt"));
    QVERIFY(parser->getText().length() > 0);
    delete parser;
}

/**
 *Testing the final output
 * @brief Test_Parser::testResult
 */
void Test_Parser::testResult()
{
    Parser* parser = new Parser();
    parser->parseFile(QDir().absoluteFilePath("/home/lupus/Desktop/text.txt"));
    parser->calculateStatistics(1);
    QVERIFY(parser->getResult() == QString("der : 10 <br></br><br></br>- : 8 <br></br><br></br>Tochter : 6 <br></br><br></br>ist : 4 <br></br><br></br>ins : 3 <br></br><br></br>aufeinander : 2 <br></br><br></br>nichts.\r\nIn : 1 <br></br><br></br>"));
    delete parser;
}

/**
 * @brief Test_Parser::testWordLengthFiltering
 */
void Test_Parser::testWordLengthFiltering()
{
    Parser* parser = new Parser();
    parser->parseFile(QDir().absoluteFilePath("/home/lupus/Desktop/text.txt"));
    parser->calculateStatistics(3);
    QHash<QString, int>* hash = parser->getHashMap();
    QVERIFY(getMinLenght(*hash) >= 3);
    delete parser;

    parser = new Parser();
    parser->parseFile(QDir().absoluteFilePath("/home/lupus/Desktop/text.txt"));
    parser->calculateStatistics(5);
    hash = parser->getHashMap();
    QVERIFY(getMinLenght(*hash) >= 5);
    delete parser;

    parser = new Parser();
    parser->parseFile(QDir().absoluteFilePath("/home/lupus/Desktop/text.txt"));
    parser->calculateStatistics(6);
    hash = parser->getHashMap();
    QVERIFY(getMinLenght(*hash) >= 6);
    delete parser;

}




