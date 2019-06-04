#ifndef PARSER_H
#define PARSER_H
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <sstream>
#include <string>
#include <QDebug>

class Parser
{
    QString text;
    QHash<QString, int> hash;
public:
    Parser();
    void parseFile(QString path);
    void calculateStatistics(QString path);
    QString getResult();
    QString getText();
};

#endif // PARSER_H
