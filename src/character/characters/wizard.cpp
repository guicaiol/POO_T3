/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "wizard.h"

Wizard::Wizard(std::string alias, int wisdom) : Character(alias) {
    this->wisdom = wisdom;
}

int Wizard::getDefensePts() {
    return Character::getDefensePts() + this->wisdom/2;
}

void Wizard::addWisdom(int value) {
    this->wisdom += value;
}
