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
	unsigned attackpts;
	double range;
public:
	Weapon(std::string name, double price, unsigned attackpts, double range);
	Weapon(const Weapon &weapon);
	
    int getAttackPts() const;
	double getRange() const;

    void use(Character *c);
};

#endif // WEAPON_H
