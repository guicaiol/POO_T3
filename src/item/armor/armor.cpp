/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "armor.h"

Armor::Armor(std::string name, double price, int defensepts, double weight) : Item(name, price, IT_DEFENSE) {
	this->defensepts = defensepts;
	this->weight = weight;
	
	// Check defensepts interval
    if(this->defensepts<1 || this->defensepts>20) {
		std::cout << ">> Armor (" << name << "): invalid defense points value; interval allowed: [1,20].\n";
		if(this->defensepts<1)
			this->defensepts = 1;
		else if(this->defensepts>20)
            this->defensepts = 20;
	}

    // Check weight interval
    if(this->weight<1 || this->weight>20) {
        std::cout << ">> Armor (" << name << "): invalid weight value; interval allowed: [1,20].\n";
        if(this->weight<1)
            this->weight = 1;
        else if(this->weight>20)
            this->weight = 20;
    }
}

Armor::Armor(const Armor &armor) : Item(armor) {
	this->defensepts = armor.defensepts;
	this->weight = armor.weight;
}

int Armor::getDefensePts() const {
	return this->defensepts;
}

double Armor::getWeight() const {
	return this->weight;
}

void Armor::use(Character *c) {
    c->equipItem(this->getName());
}
