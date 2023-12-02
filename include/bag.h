#ifndef __BAG_H__
#define __BAG_H__
#include <vector>
#include <iostream>

using namespace std;

/**
 *  \brief TDA abstracto Bolsa
 *
 *  Este TDA abstracto nos permite trabajar con una colección de elementos que
 *  permite la extracción de elementos de forma aleatoria sin reemplazamiento
 */

template <class T>
class Bag{
private:
    vector <T> v;
public:
    /**
     * @brief constructor por defecto
     */
    Bag(){}
    /**
     * @brief constructor de copia. Crea una copia exacta de otro objeto de tipo Bag
     * @param other Objeto de tipo Bag<T> del que se va a realizar la copia
     */
    Bag(const Bag<T> &other){
        *this=other;
    }

    /**
     * @brief Añade un elemento a la bolsa
     * @param element elemento del tipo T a añadir en la bolsa
     */
    void add(const T & element){
        v.push_back( element);
    }

    /**
     * @brief Extrae un elemento aleatorio de la bolsa. Devuelve un elemento aleatorio de la bolsa y lo elimina de la misma
     * @return Elemento de tipo T extraído de la bolsa
     * @pre la bolsa no está vacía
     * @post El elemento devuelto se ha eliminado de la bolsa
     */
    T get(){


        int a = rand() % v.size(); //genera un numero aleatorio entre 0 y size

        T salida = v.at(a); //function 'at' of vector checks whether n is within the bounds of valid elements in the vector
        v.erase(v.begin() + a);

        return salida;
    }


    /**
     * @brief Elimina todos los elementos de la bolsa. Borra todos los elemento almacenado en la bolsa
     */
    void clear(){
        v.clear();
    }

    /**
     * @brief Tamaño de la bolsa
     * @return Número de elementos que hay en la bolsa
     */
    unsigned int size() const{
        return v.size();
    }

    /**
     * @brief Comprueba si la bolsa está vacía
     * @return true si la bolsa está vacía, flase en caso contrario
     */
    bool empty(){
        return v.empty();
    }

    /**
     * @brief Sobrecarga del operador asignación
     * @param other Bag<T> a copiar
     * @return Referencia a this para poder encadenar el operador
     */
    const Bag <T> & operator = (const Bag<T> & other ){
        this->v = other.v;
        return *this;
    }

    typename vector<T>::iterator begin(){
        return v.begin();
    }

    typename vector<T>::iterator end(){
        return v.end();
    }
};

#endif
