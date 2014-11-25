/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <vector>

template<class T>
class MyVector : public std::vector<T> {
public:
    MyVector() : std::vector<T>() {

    }

    bool contains(const T &value) const {
        typename std::vector<T>::const_iterator it;
        for(it=this->cbegin(); it!=this->cend(); it++)
            if(*it==value)
                return true;
        return false;
    }
};

#endif
