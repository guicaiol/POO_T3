#ifndef COLOR_H
#define COLOR_H

#include <iostream>

enum Color {
	blue,
	red,
	green,
	yellow,
	white,
	black
};

class HColor {
public:
    static std::string colorToString(Color color) {
        switch(color) {
            case blue:
                return "blue";
            case red:
                return "red";
            case green:
                return "green";
            case yellow:
                return "yellow";
            case white:
                return "white";
            case black:
                return "black";
            default:
                return "undefined";
        }
    }
};

#endif // COLOR_H
