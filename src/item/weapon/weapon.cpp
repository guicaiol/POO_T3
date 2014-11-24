/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "weapon.h"

Weapon::Weapon(std::string name, double price, unsigned attackpts, double range) : Item(name, price, IT_ATTACK) {
	this->attackpts = attackpts;
	this->range = range;
	
	// Check attackpts interval
	if(this->attackpts<1 || this->attackpts>9) {
		std::cout << ">> Weapon (" << name << "): invalid attack points value; interval allowed: [1,9].\n";
		if(this->attackpts<1)
			this->attackpts = 1;
		else if(this->attackpts>9)
			this->attackpts = 9;
	}
}

Weapon::Weapon(const Weapon &weapon) : Item(weapon) {
	this->attackpts = weapon.attackpts;
	this->range = weapon.range;
}

int Weapon::getAttackPts() const {
	return this->attackpts;
}

double Weapon::getRange() const {
	return this->range;
}

void Weapon::use(Character *c) {
    std::cout << "Doesn't known how to use this weapon (" << this->getName() << ")...\n";
}
