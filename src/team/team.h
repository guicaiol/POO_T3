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
#include "src/character/character.h"
#include "color.h"

class Team {
private:
    std::string name;
    Color color;
    int win;
    int lose;
    int draw;
    std::vector<Character*> characters;
public:
    Team(std::string name, Color color);
    ~Team();

    std::string getName() const;
    std::string getResults() const;
    std::string toString() const;
    std::string getCharsInfo() const;
    double getPoints() const;
    Character* searchChar(std::string name) const;
    int resolveBattle(const Team &team);
    void addChar(Character *c);
    void removeChar(int index);
    void removeChar(Character *c);
    void removeChar(std::string name);
    int size() const { return characters.size(); }
};

#endif // TEAM_H
