#include "classxmleditor.h"

classXmlEditor::classXmlEditor()
{
}

bool classXmlEditor::setFile(const QString &filePath)
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

int classXmlEditor::headerItems(QDomDocument doc)
{
    _domDoc.no
}

