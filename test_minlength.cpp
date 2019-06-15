#include "test_minlength.h"



int getMinLenght(QHash<QString, int> hash)
{
    QHash<QString, int>::iterator i;
    int minLength = 0;
    for (i = hash.begin(); i != hash.end(); ++i){
        if(i.key().length() > minLength)
            minLength = i.key().length();
    }
    return minLength;
}
