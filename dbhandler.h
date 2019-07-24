#ifndef DBHANDLER_H
#define DBHANDLER_H
#include <QObject>
#include <QString>
#include <QVariant>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>



static const QString dbName = "myLog.db";

class DBHandler : public QObject
{    
    Q_OBJECT
    QSqlDatabase db;
    QSharedPointer<QList<QString>> indexList = QSharedPointer<QList<QString>>(new QList<QString>());
    QSharedPointer<QList<QString>> dataList = QSharedPointer<QList<QString>>(new QList<QString>());

public:
   explicit DBHandler(QObject *parent = nullptr);
    ~DBHandler();
   bool connect();
   bool writeData(QString& output, long long elapsed_seconds, QList<QString>* books, int minWordLength);
   QSharedPointer<QList<QString>> readDbIndex();
   QSharedPointer<QList<QString>> readDbData(QString date_time);
   bool deleteEntry(QString& entry);
};

#endif // DBHANDLER_H
