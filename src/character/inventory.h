/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "../item/item.h"

class Inventory {
private:
    int _spaces;
    double _gold;
    std::vector< std::pair<Item*, bool> > _items;

    unsigned _armorsEquiped;
    unsigned _weaponsEquiped;
public:
	Inventory();
	~Inventory();

    int size() const { return _items.size(); }

    double getEquipedWeight() const;

    void setSpaces(int number);
    int getAvailableSpace() const { return _spaces - _items.size(); }
	
    double getTotalGold() const { return _gold; }
	void spendGold(double value);
	void earnGold(double value);
		
    void insertItem(Item *item, bool equip = false);
    void equipItem(std::string name);
    void unequipItem(std::string name);
    const Item* getEquipedWeapon() const;
	
	Item* searchItem(std::string name) const;
	void removeItem(std::string name);
	
    int getEquipedDefensePts() const;
    int getEquipedAttackPts() const;
};

#endif // INVENTORY_H
