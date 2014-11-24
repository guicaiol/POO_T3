#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "item.h"

class Inventory {
private:
	int spaces;
	double gold;
	std::vector< std::pair<Item*, bool> > items;

    unsigned armorsEquiped;
    unsigned weaponsEquiped;
public:
	Inventory();
	~Inventory();
	
	double getTotalGold() const;
	int getAvailableSpace() const;
    double getEquipedWeight() const;
	
	void spendGold(double value);
	void earnGold(double value);
	
    void setSpaces(int number);
	
    void insertItem(Item *item, bool equip = false);
    void equipItem(std::string name);
    void unequipItem(std::string name);
	
	Item* searchItem(std::string name) const;
	Item* searchItem(unsigned index) const;
	
	void removeItem(std::string name);
    void removeItem(unsigned index);

    int size() const { return items.size(); }
	
	
//	double getGold();
    int getEquipedDefensePts() const;
    int getEquipedAttackPts() const;
};

#endif // INVENTORY_H
