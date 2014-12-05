/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "manapotion.h"
#include "../../../team/team.h"

ManaPotion::ManaPotion(double price, unsigned restorepts) : Potion("Mana Potion", price, restorepts) {

}

ManaPotion::ManaPotion(ManaPotion &manapotion) : Potion(manapotion) {

}

ManaPotion::~ManaPotion() {

}

void ManaPotion::use(Character *c) {
    std::cout << c->getName() << " (" << c->getTeam()->getName() << ") usou poção de MP (+" << this->getRestorePts() <<" MP)!" << "\n";

    c->addMP(this->getRestorePts());
    c->dropItem(this->getName()); // should be the last call; after this object will no longer exists
}
