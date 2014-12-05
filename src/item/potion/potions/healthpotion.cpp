/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "healthpotion.h"
#include "src/team/team.h"

HealthPotion::HealthPotion(double price, unsigned restorepts) : Potion("Health Potion", price, restorepts) {

}

HealthPotion::HealthPotion(HealthPotion &healthpotion) : Potion(healthpotion) {

}

HealthPotion::~HealthPotion() {

}

void HealthPotion::use(Character *c) {
    std::cout << c->getName() << " (" << c->getTeam()->getName() << ") usou poção de HP (+" << this->getRestorePts() <<" HP)!\n";

    c->addHP(this->getRestorePts());
    c->dropItem(this->getName()); // should be the last call; after this object will no longer exists
}
