#ifndef TEST_PARSER_H
#define TEST_PARSER_H

#include <QObject>
#include <parser.h>
#include <QtTest/QtTest>

class Test_Parser : public QObject
{
    Q_OBJECT
public:
    explicit Test_Parser(QObject* parent = 0);

private slots:
    void testParsing();
    void testResult();
    void testWordLengthFiltering();
};

#endif // TEST_PARSER_H
