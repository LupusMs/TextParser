#ifndef DBHANDLER_H
#define DBHANDLER_H
#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>

static const QString dbName = "myLog.db";

class DBHandler
{

    QSqlDatabase db;

public:
   DBHandler();
   bool connect();
   bool writeData(QString& output, long long elapsed_seconds, QList<QString>* books, int minWordLength);
   void readData();
};

#endif // DBHANDLER_H
