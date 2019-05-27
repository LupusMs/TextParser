#ifndef PARSER_H
#define PARSER_H
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

class Parser
{
public:
    Parser();
    QString parseFile(QString path);
};

#endif // PARSER_H
