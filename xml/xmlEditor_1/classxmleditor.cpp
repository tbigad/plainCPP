#include "classxmleditor.h"

classXmlEditor::classXmlEditor()
{
}

bool classXmlEditor::readFile(const QString &filePath)
{
    _xmlFile = filePath;
    if(!_xmlFile.open(QFile::ReadOnly|QFile::Text))
    {
        return false
    }

}
