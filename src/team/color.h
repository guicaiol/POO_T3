/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * @author: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef COLOR_H
#define COLOR_H

#include <iostream>

enum Color {
    blue=1,
    red,
    green,
    yellow
};

class HColor {
public:
    static std::string colorToString(Color color) {
        switch(color) {
            case blue:
                return "azul";
            case red:
                return "vermelho";
            case green:
                return "verde";
            case yellow:
                return "amarelo";
            default:
                return "undefined";
        }
    }
};

#endif // COLOR_H
