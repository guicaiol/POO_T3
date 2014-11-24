#ifndef MANAPOTION_H
#define MANAPOTION_H

#include "potion.h"
#include "character.h"

class ManaPotion : public Potion {
public:
	ManaPotion(std::string name, double price, unsigned restorepts);
	ManaPotion(ManaPotion &manapotion);
	~ManaPotion();

    void use(Character *c);
};

#endif // MANAPOTION_H
