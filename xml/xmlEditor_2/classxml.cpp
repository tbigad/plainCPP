#include "classxml.h"

classXml::classXml()
{
}

bool classXml::setFile(const QString &filePath)
{
    _xmlFile.setFileName(filePath);
    if(!_xmlFile.open(QFile::ReadOnly|QFile::Text))
    {
        return false;
    }
    if (!_domDoc.setContent(&_xmlFile))
    {
        return false;
    }
    return true;

}

int classXml::headerItems(QDomDocument doc)
{
    //_domDoc.no
}

