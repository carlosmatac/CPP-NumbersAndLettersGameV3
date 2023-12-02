#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "bag.h"
#include <iostream>
#include "letters_set.h"



using namespace  std;
/**
 * @brief TDA LettersBag
 *
 * Este TDA almacena un conjunto de chars utilizado en el juego de letras.
 * La estructura de datos subyacente es una lista de chars.
 */
class LettersBag {
private:
    /**
     * @brief bolsa Bag de caracteres
     */
    Bag <char> letters;
public:
    LettersBag();
    /**
     * @brief Constructor dado un LetterSet. Dado un LetterSet como argumento, este constructor debe rellenar la LettersBag con las letras que contiene el LetterSet, introduciendo
     * cada letra el número de veces indicado por el campo LetterInfo::repetitions.
     * @param letterSet letterSet TDA LetterSet a parsear
     */
    LettersBag(const LetterSet &letterSet);

    /**
     * @brief Introduce una letra en la bolsa
     * @param l letra a añadir a la LettersBag
     */
    void insertLetter(const char & l);

    /**
     * @brief Extrae una letra aleatoria de la bolsa, eliminadola del conjunto
     */
    char extractLetter();

    /**
     * @brief Extrae un conjunto de letras, eliminándolas del conjunto
     * @param num Número de letras a extraer
     * @return Lista con las letras extraídas aleatoriamente
     */
    vector <char> extractLetters( int num);

    /**
     * @brief Vacía la LettersBag
     */
    void clear();

    /**
     * @brief Tamaño de la bolsa
     * @return int con el tamaño de la bolsa
     */
    unsigned int size();

    /**
     * @brief Sobrecarga del operador de asignación
     * @returns Referencia a this de esta forma el operador puede ser encadenado
     */
    LettersBag & operator = ( const LettersBag & other);





};
#endif
