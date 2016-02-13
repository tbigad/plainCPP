#include "market.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <QDebug>
#include <chrono>
#include <thread>
/*Класс для представления списка товаров. Товар характеризуется уникальным названием,
  количеством единиц, ценой. Реализовать методы для добавления и редактирования товаров,
  поиска товаров, «покупки» товара.*/
Market::Market()
{

}

Market::~Market()
{
    _itemList.clear();
}

void Market::addItem(string title, double cost , int quantity)
{
    srand(time(NULL));
    int id = rand();
    shared_ptr<MarketItem> _itemSptr = make_shared<MarketItem>(id);
    _itemSptr->setCost(cost);
    _itemSptr->setQuantity(quantity);
    _itemSptr->setTitle(title);

    _itemList.push_back(_itemSptr);

    this_thread::sleep_for(chrono::milliseconds(1000));
    qDebug()<< _itemSptr->getCost()<< _itemSptr->getID() << _itemSptr->getQuantity() << _itemSptr->getTitle().c_str();
}

void Market::buyItem(shared_ptr<MarketItem> item)
{
    if(!item->buy()){
        _itemList.remove(item);
    }
}

int Market::indexByID(int id)
{
    for(list<shared_ptr<MarketItem>>::iterator it = _itemList.begin(); it!=_itemList.end(); ++it){
        MarketItem& _itemSptr = *(*it);
        if (_itemSptr.getID()==id)
            return static_cast<int>(distance(_itemList.begin(), it));
    }
    return -1;
}

void Market::editItem(int id, string title, double cost, int quantity)
{
    MarketItem& item = itemFromID(id);
    item.setCost(cost);
    item.setQuantity(quantity);
    item.setTitle(title);
}

const list<shared_ptr<MarketItem> > Market::getList()
{
    return _itemList;
}

MarketItem& Market::itemFromID(int id)
{
    for(list<shared_ptr<MarketItem>>::iterator it = _itemList.begin(); it!=_itemList.end(); ++it){
        MarketItem& _itemSptr = *(*it);
        if (_itemSptr.getID()==id)
            return _itemSptr;
    }
}


