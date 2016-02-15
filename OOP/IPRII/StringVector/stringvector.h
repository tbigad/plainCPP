#ifndef STRINGVECTOR_H
#define STRINGVECTOR_H
#include <string>

struct Data{
  Data* nextItem;
  std::string content;
};
class StringVector
{
public:
    StringVector(){}
    StringVector(const std::string* str);
    StringVector(const char* c);
    ~StringVector(){}
    void pushBack(const std::string* str);
    void pushBack(const char* c);
    const char* popFront_C_str();
    std::string popFront();
    inline StringVector &operator << (const char* c)
    {pushBack(c); return *this;}
    const char* operator[](const int i);
    int size();
private:
    Data*  lastData();
    Data *  nextData(Data* next);
    size_t m_size;
    Data* first = NULL;
};

#endif // STRINGVECTOR_H
