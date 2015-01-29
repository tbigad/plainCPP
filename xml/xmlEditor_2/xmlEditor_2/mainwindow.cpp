#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readXml(const QString &xmlContent)
{
  QDomDocument doc;
  QDomElement root;
  QDomNode dNode;
  QStandardItem *item;

  doc.setContent(xmlContent);
  root = doc.documentElement();

  dNode = root.firstChild();
  item = new QStandardItem(root.tagName());
  printNodes(dNode, item);
  ui->treeView->setModel(item->model());
}

void MainWindow::printNodes(QDomNode dNode, QStandardItem *item)
{
  do
  {
    int totalOfChilds = dNode.childNodes().size();

    if (dNode.nodeType() != QDomNode::CommentNode)
    {
      if (totalOfChilds == 0)
      {
        if (dNode.nodeType() == QDomNode::TextNode)
          item->setValue(dNode.nodeValue());
        else
        {
          QStandardItem *subItem = new QStandardItem(dNode.nodeName());

          for (int i = 0; i < dNode.attributes().size(); i++)
          {
            subItem->a (dNode.attributes().item(i).nodeName(),
                                  dNode.attributes().item(i).nodeValue());
          }
          item->appendRow(subItem);
        }
      }
      else
      {
        QStandardItem *item2 = new QStandardItem(dNode.nodeName());

        for (int i = 0; i < totalOfChilds; i++)
          if (dNode.childNodes().size() > 0 && i == 0)
            printNodes(dNode.childNodes().at(i), item2);

        item->appendRow(item2);
      }
    }
    dNode = dNode.nextSibling();
  }
  while (!dNode.isNull());
}
