#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Character; // forward-declaration

enum ItemType { // specify item type
    IT_ATTACK,
    IT_DEFENSE,
    IT_CONSUMABLE,
    IT_UNKNOWN
};

class Item {
private:
	std::string name;
	double price;
    ItemType type; // added to specify item type
public:
    Item(std::string name, double price, ItemType type = IT_UNKNOWN);
	Item(const Item &item);
    virtual ~Item();
	
	std::string getName() const;
	double getPrice() const;
    ItemType getType() const;

    virtual int getRestorePts() const { return 0; }   // I preferred to return 0 here and only
    virtual int getAttackPts() const { return 0; }    // overwrite methods when necessary
    virtual int getDefensePts() const { return 0; }
    virtual double getWeight() const { return 0; }
    virtual void use(Character *c) = 0;
};

#endif // ITEM_H
