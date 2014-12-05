/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "inventory.h"

Inventory::Inventory() {
    this->_spaces = 0;
    this->_gold = 0;
    this->_armorsEquiped = 0;
    this->_weaponsEquiped = 0;
}

Inventory::~Inventory() {
    while(_items.empty()==false) {
        Item *tmp = _items.at(_items.size()-1).first;
        delete tmp;
        _items.pop_back();
    }
}

double Inventory::getEquipedWeight() const {
    if(_armorsEquiped==0)
        return 0;

    for(std::vector< std::pair<Item*, bool> >::const_iterator it = _items.begin(); it!=_items.end(); it++)
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
	
    this->_gold -= value;
}

void Inventory::earnGold(double value) {
    // Check invalid value
    if(value<0) {
        std::cout << ">> Inventory: earnGold(" << value << "), negative value is invalid; gold not changed.\n";
        return;
    }

    this->_gold += value;
}

void Inventory::setSpaces(int number) {
    // Check invalid number
    if(number<0)
        return;

	// Check number==0, drop all items
    if(number==0)
        while(_items.empty()==false)
            this->removeItem(0);
		
    // Check inventory overflow, drop excess items
    while(_items.size()>(unsigned)number)
        this->removeItem(0);
	
    this->_spaces = number;
}

void Inventory::insertItem(Item *item, bool equip) {
    if(item!=NULL) {
        if(_items.size()==(unsigned)this->_spaces) {
            std::cout << ">> Inventory: cannot insert item \"" << item->getName() << "\", inventory is full!\n";
            return;
        }

        _items.push_back(std::make_pair(item, false));
        if(equip) // if equip, equip item
            equipItem(item->getName());
    }
}

const Item* Inventory::getEquipedWeapon() const {
    std::vector< std::pair<Item*, bool> >::const_iterator it;
    for(it = _items.cbegin(); it!=_items.cend(); it++) {
        const Item* item = it->first;
        const bool equiped = it->second;

        // If attack item and equiped, return
        if(item->getType()==IT_ATTACK && equiped) {
            return item;
            break;
        }
    }

    return NULL;
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
            if(_weaponsEquiped<2)
                canEquip = true;
        break;
        case IT_DEFENSE:
        if(_weaponsEquiped<1)
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
    for(std::vector< std::pair<Item*, bool> >::iterator it = _items.begin(); it!=_items.end(); it++) {
        if(it->first->getName()==name && it->second==false) { // if found and is currently unequiped
            it->second = true; // set equiped to true

            // Inc counter
            if(it->first->getType()==IT_ATTACK)
                _weaponsEquiped++;
            else if(it->first->getType()==IT_DEFENSE)
                _armorsEquiped++;

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
    for(std::vector< std::pair<Item*, bool> >::iterator it = _items.begin(); it!=_items.end(); it++) {
        if(it->first->getName()==name && it->second) { // if found and is currently equiped
            it->second = false; // set equiped to false

            // Dec counter
            if(it->first->getType()==IT_ATTACK)
                _weaponsEquiped--;
            else if(it->first->getType()==IT_DEFENSE)
                _armorsEquiped--;

            break;
        }
    }
}

Item* Inventory::searchItem(std::string name) const {
    for(std::vector< std::pair<Item*, bool> >::const_iterator it = _items.begin(); it!=_items.end(); it++)
        if(it->first->getName()==name)
            return it->first;
	return NULL;
}

void Inventory::removeItem(std::string name) {
    for(std::vector< std::pair<Item*, bool> >::iterator it = _items.begin(); it!=_items.end(); it++) {
        if(it->first->getName()==name) {
            unequipItem(name);  // unequip
            delete it->first;   // free memory
            _items.erase(it);    // remove from inventory
			break;
		}
	}
}

int Inventory::getEquipedDefensePts() const {
	int sum=0;
    for(std::vector< std::pair<Item*, bool> >::const_iterator it = _items.begin(); it!=_items.end(); it++)
        if(it->second) // if equiped
            sum += it->first->getDefensePts();
	return sum;
}

int Inventory::getEquipedAttackPts() const {
	int sum=0;
    for(std::vector< std::pair<Item*, bool> >::const_iterator it = _items.begin(); it!=_items.end(); it++)
        if(it->second) // if equiped
            sum += it->first->getAttackPts();
	return sum;
}
