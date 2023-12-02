//
// Created by usuario on 25/11/21.
//

#include "solver.h"
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;


int main (int argc, char ** argv){

    int t0,t1;
    Dictionary dictionary;
    LetterSet letterSet;
    bool score_game;

    if (argv[3] == (string) "P"){
        score_game = true;
    }
    else if (argv[3] == (string)"L"){
        score_game = false;
    }
    else cout << "Modo de juego no válido" <<endl;


    ifstream ifstream1(argv[2]);
    ifstream ifstream2(argv[1]);
    string basura;

    while(ifstream1){
        ifstream1 >> dictionary;
    }

    ifstream1.close();


    if (ifstream2){
        ifstream2 >> basura;
        ifstream2 >> basura;
        ifstream2 >> basura;
        ifstream2 >> letterSet;
    }



    ifstream2.close();

    //este letterbag ahora hay que convertirlo en un vector

    cout << "LETRAS DISPONIBLES:" << endl;

    LettersBag lettersBag(letterSet);
    vector<char> available_letters = lettersBag.extractLetters(stoi(argv[4]));



    for (auto i = available_letters.begin(); i != available_letters.end(); ++i){
        cout << *i << "\t";
    }
    cout <<endl;

    //convertimos las letras a minuscula
    for (auto i = available_letters.begin(); i != available_letters.end(); ++i){
        *i = *i + 32;
    }


    cout << "SOLUCIONES:" << endl;


    Solver solver(dictionary, letterSet);
    t0 = clock();
    pair<set<string>, int> s = solver.getSolutions(available_letters, score_game);
    t1 = clock();

    cout << "tiempo empleado en resolver la partida:  " << t1 - t0 << endl;


    for (auto i = s.first.begin(); i != s.first.end(); ++i){
        cout << *i << endl;
    }

    cout << "PUNTUACION:" << endl;
    cout << s.second <<endl;





    return 0;
}