/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "character.h"
#include "src/team/team.h"

Character::Character(std::string alias) {
    this->_alias = alias;
	
	// Initialization
    this->_XP = 1;
    this->_strenght = 1;
    this->_speed = 1;
    this->_dexterity = 1;
    this->_constitution = 1;
    this->_HP = 100;
    this->_MP = 100;

    // Default spaces = 5
    _myitems.setSpaces(5);

    _myTeam = NULL;
    _coolDownTimer.reset();
    _speedTimer.reset();
}

Character::~Character() {

}

void Character::loop() {
    //std::cout << "\n" << getName() << "::loop()";

    // Attacking loop
    Character *enemy = lookForEnemy();
    if(enemy==NULL) { // no enemies to attack, just stop

    } else {
        // Get weapon
        const Weapon *equipedWeapon = (const Weapon*)_myitems.getEquipedWeapon();
        if(equipedWeapon==NULL) { // check if character has weapons

        } else {

            // Check range
            const int range = equipedWeapon->getRange();
            if(this->getPosition().distanceTo(enemy->getPosition())>range) {
                // Move to enemy
                this->moveTo(enemy->getPosition());
            } else {
                // Cool down
                const int atkSpeed = equipedWeapon->getAtkSpeed(); // atkSpeed: atks per 5 seconds
                const int atkTime = 5000/atkSpeed; // ms
                _coolDownTimer.mark();
                if(_coolDownTimer.timemsec()>=atkTime) {
                    _coolDownTimer.start();

                    // Attacks!
                    this->attack(enemy);
                }
            }
        }
    }

    // Life checking, self "disable" (thread disable)
    if(isAlive()==false)
        disable();
}

void Character::moveTo(const Position &pos) {
    int moveTime = 1000/getRealSpeed();

    // Timer speed
    _speedTimer.mark();
    if(_speedTimer.timemsec()<moveTime) {
        return;
    } else {
        _speedTimer.start();

        // Move
        Position distance(pos.x()-this->getPosition().x(), pos.y()-this->getPosition().y());
        int dirX = distance.x()==0? 0 : distance.x()/abs(distance.x());
        int dirY = distance.y()==0? 0 : distance.y()/abs(distance.y());
        Position direction(dirX, dirY);

        Position newPosition(getPosition().x()+direction.x(), getPosition().y()+direction.y());
        this->setPosition(newPosition);
    }
}

void Character::setTeam(Team *team) {
    _myTeam = team;
}

Character* Character::lookForEnemy() {
    return _myTeam->getNearestEnemy(this);
}

void Character::useItem(std::string name) {
    Item *item = _myitems.searchItem(name);
    if(item==NULL) {
        std::cout << ">> Character (" << this->getName() << "): tried to use item \"" << name << "\" that doesn't exists in inventory!\n";
        return;
    }

    // Effectvely use
    item->use(this);
}

bool Character::hasItem(std::string name) const {
    Item *item = _myitems.searchItem(name);
    if(item!=NULL)
        return true;
    return false;
}

int Character::getHP() const {
    return this->_HP;
}

int Character::getMP() const {
    return this->_MP;
}

std::string Character::getName() const {
    return this->_alias;
}

int Character::getAttributesSum() const {
	// Return sum of attributes
    return _strenght+_speed+_dexterity+_constitution;
}

void Character::setStrenght(int value) {
	// Check attributes maximum sum value
    int attrSum = this->getAttributesSum();
    int free = Character::maxAttrSum - attrSum + this->_strenght;
	if(value>free) {
        std::cout << ">> Character '" << this->_alias << "': setStrenght(" << value << ") exceeded maximum points available; strenght set to " << free << ".\n";
		value = free;
	}
	
	// Set strenght
    this->_strenght = value;
}

void Character::setSpeed(int value) {
	// Check attributes maximum sum value
    int attrSum = this->getAttributesSum();
    int free = Character::maxAttrSum - attrSum + this->_speed;
	if(value>free) {
        std::cout << ">> Character '" << this->_alias << "': setSpeed(" << value << ") exceeded maximum points available; speed set to " << free << ".\n";
		value = free;
	}
	
	// Set speed
    this->_speed = value;
}

void Character::setDexterity(int value) {
	// Check attributes maximum sum value
    int attrSum = this->getAttributesSum();
    int free = Character::maxAttrSum - attrSum + this->_dexterity;
	if(value>free) {
        std::cout << ">> Character '" << this->_alias << "': setDexterity(" << value << ") exceeded maximum points available; dexterity set to " << free << ".\n";
		value = free;
	}
	
	// Set dexterity
    this->_dexterity = value;
}

