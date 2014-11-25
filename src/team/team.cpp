/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "team.h"

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

void Team::setInitialPosition(const Position &center) {
    // Calculate players positions based on center position
    const Position pos[] = {
        Position(center.x()+1, center.y()+1),
        Position(center.x()-1, center.y()+1),
        Position(center.x()+1, center.y()-1),
        Position(center.x()-1, center.y()-1)
    };

    // Set players positions
    int c=0;
    std::vector<Character*>::iterator it;
    for(it=characters.begin(); it!=characters.end(); it++, c++) {
        Character *ch = *it;
        ch->setPosition(pos[c]);
    }
}

void Team::reset() {
    // Reset each player
    std::vector<Character*>::iterator it;
    for(it=characters.begin(); it!=characters.end(); it++) {
        Character *ch = *it;
        ch->reset();
    }
}

void Team::stopBattle() {
    // Reset each player
    std::vector<Character*>::iterator it;
    for(it=characters.begin(); it!=characters.end(); it++) {
        Character *ch = *it;
        ch->stop();
        ch->wait();
    }
}

void Team::startGame() {
    // Start each player
    std::vector<Character*>::iterator it;
    for(it=characters.begin(); it!=characters.end(); it++) {
        Character *ch = *it;
        ch->start();
    }
}

int Team::playersAlive() const {
    int alive=0;
    std::vector<Character*>::const_iterator it;
    for(it=characters.cbegin(); it!=characters.cend(); it++) {
        const Character *ch = *it;
        if(ch->isAlive())
            alive++;
    }
    return alive;
}
