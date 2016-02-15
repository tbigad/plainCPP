#include "stringvector.h"



StringVector::StringVector(const std::string *str)
{
    Data* data = new Data;
    data->content=*str;
    data->nextItem=NULL;
    this->first = data;
}

StringVector::StringVector(const char *c)
{
    Data* data = new Data;
    data->content=c;
    data->nextItem=NULL;
    this->first = data;
}

void StringVector::pushBack(const std::string *str)
{
    Data* data = new Data;
    data->content=*str;
    data->nextItem = NULL;
    if(first!=NULL)
        lastData()->nextItem = data;
    else
        first = data;
}

void StringVector::pushBack(const char *c)
{
    Data* data = new Data;
    data->content=c;
    data->nextItem = NULL;
    if(first!=NULL)
        lastData()->nextItem = data;
    else
        first = data;
}

const char *StringVector::popFront_C_str()
{
    if(first==NULL){
        const char* c = NULL;
        return c;
    }
    std::string str = first->content;
    Data* oldFirst = first;
    first = first->nextItem;
    delete oldFirst;
    return str.c_str();
}

std::string StringVector::popFront()
{
    if(first==NULL){
        return std::string(NULL);
    }
    std::string str = first->content;
    Data* oldFirst = first;
    first = first->nextItem;
    delete oldFirst;
    return str;
}

const char* StringVector::operator[](const int value)
{
    Data* data = first;
    for(int i = 0; i<value; i++){
        data = nextData(data);
        if(data==NULL)
            return NULL;
    }
    return data->content.c_str();
}



int StringVector::size()
{
    int i = 1;
    Data* last = first;
    while (last->nextItem!=NULL) {
        last = nextData(last);
        i++;
    }
    return i;
}

Data *  StringVector::lastData()
{
    Data* last = first;
    while (last->nextItem!=NULL) {
        last = nextData(last);
    }
    return last;
}

Data * StringVector::nextData(Data *next)
{
    if(next->nextItem==NULL)
        return NULL;
    else
        return next->nextItem;
}
