#include "../include/inventory.h"

Inventory::Inventory() {
	this->spaces = 0;
	this->gold = 0;
    this->armorsEquiped = 0;
    this->weaponsEquiped = 0;
}

Inventory::~Inventory() {
    while(items.empty()==false) {
        Item *tmp = items.at(items.size()-1).first;
        delete tmp;
        items.pop_back();
    }
}

double Inventory::getTotalGold() const {
	return this->gold;
}

int Inventory::getAvailableSpace() const {
    return this->spaces - items.size();
}

double Inventory::getEquipedWeight() const {
    if(armorsEquiped==0)
        return 0;

    for(std::vector< std::pair<Item*, bool> >::const_iterator it = items.begin(); it!=items.end(); it++)
        if(it->first->getType()==IT_DEFENSE)
            return it->first->getWeight();
    return 0;
}

void Inventory::spendGold(double value) {
	// Check
	if(value<0) {
		std::cout << ">> Inventory: spendGold(" << value << "), negative value is invalid; gold not changed.\n";
		return;
	}
	
	this->gold -= value;
}

void Inventory::earnGold(double value) {
    // Check invalid value
    if(value<0) {
        std::cout << ">> Inventory: earnGold(" << value << "), negative value is invalid; gold not changed.\n";
        return;
    }

	this->gold += value;
}

void Inventory::setSpaces(int number) {
    // Check invalid number
    if(number<0)
        return;

	// Check number==0, drop all items
    if(number==0)
        while(items.empty()==false)
            this->removeItem(0);
		
    // Check inventory overflow, drop excess items
    while(items.size()>(unsigned)number)
        this->removeItem(0);
	
	this->spaces = number;
}

void Inventory::insertItem(Item *item, bool equip) {
    if(item!=NULL) {
        if(items.size()==(unsigned)this->spaces) {
            std::cout << ">> Inventory: cannot insert item \"" << item->getName() << "\", inventory is full!\n";
            return;
        }

        items.push_back(std::make_pair(item, false));
        if(equip) // if equip, equip item
            equipItem(item->getName());
    }

}

void Inventory::equipItem(std::string name) {
    // Check if item exists
    Item *item = this->searchItem(name);
    if(item==NULL)
        return;

    // Check if can equip
    bool canEquip = false;
    switch(item->getType()) {
        case IT_ATTACK:
            if(weaponsEquiped<2)
                canEquip = true;
        break;
        case IT_DEFENSE:
        if(weaponsEquiped<1)
            canEquip = true;
        break;
        case IT_CONSUMABLE:
        case IT_UNKNOWN:
        default:
            canEquip = false;
        break;
    }

    // Out
    if(canEquip==false) {
        std::cout << ">> Inventory: cannot equip item \"" << name << "\", maximum items equiped!\n";
        return;
    }

    // Effectively equip
    for(std::vector< std::pair<Item*, bool> >::iterator it = items.begin(); it!=items.end(); it++) {
        if(it->first->getName()==name && it->second==false) { // if found and is currently unequiped
            it->second = true; // set equiped to true

            // Inc counter
            if(it->first->getType()==IT_ATTACK)
                weaponsEquiped++;
            else if(it->first->getType()==IT_DEFENSE)
                armorsEquiped++;

            break;
        }
    }
}

void Inventory::unequipItem(std::string name) {
    // Check if item exists
    Item *item = this->searchItem(name);
    if(item==NULL)
        return;

    // Effectively unequip
    for(std::vector< std::pair<Item*, bool> >::iterator it = items.begin(); it!=items.end(); it++) {
        if(it->first->getName()==name && it->second) { // if found and is currently equiped
            it->second = false; // set equiped to false

            // Dec counter
            if(it->first->getType()==IT_ATTACK)
                weaponsEquiped--;
            else if(it->first->getType()==IT_DEFENSE)
                armorsEquiped--;

            break;
        }
    }
}

Item* Inventory::searchItem(std::string name) const {
    for(std::vector< std::pair<Item*, bool> >::const_iterator it = items.begin(); it!=items.end(); it++)
        if(it->first->getName()==name)
            return it->first;
	return NULL;
}

Item* Inventory::searchItem(unsigned index) const {
	if(index<items.size())
        return items.at(index).first;
	return NULL;
}

void Inventory::removeItem(std::string name) {
    for(std::vector< std::pair<Item*, bool> >::iterator it = items.begin(); it!=items.end(); it++) {
        if(it->first->getName()==name) {
            unequipItem(name);  // unequip
            delete it->first;   // free memory
            items.erase(it);    // remove from inventory
			break;
		}
	}
}

void Inventory::removeItem(unsigned index) {
	if(index<items.size())
        removeItem((items.begin() + index)->first->getName());
}

int Inventory::getEquipedDefensePts() const {
	int sum=0;
    for(std::vector< std::pair<Item*, bool> >::const_iterator it = items.begin(); it!=items.end(); it++)
        if(it->second) // if equiped
            sum += it->first->getDefensePts();
	return sum;
}

int Inventory::getEquipedAttackPts() const {
	int sum=0;
    for(std::vector< std::pair<Item*, bool> >::const_iterator it = items.begin(); it!=items.end(); it++)
        if(it->second) // if equiped
            sum += it->first->getAttackPts();
	return sum;
}
