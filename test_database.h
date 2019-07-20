/*
  Testing member functions of class DbHandler
*/
#ifndef TEST_DATABASE_H
#define TEST_DATABASE_H

#include <QObject>
#include <QTest>
#include "dbhandler.h"

class Test_Database : public QObject
{
    Q_OBJECT
public:
    explicit Test_Database(QObject *parent = nullptr);

signals:

private slots:
   void testConnection();
};

#endif // TEST_DATABASE_H
