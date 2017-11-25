/**
  * @file pila_max_vd.h
  * @brief Fichero cabecera del TDA Pila_max usando un vector dinámico
  *
  * Gestiona una secuencia de elementos con su máximo
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
    *  @author Juan Sánchez Rodríguez
    *  @date Octubre 2017 
    */
    Vector_Dinamico<elemento> datos;

public:

    /**
     * @brief Indica si la pila está vacia
     * @return true si vacia, false si no
     */
    bool vacia() const
    {
      return (datos.size() == 0);
    }

    /**
     * @brief Añade un elemento al final
     * @param elem Elemento a añadir.
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
     * @brief Devuelve el número de elementos
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
