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
    ~StringVector(){}
    void pushBack(const std::string* str);
    void pushFron(const std::string* str);
    void clear();
    std::string const popBack();
    std::string const popFront();
    std::string* const front();
    std::string* const back();
    size_t size(){return m_size;}
private:
    size_t m_size;
    Data* first = NULL;
};

#endif // STRINGVECTOR_H
