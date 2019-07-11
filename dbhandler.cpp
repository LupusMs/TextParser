#include "dbhandler.h"

DBHandler::DBHandler()
{    

}

bool DBHandler::connect()
{
    //Using SQLite db driver
   db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName(dbName);

   if(db.open()){
       QSqlQuery query;
       query.exec("CREATE TABLE IF NOT EXISTS my_table(t_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "date_time TEXT, output TEXT, books TEXT, parsing_time INTEGER, min_word_length INTEGER)");
       return true;
   }
   else{
       return false;
   }

}

//writing to three tables: table, book, contains
bool DBHandler::writeData(QString& output, long long elapsed_seconds, QList<QString>* books, int minWordLength)
{
    QMessageBox msgBox;
    //Checking if output is not empty
    if(output.isEmpty()){
        msgBox.setText("Cannot save empty workspace");
        msgBox.exec();
        return false;
    }


    //Transferring books to QString
    QString booksString;
    foreach(QString book,*books){
        booksString.append(book).append(",");
    }
    qDebug()<<booksString;


    QSqlQuery query;
    query.prepare("INSERT INTO my_table (date_time, output, books, parsing_time, min_word_length) VALUES (datetime('now'), ?, ?, ?, ?)");
    query.addBindValue(output);
    query.addBindValue(booksString);
    query.addBindValue((int) elapsed_seconds);
    query.addBindValue(minWordLength);
    if (query.exec()){
        msgBox.setText("Saved to Database");
        msgBox.exec();
         return true;
    }
    else{
        msgBox.setText("Cannot write to Database");
        msgBox.exec();
        return false;
    }




}

