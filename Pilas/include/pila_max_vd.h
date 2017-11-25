/**
  * @file pila_max_vd.h
  * @brief Fichero cabecera del TDA Pila_max usando un vector din�mico
  *
  * Gestiona una secuencia de elementos con su m�ximo
  */
#ifndef __PILA_MAX
#define __PILA_MAX

#include <iostream>
#include <vector_dinamico.h>

using namespace std;

class Pila_max
{

private:
  /**
    * @brief Rep de pila_max
    *
    * Guardamos los datos en un vector_dinamico de tipo elemento
    * 
    * 
    *  @author Juan S�nchez Rodr�guez
    *  @date Octubre 2017 
    */
    Vector_Dinamico<elemento> datos;

public:

    /**
     * @brief Indica si la pila est� vacia
     * @return true si vacia, false si no
     */
    bool vacia() const
    {
      return (datos.size() == 0);
    }

    /**
     * @brief A�ade un elemento al final
     * @param elem Elemento a a�adir.
     */
    void poner(int valor);
    /**
     * @brief Quita el elemento del frente de la cola
     */

    void quitar()
    {
      datos.delete_last();
    };

    /**
     * @brief Devuelve el n�mero de elementos
     */
    int num_elementos() const
    {
      return datos.size();
    }

    /**
     * @brief Devuelve el ultimo elemento de la pila
     * @return Un elemento
     */
    elemento tope();

};

#include <pila_max_vd.cpp>

#endif
