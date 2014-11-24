/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "knight.h"

Knight::Knight(std::string alias, int power) : Character(alias) {
    this->power = power;
}

int Knight::getDefensePts() {
    return Character::getDefensePts() + power;
}

void Knight::addPower(int value) {
    this->power += value;
}
