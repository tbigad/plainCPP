#ifndef MARKETITEM_H
#define MARKETITEM_H
#include <string>
class MarketItem{
    int _ID;
    int _quantity;
    std::string _title;
    double _cost;
public:
    explicit MarketItem(int id){_ID = id;}
    ~MarketItem(){}
    void setTitle(std::string title){_title = title;}
    void setCost(double cost){_cost = cost;}
    void setQuantity(int quantity){_quantity = quantity;}
    bool buy(){
        _quantity--;
        if(_quantity==0)
            return false;
        else
            return true;
    }
    int getID() const {return _ID;}
    std::string getTitle() const {return _title;}
    double getCost() const {return _cost;}
};
#endif // MARKETITEM_H
