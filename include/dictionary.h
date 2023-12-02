#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief TDA Dictionary
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 */

class Dictionary {
private:

    /**
     * @brief contenedor set de strings
     */
    set <string> words;
public:

    /**
     * @brief Constructor por defecto. Crea un diccionario vacío
     */
    Dictionary();

    /**
     * @brief Constructor de copia
     * @param other Dictionary que se quiere copiar
     */
    Dictionary(const Dictionary & other);

    /**
     * @brief Indica si una palabra esta en el diccionario o no
     * @param val la palabra que se quiere buscar
     * @return Booleano indicando si la palabra existe o no en el diccionario
     */
    bool exists(const string & val ) const;

    /**
     * @brief Inserta una palabra en el diccionario
     * @param val palabra a insertar en el diccionario
     * @return Booleano que indica si l ainseción ha tenido éxito. UUna palabra se inserta con éxito si no existía previamente en el diccionario
     */
    bool insert (const string & val);

    /**
     * @brief Elimina una palabra del diccionario
     * @param val Palabra a borrar del diccionario
     * @return Booleano que indica si la palabra se ha borrado del diccionario
     */
    bool erase(const string & val);

    /**
     * @brief Limpia el Dictionary
     */
    void clear();

    /**
     * @brief Comprueba si el diccionario está vacío
     * @return true si el diccionario está vacío
     */
    bool empty() const;

    /**
     * @brief Tamaño del diccionario
     * @return Número de palabras guardadas en el diccionario
     */
    unsigned int size() const;

    /**
     * @brief Indica el numero de apariciones de una letra
     * @param c letra a buscar
     * @return Un entero indicando el número  de apariciones
     */
    int getOcurrences(const char c);

    /**
     * @brief Cuenta el total de letras de un diccionario
     * @return Enetero con el total de letras
     */
    int getTotalLetters();

    /**
     * @brief Devuelve las palabras en el diccionario con una longitud dada
     * @param lenght Longitud de las palabras buscadas
     * @return Vector de palbras con la longitud deseada
     */
    vector <string> wordsOfLenght (int lenght);

    /**
     * @brief Sobrecarga del operador de entrada
     * @param is elemento istream del que se lee la información
     * @param d tipo Dictionary a construir
     * @return elemento de tipo istream
     * @pre no se añade una palabra cuya longitud sea 1 o menos. De esta forma no guardamos los índices de un diccionario como palabras
     */
    friend istream & operator >> ( istream & is, Dictionary & d);



    set<string>::iterator begin();
    set<string>::iterator end();




};


#endif
