#ifndef WIZARD_H
#define WIZARD_H

#include "character.h"

class Wizard : public Character {
protected:
    int wisdom;

    //int getAttackPts(); // not necessary, will automatically call Character::getAttackPts()
    int getDefensePts();
public:
    Wizard(std::string alias, int wisdom);

    void addWisdom(int value);
    //void attack(Character &defender); // unused, for now, attack() still the same as Character::attack()
};

#endif // WIZARD_H
