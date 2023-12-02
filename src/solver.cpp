#include "solver.h"
#include <cctype>
using namespace std;

Solver::Solver(const Dictionary &dict, const LetterSet &letterSet) {
    dictionary = dict;
    letter_set = letterSet;


}



pair<set<string>, int> Solver::getSolutions(const vector<char> &available_letters, bool score_game) {


    pair<set<string>, int> solver;

    vector<char> letras = available_letters;


    if (score_game){
        solver = solutions_score(letras);
    }
    else{
        solver = solutions_lon(letras);
    }

    return solver;
}




pair<set<string>, int> Solver::solutions_lon(vector<char> & available_letters) {



    vector<string> aux;
    set<string> soluciones;
    bool encontrada = false;
    int puntuacion;
    pair<set<string>, int> solver;

    for (int i = available_letters.size(); i>0 && !encontrada; --i){
        aux = dictionary.wordsOfLenght(i);
        for (auto j = aux.begin(); j != aux.end(); ++j){
            if(comprueba_letras(*j, available_letters)){
                soluciones.insert(*j);

            }
        }
        puntuacion = i;
        if (!soluciones.empty()) encontrada = true;


    }

    solver.first = soluciones;
    solver.second = puntuacion;

    return solver;

}

pair <set<string> , int> Solver::solutions_score (vector<char> & available_letters){

    vector<string> aux;
    set<string> posibles_soluciones;
    pair<set<string>, int> solver;
    set<string> soluciones;

    for (int i = available_letters.size(); i>0 ; --i) {
        aux = dictionary.wordsOfLenght(i);
        for (auto j = aux.begin(); j != aux.end(); ++j){
            if(comprueba_letras(*j, available_letters)){
                posibles_soluciones.insert(*j);

            }
        }
    }

    //posibles_soluciones ya tiene todas las palabras que coinciden con las letras
    //ahora tenemos que buscar aquellas que tengan la puntuacion mas alta

    //este primer for es para saber cual va a ser la puntuacion mas alta de todas
    int max_puntuacion=0;



    for (auto i = posibles_soluciones.begin(); i != posibles_soluciones.end(); ++i){
        if (max_puntuacion < letter_set.getScore(*i)){
            max_puntuacion = letter_set.getScore(*i);
        }
    }

    //ahora con el siguiente for ya podemos quedarnos con las palabras que tengann la puntuacion maxima

    for (auto i = posibles_soluciones.begin(); i != posibles_soluciones.end(); ++i){
        if (letter_set.getScore(*i) == max_puntuacion){
            soluciones.insert(*i);
        }
    }



    solver.second = max_puntuacion;
    solver.first = soluciones;

    return solver;


}

bool Solver::comprueba_letras (string & L1, vector<char> & L2){

    int condicion = 0;
    bool salida = false;
    bool encontrado;
    vector<char> aux = L2;

    for (int i = 0; i< L1.size(); ++i){
        encontrado =  false;
        for (auto j = aux.begin(); j != aux.end() && !encontrado; ++j){
            if (L1.at(i) == *j){
                condicion ++;
                aux.erase(j);
                encontrado =  true;
            }
        }
    }

    if (condicion == L1.size()) salida = true;

    return salida;
}