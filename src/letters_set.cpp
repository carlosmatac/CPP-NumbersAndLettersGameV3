#include "letters_set.h"
#include <iostream>
#include <map>
#include <cstdlib>
#include <algorithm>


using namespace std;

LetterInfo & LetterSet::operator[](const char &val) {
    return letters[val];
}
LetterSet & LetterSet::operator =(const LetterSet & cl){
    this->letters = cl.letters;
    return *this;

}
LetterSet::LetterSet() {}

LetterSet::LetterSet(const LetterSet & other){
    *this = other;
}
bool LetterSet::insert(const pair<char, LetterInfo> &val) {
    bool salida;
    pair<map<char,LetterInfo>::iterator, bool> par = letters.insert(val);
    salida = par.second;
    return salida;
}

bool LetterSet::erase(const char &key) {
    bool eliminado=false;

    int salida = letters.erase(key);
    if (salida == 1) eliminado = true;

    return eliminado;
}

void LetterSet::clear() {
    letters.clear();
}
bool LetterSet::empty() const {
    return letters.empty();
}

unsigned int LetterSet::size() const {
    return letters.size();
}

int LetterSet::getScore(std::string word) {
    int salida=0;

    std::transform(word.begin(), word.end(),word.begin(), ::toupper);

    for (int i=0; i<word.size(); i++){
        salida += letters[word[i]].score;
    }

    return salida;
}

 ostream  & operator << (ostream & os, const LetterSet & cl){
    LetterSet aux = cl; //nos creamos un auxiliar porque cl es constante y nos toca los huevos
    os << "Letra " << "Cantidad " << "Puntos" << endl;
    for (map <char, LetterInfo>::iterator  i = aux.letters.begin(); i != aux.letters.end(); ++i){
        os << i->first << " " << aux[i->first] << endl;
    }
    return os;
}

istream & operator >> (istream & is,  LetterSet & cl){
    char car;
    string repeticiones, puntos;
    LetterInfo aux;

    for (int i=0; i<25; i++){

        is >> car;
        is >> repeticiones;
        is >> puntos;

        aux.repetitions = stoi(repeticiones);
        aux.score = stoi(puntos);

        cl.letters[car] = aux;
    }

    return is;
}

map<char, LetterInfo>::iterator LetterSet::begin() {
    map <char, LetterInfo>::iterator b=letters.begin();
    return b;
}

map<char, LetterInfo>::iterator LetterSet::end() {
    map <char, LetterInfo>::iterator e=letters.end();
    return e;
}