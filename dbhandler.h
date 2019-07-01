#ifndef DBHANDLER_H
#define DBHANDLER_H
#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>

static const QString dbName = "myLog.db";

class DBHandler
{    

public:
   DBHandler();
   bool connect();
   bool writeData();
   void readData();
};

#endif // DBHANDLER_H
