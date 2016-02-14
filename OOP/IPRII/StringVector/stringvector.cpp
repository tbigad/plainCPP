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
