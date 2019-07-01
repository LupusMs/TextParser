#include "dbhandler.h"

DBHandler::DBHandler()
{    

}

bool DBHandler::connect()
{
    //Using SQLite db driver
   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName(dbName);

   if(db.open()){
       QSqlQuery query;
       query.exec("CREATE TABLE IF NOT EXISTS my_table(t_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "date_time TEXT, output TEXT)");
       query.exec("CREATE TABLE IF NOT EXISTS book(name TEXT, min_word_length INTEGER, parsing_time INTEGER, PRIMARY KEY(name, min_word_length))");
       query.exec("CREATE TABLE IF NOT EXISTS contains_info(t_id INTEGER, name TEXT, min_word_length INTEGER, PRIMARY KEY(t_id, name, min_word_length),"
                  "FOREIGN KEY(name, min_word_length) REFERENCES book(name, min_word_length), FOREIGN KEY(t_id) REFERENCES my_table(t_id))");
       return true;
   }
   else{
       return false;
   }

}

//writing to three tables: table, book, contains
bool DBHandler::writeData()
{

}

