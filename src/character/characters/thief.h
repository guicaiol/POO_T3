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
    Thief(std::string _alias, int stealth);
    std::string getCharacterClass() const { return "Thief"; }

    void addStealth(int value);
};

#endif // THIEF_H
