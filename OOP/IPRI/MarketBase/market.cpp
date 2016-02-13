#include "market.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iterator>

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

const list<shared_ptr<MarketItem> > Market::getList()
{
    return _itemList;
}


