#ifndef CLASSXMLEDITOR_H
#define CLASSXMLEDITOR_H

#include <QtXml>
#include <QString>


class classXmlEditor
{
public:
    classXmlEditor();
    bool setFile(const QString &filePath);
    int headerItems(QDomDocument doc);
private:

    QDomDocument _domDoc;
    QDomNode _domNode;
    QDomElement _domElement;
    QFile _xmlFile;
};

#endif // CLASSXMLEDITOR_H
