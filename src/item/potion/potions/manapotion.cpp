/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "manapotion.h"

ManaPotion::ManaPotion(std::string name, double price, unsigned restorepts) : Potion(name, price, restorepts) {

}

ManaPotion::ManaPotion(ManaPotion &manapotion) : Potion(manapotion) {

}

ManaPotion::~ManaPotion() {

}

void ManaPotion::use(Character *c) {
	std::cout << c->getName() << " used ManaPotion (+" << this->getRestorePts() <<" MP)!" << "\n";

    c->addMP(this->getRestorePts());
    c->dropItem(this->getName()); // should be the last call; after this object will no longer exists
}
