#include "parser.h"

Parser::Parser()
{

}

/**
 * @brief Parser::parseFile Parsing txt file
 * @param path
 * @return
 */
void Parser::parseFile(QString path)
{
    QFile file (path);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    QString output = in.readAll();
    file.close();

    //Update object field
    text = output;
}

/**
 * @brief Parser::calculateStatistics
 * Calculates words' occurences in a text
 * @param path
 */
void Parser::calculateStatistics(QString path)
{
    parseFile(path);
    QStringList words = text.split(" ");


    //Adding words to the hash map and calculating occurences
    for(const auto& i : words ){
        if(!hash.contains(i)){
            //adding new word
           hash.insert(i, 1);
        }
        else {
            //increasing the count
            hash.insert(i, hash.value(i)+ 1);
        }
    }
}
//TODO Implement sorting
QString Parser::getResult()
{
    QString res;
    QHashIterator<QString, int> i(hash);    
    QMap<int, QString> sortedRes;

    while (i.hasNext()) {
        i.next();
        sortedRes.insert(i.value(), i.key());        
    }
    QMapIterator<int, QString> mapIt(sortedRes);
    mapIt.toBack();
    while (mapIt.hasPrevious()) {
        mapIt.previous();
        res +=  QString(mapIt.value() + " : %1 <br></br><br></br>").arg(mapIt.key());
    }


    return res;
}
