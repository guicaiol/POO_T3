#include "../include/manapotion.h"

ManaPotion::ManaPotion(std::string name, double price, unsigned restorepts) : Potion(name, price, restorepts) {

}

ManaPotion::ManaPotion(ManaPotion &manapotion) : Potion(manapotion) {

}

ManaPotion::~ManaPotion() {

}

void ManaPotion::use(Character *c) {
	std::cout << c->getName() << " used ManaPotion (+" << this->getRestorePts() <<" MP)!" << "\n";

    c->addMP(this->getRestorePts());
    c->dropItem(this->getName()); // should be the last call; after this object will no longer exists
}
