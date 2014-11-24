#ifndef CHARACTER_H
#define CHARACTER_H

#include <cstdlib>
#include <ctime>
#include <sstream>
#include <math.h>
#include "inventory.h"

class Character {
protected:
	unsigned XP;
	unsigned strenght;
	unsigned speed;
	unsigned dexterity;
	unsigned constitution;
	
    virtual int getDefensePts() const;
    virtual int getAttackPts() const;
private:
	static const unsigned maxAttrSum = 100;

	std::string alias;
	Inventory myitems;
    int HP;
    int MP;
	
    int getAttributesSum() const;
    double getRealSpeed() const;
public:
	Character(std::string alias);
    virtual ~Character();
	
    int getHP() const;
    int getMP() const;
	std::string getName() const;
    void setStrenght(int value);
    void setSpeed(int value);
    void setDexterity(int value);
    void setConstitution(int value);
    void setStats(int strenght, int speed, int dexterity, int constitution);
	void addXP(int value);
	void addHP(int value);
	void addMP(int value);
    void useItem(std::string name);
    bool hasItem(std::string name) const;

    void storeItem(Item *item, bool equip = false);
    void equipItem(std::string name);
    void dropItem(std::string name);
    std::string getInfo();
	
    virtual void attack(Character *defender);
};

#endif // CHARACTER_H
