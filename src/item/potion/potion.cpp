/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "potion.h"

Potion::Potion(std::string name, double price, int restorepts) : Item(name, price, IT_CONSUMABLE) {
	this->restorepts = restorepts;
}

Potion::Potion(const Potion &potion) : Item(potion) {
	this->restorepts = potion.restorepts;
}

Potion::~Potion() {

}

int Potion::getRestorePts() const {
	return this->restorepts;
}
