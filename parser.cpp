#include "parser.h"
Parser::Parser()
{
    files = new QList<QString>;
    hash = new QHash<QString, int>;
}

Parser::~Parser()
{
    delete files;
    delete hash;
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
    else {
    files->append(path);
    QTextStream in(&file);
    QString output = in.readAll();
    file.close();

    //Update object field
    text = output;
    }
}

/**
 * @brief Parser::calculateStatistics
 * Calculates words' occurences in a text
 * @param path, wordLength
 */
void Parser::calculateStatistics(int wordLength)
{

    QStringList words = text.split(QRegExp("\\s+"), QString::SkipEmptyParts);

    // Clean hashMap from words < wordLength
    filterHash(wordLength);

    //Adding words to the hash map and calculating occurences
    //TODO use more efficient hashing?
    for(const auto& i : words ){

        //Ignoring words which length is less
        if (i.length() < wordLength){
            continue;
        }

        if(!hash->contains(i)){
            //adding new word
           hash->insert(i, 1);
        }
        else {
            //increasing the count
            hash->insert(i, hash->value(i)+ 1);
        }
    }
}

/** Returning sorted occurances result WORD : OCCURENCE
 * @brief Parser::getResult
 * @return
 */
QString Parser::getResult()
{
    QString res;
    QHashIterator<QString, int> i(*hash);
    QList<QPair<int,QString> > sortedRes;

    //Filling QList
    while (i.hasNext()) {
        i.next();       
        sortedRes.append(qMakePair(i.value(), i.key()));
    }

    //Sorting and reversing
    std::sort(sortedRes.begin(), sortedRes.end());
    std::reverse(sortedRes.begin(), sortedRes.end());

    //Forming an output string
    for (int i=0;i<sortedRes.count();i++){
        QPair<int, QString> pair = sortedRes.at(i);
        res +=  QString(pair.second + " : %1 <br></br><br></br>").arg(pair.first);
    }
    output = res;
    return res;
}

QString Parser::getText()
{
    return text;
}

QHash<QString, int>* Parser::getHashMap()
{
    return hash;
}

/**
 * @brief Parser::filterHash
 * Removes from hash words that shorter than wordLength
 * @param wordLength
 */
void Parser::filterHash(int wordLength)
{
    QHash<QString, int>::iterator i;
    QList<QString> toBeDeleted;
    for (i = hash->begin(); i != hash->end(); ++i){
        if(i.key().length() < wordLength){
            toBeDeleted.append(i.key());
        }
    }

    foreach(QString key, toBeDeleted){
        hash->remove(key);
    }
}

QList<QString>* Parser::getFiles()
{
    return files;
}

long long Parser::getElapsedTime()
{
    return elapsedTime;
}

void Parser::setElapsedTime(long long time)
{
    elapsedTime = time;
}

