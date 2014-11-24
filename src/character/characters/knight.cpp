#include "../include/knight.h"

Knight::Knight(std::string alias, int power) : Character(alias) {
    this->power = power;
}

int Knight::getDefensePts() {
    return Character::getDefensePts() + power;
}

void Knight::addPower(int value) {
    this->power += value;
}
