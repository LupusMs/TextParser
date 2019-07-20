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
       return query.exec("CREATE TABLE IF NOT EXISTS my_table(t_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "date_time TEXT, output TEXT, books TEXT, parsing_time INTEGER, min_word_length INTEGER)");
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

/**
 * @brief DBHandler::readDbIndex
 * @return returning date_time of all available entries
 */
QSharedPointer<QList<QString>> DBHandler::readDbIndex()
{
    QSqlQuery query;

    query.exec("SELECT date_time FROM my_table");
    while (query.next()) {
       indexList->append(query.value(0).toString());
    }

    return indexList;

}

QSharedPointer<QList<QString> > DBHandler::readDbData(QString date_time)
{
    QSqlQuery query;
    query.prepare("SELECT books, min_word_length, parsing_time, output FROM my_table WHERE date_time = ?");
    query.addBindValue(date_time);
    query.exec();
    query.next();

    //Deleting data from previous requests
    if(dataList->size() > 0)
    {
        dataList->clear();
    }
    dataList->append(query.value(0).toString());
    dataList->append(query.value(1).toString());
    dataList->append(query.value(2).toString());
    dataList->append(query.value(3).toString());

    return dataList;

}

