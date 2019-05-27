#include "parser.h"

Parser::Parser()
{

}

QString Parser::parseFile(QString path)
{
    QFile file (path);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    QString line;
    while(!in.atEnd()) {
        line = in.readLine();
        }

    file.close();
    return line;

}
