/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef THIEF_H
#define THIEF_H

#include "src/character/character.h"

class Thief : public Character {
protected:
    int stealth;

    int getAttackPts();
    //int getDefensePts(); // not necessary, will automatically call Character::getDefensePts()
public:
    Thief(std::string alias, int stealth);

    void addStealth(int value);
    //void attack(Character &defender); // unused, for now, attack() still the same as Character::attack()
};

#endif // THIEF_H
