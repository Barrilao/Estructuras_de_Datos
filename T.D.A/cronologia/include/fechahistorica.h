/**
  * @file fechahistorica.h
  * @brief Fichero cabecera TDA fechahistorica
  *
  */

#ifndef _FECHAHISTORICA_H_
#define _FECHAHISTORICA_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
  *  @brief T.D.A. fechahistorica
  *
  * Una instancia @e c del tipo de dato abstracto @c fechahistorica es un objeto 
  * compuesto por un entero fecha que representa la fecha del evento y un vector
  * string que representa los eventos de la susodicha fecha
  * 
  *  @author Juan Sánchez Rodríguez
  *  @date Octubre 2017 
  */


class fechahistorica
{
	/**
  * @page repConjunto Rep del TDA fechahistorica
  */

	int fecha;
	vector<string> eventos;
	
	public:
		
		/**
		* @brief Constructor por defecto de la clase
		*/
		fechahistorica();
		
		
		/**
		* @brief Constructor de la clase
		* @param fec año del evento
		* @param eve evento a crear
		*/
		fechahistorica(int fec, vector<string>& eve);
		
		
		/**
		* @brief Destructor de la clase
		*/
		~fechahistorica();
		
		
		/**
		* @brief Constructor copia de la clase
		* @param orig fechahistorica a copiar
		*/
		fechahistorica(const fechahistorica& orig);
		
	
		/**
		* @brief Operador asignación de la clase
		* @param orig fechahistorica a asignar
		* @return referencia a la fechahistorica asignada
		*/
		fechahistorica& operator=(const fechahistorica& orig);
		
		
		/**
  		* @brief Operador + de la clase
  		* @param orig fechahistorica a sumar
  		* @return una fechahistorica resultado de la suma
  		*/
		fechahistorica& operator+(const fechahistorica& orig);
		
		
		/**
		* @brief Comprueba si dos fechashistoricas son iguales
		* @param orig fechahistorica a comparar
		* @return 1 iguales, 0 no iguales
		*/
		bool operator==(const fechahistorica& orig);
		
		
		/**
		* @brief Comprueba si una fechahistorica es menos reciente que otra
		* @param orig fechahistorica a comparar
		* @return 1 si es menos reciente, 0 si no
		*/
		bool operator<(const fechahistorica& orig);
		
		
		/**
		* @brief Comprueba si una fechahistorica es más reciente que otra
		* @param orig fechahistorica a comparar
		* @return 1 si es más reciente, 0 si no
		*/
		bool operator>(const fechahistorica& orig);
		
		
		/**
		* @brief Consulta fecha
		* @return fecha
		*/
		int getfecha();
		
		
		/**
		* @brief Consulta de un evento
		* @param n posicion del evento en el vector
		* @pre n debe ser mayor o igual a 1
		* @return string con el evento
		*/
		string& getevento(int n);
		
		
		/**
 	 	* @brief Devuelve cuantos eventos hay en una fechahistorica
 	 	* @return Número de eventos en una determinada fecha
  		*/
		int totaleventos();
		
		
		/**
		* @brief Inserta un eventi
		* @param eve evento a insertar
		*/
		void insertarevento(string eve);
		
		
		/**
		* @brief Elimina un evento de una fechahistorica
		* @param n posición del evento en el vector
		* @pre n tiene que ser mayor o igual a 1
		*/
		void eliminarevento(int n);
		
		
		/**
		* @brief Elimina un evento de una fechahistorica
		* @param eve evento a eliminar
		* @return si ha eliminado el evento
		*/
		bool eliminarevento(const string& eve);	
		
		
		/**
  		* @brief Salida de un fechahistorica a ostream
  		* @param f stream de salida
  		* @param orig fechahistorica a escribir
  		* @return referencia a flujo de escritura
  		*/ 
		friend ostream& operator<<(ostream& f, const fechahistorica& orig);
		
		
		/**
  		* @brief Entrada de un fechahistorica desde istream
  		* @param f stream de entrada
 		* @param orig ConjuntoFrases que recibe los elementos
 		* @return referencia a flujo de lectura
  		*/
		friend istream& operator>>(istream& f, fechahistorica& orig);
};

#endif

