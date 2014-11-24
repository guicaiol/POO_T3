/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "src/item/potion/potion.h"
#include "src/character/character.h"

class HealthPotion : public Potion {
public:
    HealthPotion(std::string name, double price, unsigned restorepts);
	HealthPotion(HealthPotion &healthpotion);
	~HealthPotion();

    void use(Character *c);
};

#endif // HEALTHPOTION_H
