/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef KNIGHT_H
#define KNIGHT_H

#include "../character.h"

class Knight : public Character {
protected:
    int power;

    //int getAttackPts(); // not necessary, will automatically call Character::getAttackPts()
    int getDefensePts();
public:
    Knight(std::string _alias, int power);
    std::string getCharacterClass() const { return "Knight"; }

    void addPower(int value);

};

#endif // KNIGHT_H
