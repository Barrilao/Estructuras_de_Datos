/**
  * @file pila_max_cola.h
  * @brief Fichero cabecera del TDA Pila_max
  *
  * Gestiona una secuencia de elementos con su m�ximo
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
    *  @author Juan S�nchez Rodr�guez
    *  @date Noviembre 2017 
    */
    Cola<elemento> datos;

public:

    /**
     * @brief Indica si es� vacia la pila
     * @return  true si vacia, false si no
     */
    bool vacia() const
    {
      return datos.vacia();
    }

    /**
     * @brief A�ade un elemento al final
     * @param elem Elemento a a�adir.
     */
    void poner(int valor);

    /**
     * @brief Quita el elemento del frente de la cola
     */
    void quitar();

    /**
     * @brief Devuelve el n�mero de elementos
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
