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
    QHash<QString, int>* hash;
    QList<QString>* files;
    long long elapsedTime;

public:
    QString output;
    Parser();
    ~Parser();
    void parseFile(QString path);
    void calculateStatistics(int length);
    QString getResult();
    QString getText();
    QHash<QString, int>* getHashMap();
    void filterHash(int wordLength);
    QList<QString>* getFiles();
    long long getElapsedTime();
    void setElapsedTime(long long time);
};

#endif // PARSER_H
