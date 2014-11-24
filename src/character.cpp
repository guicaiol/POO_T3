#include "../include/character.h"

Character::Character(std::string alias) {
	this->alias = alias;
	
	// Initialization
	this->XP = 1;
	this->strenght = 1;
	this->speed = 1;
	this->dexterity = 1;
	this->constitution = 1;
	this->HP = 100;
	this->MP = 100;

    // Default spaces = 5, currently constant
    myitems.setSpaces(5);
}

Character::~Character() {

}

void Character::useItem(std::string name) {
    Item *item = myitems.searchItem(name);
    if(item==NULL) {
        std::cout << ">> Character (" << this->getName() << "): tried to use item \"" << name << "\" that doesn't exists in inventory!\n";
        return;
    }

    // Effectvely use
    item->use(this);
}

bool Character::hasItem(std::string name) const {
    Item *item = myitems.searchItem(name);
    if(item!=NULL)
        return true;
    return false;
}

int Character::getHP() const {
    return this->HP;
}

int Character::getMP() const {
    return this->MP;
}

std::string Character::getName() const {
	return this->alias;
}

int Character::getAttributesSum() const {
	// Return sum of attributes
	return strenght+speed+dexterity+constitution;
}

void Character::setStrenght(int value) {
	// Check attributes maximum sum value
    int attrSum = this->getAttributesSum();
    int free = Character::maxAttrSum - attrSum + this->strenght;
	if(value>free) {
		std::cout << ">> Character '" << this->alias << "': setStrenght(" << value << ") exceeded maximum points available; strenght set to " << free << ".\n";
		value = free;
	}
	
	// Set strenght
	this->strenght = value;
}

void Character::setSpeed(int value) {
	// Check attributes maximum sum value
    int attrSum = this->getAttributesSum();
    int free = Character::maxAttrSum - attrSum + this->speed;
	if(value>free) {
		std::cout << ">> Character '" << this->alias << "': setSpeed(" << value << ") exceeded maximum points available; speed set to " << free << ".\n";
		value = free;
	}
	
	// Set speed
	this->speed = value;
}

void Character::setDexterity(int value) {
	// Check attributes maximum sum value
    int attrSum = this->getAttributesSum();
    int free = Character::maxAttrSum - attrSum + this->dexterity;
	if(value>free) {
		std::cout << ">> Character '" << this->alias << "': setDexterity(" << value << ") exceeded maximum points available; dexterity set to " << free << ".\n";
		value = free;
	}
	
	// Set dexterity
	this->dexterity = value;
}

void Character::setConstitution(int value) {
	// Check attributes maximum sum value
    int attrSum = this->getAttributesSum();
    int free = Character::maxAttrSum - attrSum + this->constitution;
	if(value>free) {
		std::cout << ">> Character '" << this->alias << "': setConstitution(" << value << ") exceeded maximum points available; constitution set to " << free << ".\n";
		value = free;
	}
	
	// Set constitution
	this->constitution = value;
}

void Character::setStats(int strenght, int speed, int dexterity, int constitution) {
    setStrenght(strenght);
    setSpeed(speed);
    setDexterity(dexterity);
    setConstitution(constitution);
}

void Character::addXP(int value) {
	this->XP += value;

	// Check min and max
	if(this->XP < 1)
		this->XP = 1;	
	if(this->XP > 100)
		this->XP = 100;
}

void Character::addHP(int value) {
	this->HP += value;
	
	// Check min and max
    if((int)this->HP < 0)
		this->HP = 0;
    if((int)this->HP > 100)
		this->HP = 100;
}

void Character::addMP(int value) {
	this->MP += value;
	
	// Check min and max
	if(this->MP < 0)
		this->MP = 0;
	if(this->MP > 100)
		this->MP = 100;
}

double Character::getRealSpeed() const {
    const double w = myitems.getEquipedWeight();
    return speed*exp(-pow(w/20, 2));
}

int Character::getDefensePts() const {
	int equiped_def_pts = myitems.getEquipedDefensePts();
	float constitution = 0.5*this->constitution;
	float dexterity = 0.3*this->dexterity;
    float speed = 0.2*this->getRealSpeed();
	return (constitution+dexterity+speed+equiped_def_pts)*((float)this->XP/2);
}

int Character::getAttackPts() const {
	int equiped_atk_pts = myitems.getEquipedAttackPts();
	float strenght = 0.5*this->strenght;
	float dexterity = 0.3*this->dexterity;
    float speed = 0.2*this->getRealSpeed();
	return (strenght+dexterity+speed+equiped_atk_pts)*((float)this->XP/3);
}

void Character::attack(Character *defender) {
	int r=0;
	
	// Output
    std::cout << this->alias << " attacks " << defender->getName() << ": ";
	
	// Miss chance
	const float miss = (0.1/this->XP)*100;
	srand(clock());
	r = rand()%100;
	if(r<miss) {
		std::cout << "MISSED!\n";
		// No damage
		return;
	}
	
	// Critical chance
	const float critical = (0.02*(this->XP/2))*100;
	bool criticalHit = false;
	srand(r);
	r = rand()%100;
	if(r<critical)
		criticalHit = true;
		
	// Generate attack damage
    const int attack = this->getAttackPts();
    const int defense =  defender->getDefensePts();
	srand(r);
	int damage = (int)(attack - defense + (rand()%10) - 5);

    // Critical
	if(criticalHit)
		damage *= 2;
    // Low hit
	if(damage<=0)
		damage = 1;
	
	// Apply damage
    defender->addHP(-damage);
	if(criticalHit)
		std::cout << "CRITICAL HIT (" << damage << ")!\n";
	else
		std::cout << "HIT (" << damage << ")!\n";
}


void Character::equipItem(std::string name) {
    myitems.equipItem(name);
}

void Character::storeItem(Item *item, bool equip) {
    myitems.insertItem(item, equip);
}

void Character::dropItem(std::string name) {
    myitems.removeItem(name);
}

std::string Character::getInfo() {
    std::stringstream ss;
    ss << "Character alias: " << this->alias << std::endl;
    ss << "Attack points: " << this->getAttackPts() << std::endl;
    ss << "Defense points: " << this->getDefensePts() << std::endl;
    ss << "XP: " << this->XP << std::endl;
    ss << "Strenght: " << this->strenght << std::endl;
    ss << "Speed: " << this->speed << std::endl;
    ss << "Real speed: " << this->getRealSpeed() << std::endl;
    ss << "Dexterity: " << this->dexterity << std::endl;
    ss << "Constitution: " << this->constitution << std::endl;
    ss << "Items in inventory:";
    for(int i=0; i<myitems.size(); i++) {
		Item *item = myitems.searchItem(i);
        if(item==NULL)
            break;
        ss << "\n\t" << item->getName() << " (atkPts: " << item->getAttackPts() << ", defPts: " << item->getDefensePts() << ", resPts: " << item->getRestorePts() << ")";
	}
    return ss.str();
}
