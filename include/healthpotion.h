#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "potion.h"
#include "character.h"

class HealthPotion : public Potion {
public:
    HealthPotion(std::string name, double price, unsigned restorepts);
	HealthPotion(HealthPotion &healthpotion);
	~HealthPotion();

    void use(Character *c);
};

#endif // HEALTHPOTION_H
