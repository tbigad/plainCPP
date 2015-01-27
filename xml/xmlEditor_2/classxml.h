#ifndef CLASSXML_H
#define CLASSXML_H

#include <QtXml>
#include <QString>


class classXml
{
public:
    classXml();
    bool setFile(const QString &filePath);
    int headerItems(QDomDocument doc);
private:

    QDomDocument _domDoc;
    QDomNode _domNode;
    QDomElement _domElement;
    QFile _xmlFile;
};

#endif // CLASSXML_H
