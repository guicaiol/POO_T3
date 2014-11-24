#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"
#include "character.h"

class Armor : public Item {
protected:
    int defensepts;
	double weight;
public:
    Armor(std::string name, double price, int defensepts, double weight);
	Armor(const Armor &armor);
	
    int getDefensePts() const;
	double getWeight() const;

    void use(Character *c);
};

#endif // ARMOR_H
