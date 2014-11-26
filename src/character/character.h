/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <cstdlib>
#include <ctime>
#include <sstream>
#include <math.h>
#include "inventory.h"
#include "src/utils/thread.h"
#include "src/utils/position.h"
#include "src/utils/timer.h"
#include "src/utils/outputhandler.h"
#include "src/item/items.h"

class Team; // forward-declaration

class Character : public Thread {
protected:
    unsigned _XP;
    unsigned _strenght;
    unsigned _speed;
    unsigned _dexterity;
    unsigned _constitution;
	
    virtual int getDefensePts() const;
    virtual int getAttackPts() const;
private:
	static const unsigned maxAttrSum = 100;

    Position _position;
    std::string _alias;
    Inventory _myitems;
    int _HP;
    int _MP;
    Team *_myTeam;
	
    int getAttributesSum() const;
    int getRealSpeed() const;

    Character* lookForEnemy();
    void moveTo(const Position &pos);

    Timer _coolDownTimer;
    Timer _speedTimer;

    void loop();
public:
    Character(std::string _alias);
    virtual ~Character();
	
    const Team* getTeam() const { return _myTeam; }
    bool isAlive() const { return (_HP>0); }
    int getHP() const;
    int getMP() const;

	std::string getName() const;
    Position getPosition() const { return _position; }
    void setStrenght(int value);
    void setSpeed(int value);
    void setDexterity(int value);
    void setConstitution(int value);
    void setStats(int _strenght, int _speed, int _dexterity, int _constitution);
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

    void setTeam(Team *team);
    void setPosition(const Position &pos);
    void reset();
};

#endif // CHARACTER_H
