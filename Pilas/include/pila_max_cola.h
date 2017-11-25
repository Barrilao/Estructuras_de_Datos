/**
  * @file pila_max_cola.h
  * @brief Fichero cabecera del TDA Pila_max
  *
  * Gestiona una secuencia de elementos con su máximo
  */
#ifndef __PILA_MAX
#define __PILA_MAX

#include <iostream>
#include <cola.h>

using namespace std;

class Pila_max
{

private:
  /**
    * @brief Rep de pila_max
    *
    * Guardamos los datos en una cola de tipo elemento
    *
    *  @author Juan Sánchez Rodríguez
    *  @date Noviembre 2017 
    */
    Cola<elemento> datos;

public:

    /**
     * @brief Indica si esá vacia la pila
     * @return  true si vacia, false si no
     */
    bool vacia() const
    {
      return datos.vacia();
    }

    /**
     * @brief Añade un elemento al final
     * @param elem Elemento a añadir.
     */
    void poner(int valor);

    /**
     * @brief Quita el elemento del frente de la cola
     */
    void quitar();

    /**
     * @brief Devuelve el número de elementos
     */
    int num_elementos() const
    {
      return datos.num_elementos();
    }

    /**
     * @brief Devuelve el ultimo elemento de la pila
     * @return Un elemento
     */
    elemento tope();

};

#include <pila_max_cola.cpp>

#endif
