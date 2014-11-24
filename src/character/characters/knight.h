#ifndef KNIGHT_H
#define KNIGHT_H

#include "character.h"

class Knight : public Character {
protected:
    int power;

    //int getAttackPts(); // not necessary, will automatically call Character::getAttackPts()
    int getDefensePts();
public:
    Knight(std::string alias, int power);

    void addPower(int value);
    //void attack(Character &defender); // unused, for now, attack() still the same as Character::attack()
};

#endif // KNIGHT_H
