/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef WIZARD_H
#define WIZARD_H

#include "src/character/character.h"

class Wizard : public Character {
protected:
    int wisdom;

    //int getAttackPts(); // not necessary, will automatically call Character::getAttackPts()
    int getDefensePts();
public:
    Wizard(std::string _alias, int wisdom);

    void addWisdom(int value);
    //void attack(Character &defender); // unused, for now, attack() still the same as Character::attack()
};

#endif // WIZARD_H
