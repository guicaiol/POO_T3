/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef WEAPON_H
#define WEAPON_H

#include "src/item/item.h"
#include "src/character/character.h"

class Weapon : public Item {
protected:
    unsigned _attackPts;
    double _range;
    int _atkSpeed;
public:
    Weapon(std::string name, double price, unsigned attackPts, double range, int atkSpeed);
	Weapon(const Weapon &weapon);
	
    int getAttackPts() const;
	double getRange() const;
    int getAtkSpeed() const;

    void use(Character *c);
};

#endif // WEAPON_H
