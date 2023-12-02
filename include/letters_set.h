#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <map>
#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * @brief TDA LetterInfo
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */
struct LetterInfo {

    /**
     * @brief almacena las repeticiones de una letra en un LetterSet
     */
    int repetitions;

    /**
     * @brief almacena la puntuación asociada a una letra en un LetterSet
     */
    int score;
    /**
     * @brief Sobrecarga del operador de asignación
     * @param li  objeto LettreInfo del que se copia la información
     * @return referencia a this
     */
    LetterInfo & operator = (const LetterInfo & li){
        repetitions = li.repetitions;
        score = li.score;
        return *this;
    }

    /**
     * @brief Sobrecarga del operador de salida
     * @param os referenci a elemento de tipo ostream
     * @param li objeto LetterInfo del cual obtenemos la información
     * @return referencia a elemento ostream
     */
    friend ostream & operator << (ostream & os, const LetterInfo & li){
        os << li.repetitions << " " << li.score;
        return os;
    }
/*
    friend istream & operator >> (istream & is,  LetterInfo & li){
        string rep, sc;
        is >> rep;
        is >> sc;
        li.repetitions = stoi(rep);
        li.score = stoi(sc);

        return is;
    }
    */
};
/**
 * @brief TDA LetterSet
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 */

class LetterSet{
private:

    /**
     * @brief contenedor map con clave char y estructura LetterInfo como valor asociado a la clave
     */
    map <char, LetterInfo> letters;
public:
    /**
     * @brief constructor por defecto, crea un letterset vacio
     */
    LetterSet ();
    /**
     * @brief constructor de copia, crea el dato letterSet a partir de otro
     * @param other, TDA letterset a partir del cual se crea la clase
     */
    LetterSet(const LetterSet & other);
    /**
     * @brief inserta un elemento del tipo LetterInfo dentro de la estructura
     * @param val Pareja de letra y LetterInfo asociado a insertar
     * @return booleano que marca si se ha podido insertar la letra en el LetterSet. La letra sólo se inserta correctamente si no estaba aún incluida en la colección
     */
    bool insert (const pair < char, LetterInfo> & val);
    /**
     * @brief elimina un carácter del LetterSet
     * @param key Carácter a eliminar
     * @return booleano que indica si se ha podido eleminar correctamente la letra del LetterSet
     */
    bool erase (const char & key);
    /**
     * @brief Limpia el contenido del LetterSet
     */
    void clear();
    /**
     * @brief Consulta si el LetterSet es vacío
     * @return true si el LetterSet está vacío, falso en caso contratirio
     */
    bool empty() const;
    /**
     * @brief Tamaño del LetterSet
     * @return Número de elementos en el LetterSet
     */
    unsigned  int size() const;
    /**
     * @brief Calcula la puntuación dada una palabra
     * @param word String con la palabra cuya puontuación queremos calcular
     * @return Puntuación de la palabra, calculada como la suma de las puntuaciones de cada una de sus letras
     */
    int getScore(string word);
    /**
     * @brief Sobrecarga del operador de asignación
     * @param cl LetterSet a copiar
     * @return Referencia al objeto this para poder encadenar el operador
     */
    LetterSet & operator =(const LetterSet & cl);
    /**
     * @brief Sobrecarga del operador consulta. Permite acceder a los elementos del map que hay en nuestra clase
     * @param val Carácter a consultar
     * @return  Estructura del tipo LetterInfo con la información del carácter consultado: Número de repeticiones y puntuación
     */
    LetterInfo & operator [](const char & val);
    /**
     * @brief Sobrecarga del operador de salida
     * @param os Flujo de salida, donde escribir el LetterSet
     * @param cl el LetterSet que se escribe
     * @return Elemento de tipo ostream
     */
    friend ostream & operator << (ostream & os, const LetterSet & cl);
    /**
     * @brief Sobrecarga del operador de entrada
     * @param is Flujo de entrada, del que leer el LetterSet
     * @param cl LetterSet en el que almacenar la información leída
     * @return Elemento de tipo istream
     */
    friend istream & operator >> (istream & is,  LetterSet & cl);
    /**
     * @brief Iterador de la estructura map
     * @return Iterador que apunta al principio de la estructura map
     */
    map<char,LetterInfo>::iterator begin();
    /**
     * @brief Iterador de la estructura map
     * @return Iterador que apunta al final de la estructura map
     */
    map<char,LetterInfo>::iterator end();





};
#endif
