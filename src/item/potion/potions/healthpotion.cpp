#include "../include/healthpotion.h"

HealthPotion::HealthPotion(std::string name, double price, unsigned restorepts) : Potion(name, price, restorepts) {

}

HealthPotion::HealthPotion(HealthPotion &healthpotion) : Potion(healthpotion) {

}

HealthPotion::~HealthPotion() {

}

void HealthPotion::use(Character *c) {
    std::cout << c->getName() << " used HealthPotion (+" << this->getRestorePts() <<" HP)!" << "\n";

    c->addHP(this->getRestorePts());
    c->dropItem(this->getName()); // should be the last call; after this object will no longer exists
}
