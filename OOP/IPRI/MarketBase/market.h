#ifndef MARKET_H
#define MARKET_H
#include "marketitem.h"
#include <list>
#include <memory>

using namespace std;
class Market
{
public:
    Market();
    ~Market();
    void addItem(string title, double cost, int quantity);
    void buyItem(shared_ptr<MarketItem> item);
    int indexByID(int id);
    void editItem(int id, string title, double cost , int quantity);
    list<shared_ptr<MarketItem> > const getList();
    MarketItem &itemFromID(int id);
private:
    list<shared_ptr<MarketItem> > _itemList;
};

#endif // MARKET_H
