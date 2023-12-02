#include "dictionary.h"


Dictionary::Dictionary(){}
Dictionary::Dictionary(const Dictionary &other) {
    this->words = other.words;
}

bool Dictionary::exists(const string &val) const {

    bool salida = true;
    set<string>::iterator i = words.find(val);

    if (i == words.end()) salida = false;

    return salida;
}

bool Dictionary::insert(const string &val) {


    pair<set<string>::iterator, bool> p = words.insert(val);

    return p.second;

}

bool Dictionary::erase(const string &val) {

    int eliminado = words.erase(val);
    bool salida = false;

    if ( eliminado == 1 ) salida = true;

    return salida;
}

void Dictionary::clear() {

    words.clear();
}

bool Dictionary::empty() const {

    return words.empty();
}

unsigned int Dictionary::size() const {

    return words.size();
}

int Dictionary::getOcurrences(const char c) {

    int suma = 0;

    for (set<string>::iterator p = words.begin(); p!= words.end(); ++p){
        for (int i=0; i<p->size(); ++i){
            if (p->at(i) == c) suma ++;
        }
    }

    return suma;

}

int Dictionary::getTotalLetters() {

    int suma = 0;

    for (set<string>::iterator p = words.begin(); p!= words.end(); ++p){
        suma += p->size();
    }

    return suma;

}

vector<string> Dictionary::wordsOfLenght(int lenght) {

    vector<string> v;

    for (set<string>::iterator p = words.begin(); p!= words.end(); ++p){

        if ((*p).size() == lenght){
            v.push_back(*p);
        }
    }

    return v;

}

istream & operator >> ( istream & is, Dictionary & d){

    string cadena;
    is >> cadena;


    d.insert(cadena);

    return is;



}


set<string>::iterator Dictionary::begin() {
    return words.begin();
}

set<string>::iterator Dictionary::end(){
    return words.end();
}