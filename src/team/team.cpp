/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "team.h"
#include "src/game/field.h"

Team::Team(std::string name, Color color) {
    this->_name = name;
    this->_color = color;
    this->_field = NULL;

    // Initialization
    this->_win = 0;
    this->_lose = 0;
    this->_draw = 0;
}

Team::~Team() {
    while(_characters.empty()==false) {
        Character *tmp = _characters.at(_characters.size()-1);
        delete tmp;
        _characters.pop_back();
    }
}

void Team::setField(Field *field) {
    _field = field;
}

std::string Team::getName() const {
    return this->_name;
}

std::string Team::getResults() const {
    std::stringstream ss;
    ss << "Team \"" << this->_name << "\" (" << HColor::colorToString(this->_color) << "):\n";
    ss << this->_win << " win\n";
    ss << this->_lose << " lost\n";
    ss << this->_draw << " draw\n";
    return ss.str();
}

double Team::getPoints() const {
    double sum=0.0;
    for(std::vector<Character*>::const_iterator it = _characters.begin(); it!=_characters.end(); it++)
        sum += (*it)->getHP();
    return (double)sum/_characters.size();
}

void Team::addChar(Character *c) {
    if(c==NULL)
        return;
    _characters.push_back(c);
    c->setTeam(this);
}

void Team::removeChar(std::string name) {
    for(std::vector<Character*>::iterator it = _characters.begin(); it!=_characters.end(); it++) {
        if((*it)->getName()==name) {
            delete (*it);
            _characters.erase(it);
        }
    }
}

void Team::removeChar(Character *c) {
    removeChar(c->getName());
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
    for(it=_characters.begin(); it!=_characters.end(); it++, c++) {
        Character *ch = *it;
        ch->setPosition(pos[c]);
    }
}

void Team::reset() {
    // Reset each player
    std::vector<Character*>::iterator it;
    for(it=_characters.begin(); it!=_characters.end(); it++) {
        Character *ch = *it;
        ch->reset();
    }
}

void Team::stopBattle() {
    // Reset each player
    std::vector<Character*>::iterator it;
    for(it=_characters.begin(); it!=_characters.end(); it++) {
        Character *ch = *it;
        ch->stop();
        ch->wait();
    }
}

void Team::startBattle() {
    // Start each player
    std::vector<Character*>::iterator it;
    for(it=_characters.begin(); it!=_characters.end(); it++) {
        Character *ch = *it;
        ch->start();
    }
}

int Team::playersAlive() const {
    int alive=0;
    std::vector<Character*>::const_iterator it;
    for(it=_characters.cbegin(); it!=_characters.cend(); it++) {
        const Character *ch = *it;
        if(ch->isAlive())
            alive++;
    }
    return alive;
}

MyVector<Character*>* Team::chars() {
    return &_characters;
}

Character* Team::getNearestEnemy(Character *ch) {
    return _field->getNearestEnemy(this, ch);
}
