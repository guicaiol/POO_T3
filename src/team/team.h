/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef TEAM_H
#define TEAM_H

#include <sstream>
#include <iostream>
#include <vector>

#include "../character/character.h"
#include "../utils/position.h"
#include "../utils/myvector.h"
#include "color.h"

class Field; // foward-declaration

class Team {
private:
    std::string _name;
    Color _color;
    int _win;
    int _lose;
    int _draw;
    MyVector<Character*> _characters;
    Field *_field;
public:
    Team(std::string _name, Color _color);
    ~Team();

    // Team info
    std::string getName() const;
    std::string getResults() const;
    double getPoints() const;
    int getWin() const { return _win; }
    int getLose() const { return _lose; }
    int getDraw() const { return _draw; }

    // Characters info
    MyVector<Character*>* chars();
    void addChar(Character *c);
    void removeChar(Character *c);
    void removeChar(std::string _name);
    int size() const { return _characters.size(); }

    // Battle control
    void reset();
    void stopBattle();
    void startBattle();
    void setInitialPosition(const Position &center);
    int playersAlive() const;

    // Field/enemies info
    void setField(Field *field);
    Character* getNearestEnemy(Character *ch);

    // Battle info modifiers
    void addWin() { _win++; }
    void addLose() { _lose++; }
    void addDraw() { _draw++; }
};

#endif // TEAM_H
