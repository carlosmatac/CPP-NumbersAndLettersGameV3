#include "letters_bag.h"
#include <iostream>
#include "letters_set.h"
using namespace  std;


LettersBag::LettersBag() {}
LettersBag::LettersBag(const LetterSet &letterSet){

    LetterSet aux = letterSet;
    int repeticiones;

    for (map<char, LetterInfo>::iterator i = aux.begin(); i != aux.end(); ++i){

        repeticiones = i->second.repetitions;

        for (int k=0; k<repeticiones; ++k){
            letters.add(i->first);
        }
    }
}
void LettersBag::insertLetter(const char & l){

    letters.add(l);
}
char LettersBag::extractLetter(){

    return letters.get();
}
vector <char> LettersBag::extractLetters( int num){

    vector<char> aux;

    for (int i=0; i<num; ++i){
        aux.push_back(letters.get());
    }

    return aux;
}
void LettersBag::clear(){

    letters.clear();
}
unsigned int LettersBag::size(){

    return letters.size();
}
LettersBag & LettersBag::operator = ( const LettersBag & other){

    this->letters = other.letters;
    return *this;
}