#include <QCoreApplication>
#include "classxml.h"


#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    classXml xml;
    if(!xml.setFile("/home/user1/Documents/workspace/QTtrainingspace/xml/xmlEditor_2/xmlexamples/config.xml"))
    {
         std::cout<< "can't open file";
    }
   std::cout << "file is open";

    return 0;
}
