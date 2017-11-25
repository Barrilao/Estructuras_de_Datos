//Juan Sánchez Rodríguez

#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Imprime un conjunto de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: el conjunto con los elementos a imprimi
 * */
template <class T>
ostream & operator<<(ostream & s, const set<T> & c){

  typename set<T>::const_iterator i;
  
  for (i=c.begin(); i != c.end(); i++)
      s << (*i) << " ";
  
  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}

set<int> Union(const set<int> &a, const set<int> &b){
	set<int> resultado;
	set<int>::iterator it;
	
	for(it = a.begin();it!=a.end();++it)
		resultado.insert(*it);
	
	for(it=b.begin();it!=b.end();++it){
		if(!resultado.count(*it))
			resultado.insert(*it);
	}
	return resultado;
}

set<int>  InterseccionDisjunta(const set<int> &a, const set<int> b, const set<int> &c){
	set<int> resultado;
	set<int>::iterator it;
	
	for(it=a.begin();it!=a.end();++it){
		if((!b.count(*it)&&c.count(*it))||(!c.count(*it)&&b.count(*it)))
			resultado.insert(*it);
	}
	
	for(it=b.begin();it!=b.end();++it){
		if(!a.count(*it)&&c.count(*it))
			resultado.insert(*it);
	}
		
	return resultado;
}

int main(){
  set<int> c1;
  set<int> c2;
  set<int> c3;
  
  InicializarSemilla();
  
  for (int i=0;i<10;i++){
    c1.insert(generaEntero(1,100)); //inserta un entero generado aleatoriamente en el rango 1-100
    c2.insert(generaEntero(1,100));
    c3.insert(generaEntero(1,100));
  }
  cout << "PRUEBA DE LABORATORIO-GRUPO 3 ALUMNO: Juan Sanchez Rodriguez " << endl << endl;
  cout << "Conjunto A-> " << c1 << endl;
  cout << "Conjunto B-> " << c2 << endl;
  cout << "Conjunto C-> " << c3 << endl;
  cout << "Union de A, B y C-> " << Union(Union(c1,c2),c3) << endl;
  cout << "Interseccion disjunta de A, B y C-> " << InterseccionDisjunta(c1,c2,c3) << endl;
}  

