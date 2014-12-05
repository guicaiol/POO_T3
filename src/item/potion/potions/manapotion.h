/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef MANAPOTION_H
#define MANAPOTION_H

#include "src/item/potion/potion.h"
#include "src/character/character.h"

class ManaPotion : public Potion {
public:
    ManaPotion(double price, unsigned restorepts);
	ManaPotion(ManaPotion &manapotion);
	~ManaPotion();

    void use(Character *c);
};

#endif // MANAPOTION_H
