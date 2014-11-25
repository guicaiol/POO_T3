/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef POSITION_H
#define POSITION_H

#include <cmath>

class Position {
public:
    Position();
    Position(int x, int y);

    // Get X, Y
    int x() const { return _x; }
    int y() const { return _y; }

    // Set X, Y
    void setPosition(int x, int y);

    // Distance to other position
    int distanceTo(const Position &position);
private:
    int _x;
    int _y;
};

#endif // POSITION_H
