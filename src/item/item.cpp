/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "item.h"

Item::Item(std::string name, double price, ItemType type) {
	this->name = name;
    this->price = price;
    this->type = type;
}

Item::Item(const Item &item) {
	this->name = item.name;
	this->price = item.price;
}

Item::~Item() {

}
	
std::string Item::getName() const {
	return this->name;
}

double Item::getPrice() const {
	return this->price;
}

ItemType Item::getType() const {
    return this->type;
}
