#ifndef PARSER_H
#define PARSER_H
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <sstream>
#include <string>

class Parser
{
    QString text;
    QHash<QString, int> hash;
public:
    Parser();
    void parseFile(QString path);
    void calculateStatistics(QString path);
    QString getResult();
};

#endif // PARSER_H