void Character::setConstitution(int value) {
	// Check attributes maximum sum value
    int attrSum = this->getAttributesSum();
    int free = Character::maxAttrSum - attrSum + this->_constitution;
	if(value>free) {
        std::cout << ">> Character '" << this->_alias << "': setConstitution(" << value << ") exceeded maximum points available; constitution set to " << free << ".\n";
		value = free;
	}
	
	// Set constitution
    this->_constitution = value;
}

void Character::setStats(int strenght, int speed, int dexterity, int constitution) {
    setStrenght(strenght);
    setSpeed(speed);
    setDexterity(dexterity);
    setConstitution(constitution);
}

void Character::addXP(int value) {
    this->_XP += value;

	// Check min and max
    if(this->_XP < 1)
        this->_XP = 1;
    if(this->_XP > 100)
        this->_XP = 100;
}

void Character::addHP(int value) {
    this->_HP += value;
	
	// Check min and max
    if((int)this->_HP < 0)
        this->_HP = 0;
    if((int)this->_HP > 100)
        this->_HP = 100;
}

void Character::addMP(int value) {
    this->_MP += value;
	
	// Check min and max
    if(this->_MP < 0)
        this->_MP = 0;
    if(this->_MP > 100)
        this->_MP = 100;
}

int Character::getRealSpeed() const {
    const double w = _myitems.getEquipedWeight();
    const int realSpeed = (int)(_speed*exp(-pow(w/20, 2)));
    return realSpeed<1? 1 : realSpeed;
}

int Character::getDefensePts() const {
    int equiped_def_pts = _myitems.getEquipedDefensePts();
    float constitution = 0.5*this->_constitution;
    float dexterity = 0.3*this->_dexterity;
    float speed = 0.2*this->getRealSpeed();
    return (constitution+dexterity+speed+equiped_def_pts)*((float)this->_XP/2);
}

int Character::getAttackPts() const {
    int equiped_atk_pts = _myitems.getEquipedAttackPts();
    float strenght = 0.5*this->_strenght;
    float dexterity = 0.3*this->_dexterity;
    float speed = 0.2*this->getRealSpeed();
    return (strenght+dexterity+speed+equiped_atk_pts)*((float)this->_XP/3);
}

void Character::attack(Character *defender) {
	int r=0;
    std::stringstream ss;
	
	// Output
    ss << this->_alias << " (team " << _myTeam->getName() << ") attacks " << defender->getName() << " (team " << defender->getTeam()->getName() << "): ";
	
	// Miss chance
    const float miss = (0.1/this->_XP)*100;
	srand(clock());
	r = rand()%100;
	if(r<miss) {
        ss << "MISSED!\n";
		// No damage
		return;
	}
	
	// Critical chance
    const float critical = (0.02*(this->_XP/2))*100;
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
        ss << "CRITICAL HIT (" << damage << ")!\n";
	else
        ss << "HIT (" << damage << ")!\n";
    if(defender->isAlive()==false)
        ss << defender->getName() << " is dead!\n";

    OutputHandler::lock();
    std::cout << ss.str();
    OutputHandler::unlock();
}


void Character::equipItem(std::string name) {
    _myitems.equipItem(name);
}

void Character::storeItem(Item *item, bool equip) {
    _myitems.insertItem(item, equip);
}

void Character::dropItem(std::string name) {
    _myitems.removeItem(name);
}

std::string Character::getInfo() {
    std::stringstream ss;
    ss << "Character alias: " << this->_alias << std::endl;
    ss << "Attack points: " << this->getAttackPts() << std::endl;
    ss << "Defense points: " << this->getDefensePts() << std::endl;
    ss << "XP: " << this->_XP << std::endl;
    ss << "Strenght: " << this->_strenght << std::endl;
    ss << "Speed: " << this->_speed << std::endl;
    ss << "Real speed: " << this->getRealSpeed() << std::endl;
    ss << "Dexterity: " << this->_dexterity << std::endl;
    ss << "Constitution: " << this->_constitution << std::endl;
    ss << "Items in inventory:";
    for(int i=0; i<_myitems.size(); i++) {
        Item *item = _myitems.searchItem(i);
        if(item==NULL)
            break;
        ss << "\n\t" << item->getName() << " (atkPts: " << item->getAttackPts() << ", defPts: " << item->getDefensePts() << ", resPts: " << item->getRestorePts() << ")";
	}
    return ss.str();
}

void Character::setPosition(const Position &pos) {
    _position = pos;
}

void Character::reset() {
    // Reset position
    _position.setPosition(0, 0);

    // Reset HP and MP
    _HP = 100;
    _MP = 100;
}
