/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "weapon.h"

Weapon::Weapon(std::string name, double price, unsigned attackpts, double range, int atkSpeed) : Item(name, price, IT_ATTACK) {
    this->_attackPts = attackpts;
    this->_range = range;
    this->_atkSpeed = atkSpeed;
	
	// Check attackpts interval
    if(this->_attackPts<1 || this->_attackPts>9) {
		std::cout << ">> Weapon (" << name << "): invalid attack points value; interval allowed: [1,9].\n";
        if(this->_attackPts<1)
            this->_attackPts = 1;
        else if(this->_attackPts>9)
            this->_attackPts = 9;
	}
}

Weapon::Weapon(const Weapon &weapon) : Item(weapon) {
    this->_attackPts = weapon._attackPts;
    this->_range = weapon._range;
}

int Weapon::getAttackPts() const {
    return this->_attackPts;
}

double Weapon::getRange() const {
    return this->_range;
}

int Weapon::getAtkSpeed() const {
    return this->_atkSpeed;
}

void Weapon::use(Character *c) {
    c->equipItem(this->getName());
}
