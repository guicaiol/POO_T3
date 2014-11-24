#include "../include/team.h"

Team::Team(std::string name, Color color) {
    this->name = name;
    this->color = color;

    // Initialization
    this->win = 0;
    this->lose = 0;
    this->draw = 0;
}

Team::~Team() {
    while(characters.empty()==false) {
        Character *tmp = characters.at(characters.size()-1);
        delete tmp;
        characters.pop_back();
    }
}

std::string Team::getName() const {
    return this->name;
}

std::string Team::getResults() const {
    std::stringstream ss;
    ss << "Team \"" << this->name << "\" (" << HColor::colorToString(this->color) << "):\n";
    ss << this->win << " win\n";
    ss << this->lose << " lost\n";
    ss << this->draw << " draw\n";
    return ss.str();
}

std::string Team::toString() const {
    std::stringstream ss;
    ss << this->name << " (" << HColor::colorToString(this->color) << ")";
    return ss.str();
}

std::string Team::getCharsInfo() const {
    std::stringstream ss;
    for(unsigned i=0; i<characters.size(); i++) {
        Character *tmp = characters.at(i);
        ss << "--------- Char \"" << tmp->getName()  << "\" ---------\n";
        ss << tmp->getInfo() << "\n\n";
    }
    return ss.str();
}

double Team::getPoints() const {
    double sum=0.0;
    for(std::vector<Character*>::const_iterator it = characters.begin(); it!=characters.end(); it++)
        sum += (*it)->getHP();
    return (double)sum/characters.size();
}

Character* Team::searchChar(std::string name) const {
    for(std::vector<Character*>::const_iterator it = characters.begin(); it!=characters.end(); it++)
        if((*it)->getName()==name)
            return (*it);
    return NULL;
}

int Team::resolveBattle(const Team &team) {
    const double our = this->getPoints();
    const double their = team.getPoints();
    const double result = our - their;

    if(result>0) // win
        win++;
    else if(result<0) // lose
        lose++;
    else if(result==0) // draw
        draw++;
    return result>0? 1 : (result<0? -1 : 0);
}

void Team::addChar(Character *c) {
    if(c==NULL)
        return;
    characters.push_back(c);
}

void Team::removeChar(std::string name) {
    for(std::vector<Character*>::iterator it = characters.begin(); it!=characters.end(); it++) {
        if((*it)->getName()==name) {
            delete (*it);
            characters.erase(it);
        }
    }
}

void Team::removeChar(Character *c) {
    removeChar(c->getName());
}

void Team::removeChar(int index) {
    removeChar(*(characters.begin() + index));
}