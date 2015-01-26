#ifndef CLASSXMLEDITOR_H
#define CLASSXMLEDITOR_H

#include <QtXml>
#include <QString>

const QString PATH = "./xmlexamples/config.xml";


class classXmlEditor
{
public:
    classXmlEditor();
    bool readFile(const QString &filePath);
private:
    QDomDocument _domDoc;
    QFile _xmlFile;
};

#endif // CLASSXMLEDITOR_H
