#ifndef POTION_H
#define POTION_H

#include "item.h"

class Potion : public Item {
private:
    int restorepts;
public:
    Potion(std::string name, double price, int restorepts);
	Potion(const Potion &potion);
    ~Potion();
	
    int getRestorePts() const;
	
    virtual void use(Character *c) = 0;
};

#endif // POTION_H
