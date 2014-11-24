#include "../include/wizard.h"

Wizard::Wizard(std::string alias, int wisdom) : Character(alias) {
    this->wisdom = wisdom;
}

int Wizard::getDefensePts() {
    return Character::getDefensePts() + this->wisdom/2;
}

void Wizard::addWisdom(int value) {
    this->wisdom += value;
}
