/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef WIZARD_H
#define WIZARD_H

#include "../character.h"

class Wizard : public Character {
protected:
    int wisdom;

    //int getAttackPts(); // not necessary, will automatically call Character::getAttackPts()
    int getDefensePts();
public:
    Wizard(std::string _alias, int wisdom);
    std::string getCharacterClass() const { return "Wizard"; }

    void addWisdom(int value);
};

#endif // WIZARD_H
