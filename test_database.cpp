#include "test_database.h"

Test_Database::Test_Database(QObject *parent) : QObject(parent)
{

}

/** Testing connect() function
 * @brief Test_Database::testConnection
 */
void Test_Database::testConnection()
{
   DBHandler* db = new DBHandler();
   QVERIFY(db->connect() == true);
   delete db;
}
