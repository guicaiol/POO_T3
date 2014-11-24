/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "thief.h"

Thief::Thief(std::string alias, int stealth) : Character(alias) {
    this->stealth = stealth;
}

int Thief::getAttackPts() {
    return Character::getAttackPts() + stealth;
}

void Thief::addStealth(int value) {
    this->stealth += value;
}
