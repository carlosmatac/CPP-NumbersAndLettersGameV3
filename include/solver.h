/**
 *   \file solver.h
 *   \brief Archivo de declaración de la clase Solver
 */

#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "dictionary.h"
#include "letters_set.h"
#include "letters_bag.h"

using namespace std;


/**
 * @brief Clase Solver
 *
 * Esta clase nos resuelve el juego de las letras dado un diccionario y un set de letras.
 * Admite dos modos de juego diferente, por longitud en el que el programa obtiene las palabras
 * dado un vector de letras disponibles que son más largas, o por puntuacion, en que el programa
 * devuelve las palabras del diccionario que pueden formarse con dicho vector y que tienen la mayor
 * puntuación según el LetterSet
 */

class Solver{
private:
    Dictionary dictionary;
    LetterSet letter_set;


public:

    /**
     * @brief Construye un TDA Dictionary y TDA LetterSet que se pasan como parametros
     * Estos serán elementos del ámbito privado de nuestra clase
     * @param dict TDA Dictionary
     * @param letterSet TDA LetterSet
     */
    Solver(const Dictionary & dict, const LetterSet & letterSet);

    /**
     * @brief Funcion que resulve el juego dado unas letras disponibles y el modo de juego que queremos
     * @param available_letters letras disponibles para jugar
     * @param score_game modo de juego, true si jugamos por puntuacion, false si jugamos por longitud de palabra
     * @return Devuelve un pair cuyo primer elemento es un set de strings con todas las palabras que son solución y cuyo
     * segundo elemento es la puntuación común a todas las palabras que son solución
     */
    pair <set<string>, int> getSolutions (const vector<char> & available_letters, bool score_game);

    /**
     * @brief Función auxiliar a getSolutions que resulve el juego en caso de que se juege por longitud
     * @param available_letters letras disponibles para jugar
     * @return Devuelve un pair cuyo primer elemento es un set de strings con todas las palabras que son solución y cuyo
     * segundo elemento es la puntuación común a todas las palabras que son solución
     */
    pair <set<string> , int> solutions_lon (vector<char> & available_letters);

    /**
     * @brief Función auxiliar a getSolutions que resulve el juego en caso de que se juege por puntuación
     * @param available_letters letras disponibles para jugar
     * @return Devuelve un pair cuyo primer elemento es un set de strings con todas las palabras que son solución y cuyo
     * segundo elemento es la puntuación común a todas las palabras que son solución
     */
    pair <set<string> , int> solutions_score (vector<char> & available_letters);

    /**
     * @brief Función auxiliar a getSolutions que nos permite dado un string y un vector de letras desordenado
     * comprobar si dicho string se puede formar con las letras del vector
     * @param L1 string que es la palabra que queremos comprobar si podemos formar con las letras dadas
     * @param L2 vector de char desordenado, que nos indica las letras que podemos usar para formar palabras
     * @return true si el string puede formarse con el vector, false si no puede.
     */
    bool comprueba_letras (string & L1, vector<char> & L2);
    //string & convertVector_toString (const vector<char> &  available_letters);

};
#endif