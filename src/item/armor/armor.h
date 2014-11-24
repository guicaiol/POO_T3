/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef ARMOR_H
#define ARMOR_H

#include "src/item/item.h"
#include "src/character/character.h"

class Armor : public Item {
protected:
    int defensepts;
	double weight;
public:
    Armor(std::string name, double price, int defensepts, double weight);
	Armor(const Armor &armor);
	
    int getDefensePts() const;
	double getWeight() const;

    void use(Character *c);
};

#endif // ARMOR_H
