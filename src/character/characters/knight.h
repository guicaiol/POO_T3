/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef KNIGHT_H
#define KNIGHT_H

#include "src/character/character.h"

class Knight : public Character {
protected:
    int power;

    //int getAttackPts(); // not necessary, will automatically call Character::getAttackPts()
    int getDefensePts();
public:
    Knight(std::string _alias, int power);

    void addPower(int value);
    //void attack(Character &defender); // unused, for now, attack() still the same as Character::attack()
};

#endif // KNIGHT_H
