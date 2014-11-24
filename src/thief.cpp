#include "../include/thief.h"

Thief::Thief(std::string alias, int stealth) : Character(alias) {
    this->stealth = stealth;
}

int Thief::getAttackPts() {
    return Character::getAttackPts() + stealth;
}

void Thief::addStealth(int value) {
    this->stealth += value;
}
