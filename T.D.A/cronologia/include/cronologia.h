/**
  * @file cronologia.h
  * @brief Fichero cabecera TDA cronologia
  *
  */

#ifndef _CRONOLOGIA_H_
#define _CRONOLOGIA_H_

#include "fechahistorica.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
  *  @brief T.D.A. cronologia
  *
  * Una instancia @e c del tipo de dato abstracto @c cronologia es un objeto 
  * compuesto por un vector de sucesos
  * 
  *  @author Juan Sánchez Rodríguez
  *  @date Octubre 2017 
  */
  

class cronologia
{
	/**
  * @page repConjunto Rep del TDA Cronologia
  */
  
	vector<fechahistorica> fechas; //mod
	
	public:
		
		/**
		* @brief devuelve una cronología entre dos años
		* @param inicio año donde empieza la subcronologia
		* @param final año donde termina la subcronología, este por defecto es el 2017
		* @return cronología entre las fechas dadas
		*/
		cronologia subcronologia(int inicio, int final=2017);
		
		
		/**
		* @brief Devuelve el vector de fechashistoricas
		* @return vector de fechas
		*/
		vector<fechahistorica> getfechas();
		
		
		/**
		* @brief Devuelve el vector con los eventos de la fecha indicada
		* @param f fecha indicada
		* @return vector de los eventos de esa fecha
		*/
		vector<string> getFechas(int f);
		
		
		/**
		* @brief añade una fecha al vector fechas
		* @param f fecha a añadir al vector
		*/
		void aniadirfecha(fechahistorica& f);
		
		
		/**
		* @brief elimina una fecha
		* @param fecha, fecha a eliminar
		*/
		void eliminarfecha(int fecha);
		
		
		/**
		* @brief busca una fechahistorica
		* @param fecha , año que se desea buscar
		* @return fechahistorica buscado
		*/
		fechahistorica buscarfecha(int fecha);
		
		
		/**
		* @brief busca una fechahistorica
		* @param f fecha a buscar
		* @return cronologia con los fechas que tiene el string
		*/
		cronologia buscarfecha(const string& f); 
		
		
		/**
		* @brief suma 2 cronologias
		* @param orig cronologia que va a ser sumada 
		* @return puntero a la cronología sumada
		*/
		cronologia operator+(const cronologia& orig);
		
		
		/**
  		* @brief Salida de un cronologia a ostream
  		* @param f stream de salida
  		* @param orig cronologia a escribir
  		* @return referencia a flujo de escritura
  		*/ 
		friend ostream& operator<<(ostream& f, const cronologia& orig);
		
		
		/**
  		* @brief Entrada de un cronologia desde istream
  		* @param f stream de entrada
 		* @param orig cronologia que recibe los elementos
 		* @return referencia a flujo de lectura
  		*/
		friend istream& operator>>(istream& f, cronologia& orig);
};

#endif
