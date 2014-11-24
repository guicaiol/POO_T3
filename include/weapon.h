#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"
#include "character.h"

class Weapon : public Item {
protected:
	unsigned attackpts;
	double range;
public:
	Weapon(std::string name, double price, unsigned attackpts, double range);
	Weapon(const Weapon &weapon);
	
    int getAttackPts() const;
	double getRange() const;

    void use(Character *c);
};

#endif // WEAPON_H
