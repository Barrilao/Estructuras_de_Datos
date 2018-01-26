#include "../include/quienesquien.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>

QuienEsQuien::QuienEsQuien(){
}

QuienEsQuien::QuienEsQuien(const QuienEsQuien &quienEsQuien){
	*this = quienEsQuien;
}

QuienEsQuien& QuienEsQuien::operator= (const QuienEsQuien &quienEsQuien){
	if (this != &quienEsQuien) {
		this->limpiar();
		personajes = quienEsQuien.personajes;
		atributos = quienEsQuien.atributos;
		tablero = quienEsQuien.tablero;
		arbol = quienEsQuien.arbol;
		jugada_actual = quienEsQuien.jugada_actual;
	}
	
	return *this;
}

QuienEsQuien::~QuienEsQuien(){
	this->limpiar();
}

void QuienEsQuien::limpiar(){
	personajes.clear();
	atributos.clear();
	for(auto it = tablero.begin(); it != tablero.end(); ++it)
		it -> clear();
	tablero.clear();
	arbol.clear();
	jugada_actual.remove();
	
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

void QuienEsQuien::mostrar_estructuras_leidas(){
	cout << "personajes: "<< (this->personajes) << endl;
	cout << "atributos:  "<< (this->atributos)  << endl;
	cout << "tablero:    "<< endl;


	// Escribe la cabecera del tablero
	for(vector<string>::iterator it_atributos = this->atributos.begin();
		it_atributos != this->atributos.end();
		it_atributos++){
		cout << *it_atributos << "\t";
	}
	cout <<endl;

	int indice_personaje = 0;
	for(vector<vector<bool>>::iterator it_tablero_atributos = tablero.begin();
		it_tablero_atributos!= tablero.end();
		it_tablero_atributos++){

		string personaje = this->personajes[indice_personaje];
		int indice_atributo = 0;
		for(vector<bool>::iterator it_atributos_personaje = (*it_tablero_atributos).begin();
			it_atributos_personaje != (*it_tablero_atributos).end();
			it_atributos_personaje++){

			cout << *it_atributos_personaje<<"\t";

			indice_atributo++;
		}

		cout << personaje << endl;

		indice_personaje++;
	}


}

/**
  * @brief Devuelve una copia de la cadena original sin las subcadenas no deseadas.
  * 
  * @param cadena_original Cadena de la que se eliminan las subcadenas no deseadas.
  * @param cadena_a_eliminar Subcadena que se busca y se elimina.
  *
  * @return Copia de la cadena original sin las subcadenas no deseadas.
  */
string limpiar_string(string cadena_original,string cadena_a_eliminar){
	string linea(cadena_original);

	while(linea.find_first_of(cadena_a_eliminar) != std::string::npos){
		linea.erase(linea.find_first_of(cadena_a_eliminar),cadena_a_eliminar.length());
	}

	return linea;
}

istream& operator >> (istream& is, QuienEsQuien &quienEsQuien) {
	quienEsQuien.limpiar();
	
  	if(is.good()){
  		string linea;
    	getline(is, linea, '\n');

    	linea = limpiar_string(linea,"\r");
    	
    	while(linea.find('\t') != string::npos ){
    		string atributo = linea.substr(0,linea.find('\t'));
			quienEsQuien.atributos.push_back(atributo);
    		linea = linea.erase(0,linea.find('\t')+1);
    	}

		assert(linea ==  "Nombre personaje");
	}
	
    while( is.good() ) {
    	string linea;
    	getline(is, linea, '\n');
    	linea = limpiar_string(linea,"\r");

    	//Si la linea contiene algo extrae el personaje. Si no lo es, la ignora.
    	if(linea != ""){;
	    	vector<bool> atributos_personaje;
	    	
	    	int indice_atributo=0;
	    	while(linea.find('\t') != string::npos){
	    		string valor = linea.substr(0,linea.find('\t'));
	    		
	    		assert(valor == "0" || valor == "1");
	    		
	    		bool valor_atributo = valor == "1";
	    		
	    		atributos_personaje.push_back(valor_atributo);
				
	    		linea = linea.erase(0,linea.find('\t')+1);
	    		indice_atributo++;
			}
			
			string nombre_personaje = linea;
	    	
	    	quienEsQuien.personajes.push_back(nombre_personaje);
	    	quienEsQuien.tablero.push_back(atributos_personaje);
	    }
  	}
  	
	return is;
}

ostream& operator << (ostream& os, const QuienEsQuien &quienEsQuien){

	//Escribimos la cabecera, que contiene los atributos y al final una columna para el nombre
	for(vector<string>::const_iterator it_atributos = quienEsQuien.atributos.begin();
		it_atributos != quienEsQuien.atributos.end();
		it_atributos++){

		os  << *it_atributos << "\t";
	}
	os << "Nombre personaje" << endl;

	//Rellenamos con ceros y unos cada línea y al final ponemos el nombre del personaje.
	for(int indice_personaje=0;indice_personaje<quienEsQuien.personajes.size();indice_personaje++){
		for(int indice_atributo=0;indice_atributo<quienEsQuien.atributos.size();indice_atributo++){

			os  << quienEsQuien.tablero[indice_personaje][indice_atributo] << "\t";
		}
		os  << quienEsQuien.personajes[indice_personaje] << endl;
	}

	return os;
}

/**
  * @brief Convierte un número a un vector de bool que corresponde 
  *        con su representación en binario con un numero de digitos
  *        fijo.
  *
  * @param n Número a convertir en binario.
  * @param digitos Número de dígitos de la representación binaria.
  *
  * @return Vector de booleanos con la representación en binario de @e n 
  *      con el número de elementos especificado por @e digitos. 

  */
vector<bool> convertir_a_vector_bool(int n, int digitos) {
  vector<bool> ret;
  while(n) {
    if (n&1){
      ret.push_back(true);
    } else{
      ret.push_back(false);
    }
    n>>=1;  
  }

  while(ret.size()<digitos){
  	ret.push_back(false);
  }

  reverse(ret.begin(),ret.end());
  return ret;
}

bintree<Pregunta> QuienEsQuien::crear_arbol()
{	
	vector<bool> personajes_sin_uso;
	vector<bool> atributos_sin_uso;
	int n_personajes = personajes.size();
	
	for(int i = 0; i < n_personajes; i++)
		personajes_sin_uso.push_back(true);
	for(int i = 0;i < atributos.size(); i++)
		atributos_sin_uso.push_back(true);

	Pregunta pregunta_inicial;
	pregunta_inicial.num_personajes=n_personajes;
	pregunta_inicial.personajes_sin_uso=personajes_sin_uso;
	pregunta_inicial.atributos_sin_uso=atributos_sin_uso;
	int atributo_inicial=mejor_atributo(atributos_sin_uso,personajes_sin_uso,n_personajes);
	pregunta_inicial.atributo = atributos[atributo_inicial];

	
	bintree<Pregunta> aux(pregunta_inicial); //no se si está bien
	arbol=aux;
	nodosfr(arbol.root());
	return arbol;
}

//Módulo creado para "crear_arbol" -> asigna información a los nodos

void QuienEsQuien::nodosfr(bintree<Pregunta>::node nodo){
	Pregunta izq, der;
	bintree<Pregunta>::node nodi(izq), nodd(der);
	int izquierda = 0, derecha= 0, suma=0;
	int atrib_seleccionado = mejor_atributo((*nodo).atributos_sin_uso,(*nodo).personajes_sin_uso,(*nodo).num_personajes);
	for(int i=0; i<personajes.size();i++){
		if((*nodo).personajes_sin_uso[i]==1){
			if(tablero[i][atrib_seleccionado]==1)
				izquierda++;
			suma++;
		}
	}

	derecha = suma - izquierda;
	mod_node(nodo, izq, izquierda, true);
	mod_node(nodo, der, derecha, false);
	arbol.insert_left(nodo, izq);
	arbol.insert_right(nodo, der);
	if(izquierda!=1)
		nodosfr(nodo.left());
	if(derecha!=1)
		nodosfr(nodo.right());
	
}

//Modulo creado para poder actualizar los nodos en la función recursiva "nodosfr"

void QuienEsQuien::mod_node(const bintree<Pregunta>::node &nodo, Pregunta &pregunta, const int pos, bool lado){
	pregunta.num_personajes=pos;
	pregunta.personajes_sin_uso.resize((*nodo).personajes_sin_uso.size());
	pregunta.atributos_sin_uso=(*nodo).atributos_sin_uso;
	pregunta.atributos_sin_uso[devolver_pos_atr((*nodo).atributo)]=0;
	pregunta.personajes_sin_uso=(*nodo).personajes_sin_uso;
	for(int i=0;i<((*nodo).personajes_sin_uso).size();i++){
		if((*nodo).personajes_sin_uso[i] == 1){
			if(lado)
				pregunta.personajes_sin_uso[i]=tablero[i][devolver_pos_atr((*nodo).atributo)];
			else
				pregunta.personajes_sin_uso[i]=!tablero[i][devolver_pos_atr((*nodo).atributo)];
		}
	}
	
	if(pos==1){
		int respuesta;
		bool descubierto = false;
		for(int i=0; i<pregunta.personajes_sin_uso.size()&&!descubierto;i++){
			if(pregunta.personajes_sin_uso[i]==1){
				descubierto=true;
				respuesta =i;
			}
		}
		assert(descubierto==true);
		pregunta.atributo = personajes[respuesta];
	}
	else{
		pregunta.atributo = atributos[mejor_atributo(pregunta.atributos_sin_uso,pregunta.personajes_sin_uso,pos)];
	}
			
}

int QuienEsQuien::devolver_pos_atr(string atr){
	int respuesta;
	bool descubierto=false;
	for(int i=0;i<atributos.size()&&!descubierto;i++){
		if(atr == atributos[i]){
			descubierto=true;
		}
	}
	assert(descubierto==true);
	return respuesta;
}

int QuienEsQuien::devolder_pos_per(string per){
	int respuesta;
	bool descubierto=false;
	for(int i=0;i<personajes.size()&&!descubierto;i++){
		if(per == personajes[i]){
			descubierto=true;
			respuesta = i;
		}
	}
	assert(descubierto==true);
	return respuesta;
}



//Módulos "mejor_atributo" y "personajes_con_atributo" creados para obtener el "atributo_inicial"

int QuienEsQuien::mejor_atributo(vector<bool> atrib_sin_uso, vector<bool> personajes_sin_uso, int n){
	int respuesta;
	int numero_personajes=0;
	int tmp=0;
	for(int i = 0; i< atrib_sin_uso.size();i++){
		if(atrib_sin_uso[i]==true){
			numero_personajes=personajes_con_atributo(personajes_sin_uso,i);
			if(numero_personajes>tmp){
				tmp=numero_personajes;
				respuesta=i;
			}
		}
	}
	return respuesta;	
}

int QuienEsQuien::personajes_con_atributo(vector<bool> personajes_sin_uso, int atr){
	int respuesta=0;
	for(int i = 0;i< personajes.size();i++){
		if(personajes_sin_uso[i]&&tablero[i][atr]==1)
			respuesta++;
	}
	return respuesta;
}

void QuienEsQuien::usar_arbol(bintree<Pregunta> arbol_nuevo){
	arbol = arbol_nuevo;
}

void QuienEsQuien::iniciar_juego(){
	cout << "Disfruta de tu partida en el Quien es Quien, version beta " <<endl << endl << endl;
	char opcion=0, querer;
	int menu_cutre = -1;
	bool continuar=true;
	while(continuar){
		jugada_actual = arbol.root();
		while(!(*jugada_actual).es_personaje()){
			cout << "Que quieres hacer?:\n" << "1:Continuar\n" << "2:Información sobre la jugada :D\n";
			cin >> menu_cutre;
			if(menu_cutre==1){
				//no se si está bien
				cout << (*jugada_actual).atributo << "?" << " responder con S/N" << endl;
				do{
					cin >> opcion;
					opcion = toupper(opcion);
				}while(opcion!='S' && opcion !='N'); //terminar
				jugada_actual = opcion =='S' ? jugada_actual.left() : jugada_actual.right();
			}
			else if(menu_cutre == 2){
				set<string> info = informacion_jugada(jugada_actual);
				cout << "\nLos personajes no tumbados son: "<< endl;
				for(auto i= info.begin();i!=info.end();i++)
					cout << *i << endl;
			}
		}
		cout << "Tu personaje es: " << (*jugada_actual).atributo << endl;
		cout << "Deseas volver a jugar? (S/N)" << endl;
		do{
			cin >> querer;
			querer = toupper(querer);
		}while(querer!='S' && querer !='N');
		if(querer == 'S')
			cout << "NEW GAME" << endl << endl;
		else{
			cout << "GAME OVER" << endl << endl;
			continuar = false;
		}
	}
}

set<string> QuienEsQuien::informacion_jugada(bintree<Pregunta>::node jugada_actual){
	
	vector<bool> esta_levantado = (*jugada_actual).personajes_sin_uso;
	set<string> personajes_levantados;
	
	for(int i =0;i<esta_levantado.size();i++){
		if(esta_levantado[i]==1)
			personajes_levantados.insert(personajes[i]);
	}
	return personajes_levantados;
}

void escribir_esquema_arbol(ostream& ss,
					  const bintree<Pregunta>& a, 
		    		  bintree<Pregunta>::node n,
					  string& pre){
	if (n.null()){
	    ss << pre << "-- x" << endl;
	} else {
	    ss << pre << "-- " << (*n) << endl;
	    if ( !n.right().null() || !n.left().null()) {// Si no es una hoja
			pre += "   |";
	    	escribir_esquema_arbol(ss,a, n.right(), pre);
	     	pre.replace(pre.size()-4, 4, "    ");
	      	escribir_esquema_arbol (ss,a, n.left(), pre);
	      	pre.erase(pre.size()-4, 4);    
	    }
  	}
}

void QuienEsQuien::escribir_arbol_completo() const{
	string pre = "";
	escribir_esquema_arbol(cout,this->arbol,this->arbol.root(),pre);
}

void QuienEsQuien::eliminar_nodos_redundantes(){
	bintree<Pregunta>::node nodo;
	bintree<Pregunta>::preorder_iterator p;
	for (p = arbol.begin_preorder(); p != arbol.end_preorder(); ++p){
		if(((p.getElnodo().left()).null() && !(p.getElnodo().right()).null()) || ((p.getElnodo().right()).null() && !(p.getElnodo().left()).null())){
			if((p.getElnodo().left()).null() && !(p.getElnodo().right()).null()){
				nodo = (p.getElnodo().right());
			}else if((p.getElnodo().right()).null() && !(p.getElnodo().left()).null()){
				nodo = (p.getElnodo().left());
			}

			bintree<Pregunta> aux;
			aux.assign_subtree(arbol, nodo);
			
			nodo = nodo.parent();
			if(nodo.parent().right() == nodo){
				nodo = nodo.parent();
				arbol.insert_right(nodo, aux);
			}else{
				nodo = nodo.parent();
				arbol.insert_left(nodo, aux);	
			}
		}
	}
}

float QuienEsQuien::profundidad_promedio_hojas(){
	vector<int> pos;
  	float promedio;
  	BTree::preorder_iterator iter;

  	for (iter = arbol.begin_preorder(); iter != arbol.end_preorder(); ++iter) {
    	if ((*iter).es_personaje()) {
      		BTree::node nodo_actual = iter.getElnodo();
      		int nivel = 0;

      		while (!nodo_actual.null()) {
        		nivel++;
        		nodo_actual = nodo_actual.parent();
      		}

      		pos.push_back(nivel);
    	}
	}

  	promedio = accumulate(pos.begin(), pos.end(), 0.0);
  	promedio /= pos.size();
    return promedio;

}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max).
**/

int generaEntero(int min, int max){
    int tam= max -min;
    return ((rand()%tam)+min);
}

void QuienEsQuien::tablero_aleatorio(int numero_de_personajes){
	srand(0);

	this->limpiar();

	float log_2_numero_de_personajes = log(numero_de_personajes)/log(2);

	int numero_de_atributos = ceil(log_2_numero_de_personajes);

	cout << "Petición para generar "<< numero_de_personajes<<" personajes ";
	cout << "con "<<numero_de_atributos<< " atributos"<<endl;
	cout << "Paso 1: generar "<< pow(2,numero_de_atributos) << " personajes"<<endl;

	//Fase 1: completar el tablero con todos los personajes posibles
	//Completo el tablero y los nombres de personajes a la vez
	for(int indice_personaje=0;indice_personaje< pow(2,numero_de_atributos);indice_personaje++){
		vector<bool> atributos_personaje = convertir_a_vector_bool(indice_personaje,numero_de_atributos);
		string nombre_personaje = "Personaje_"+to_string(indice_personaje);

		this->personajes.push_back(nombre_personaje);
		this->tablero.push_back(atributos_personaje);
	}

	// Completo los nombres de los atributos.
	for(int indice_atributo=0;indice_atributo<numero_de_atributos;indice_atributo++){
		string nombre_atributo = "Atr_"+to_string(indice_atributo);
		this->atributos.push_back(nombre_atributo);
	}

	cout << "Paso 2: eliminar "<< (pow(2,numero_de_atributos)-numero_de_personajes) << " personajes"<<endl;
	//Fase 2. Borrar personajes aleatoriamente hasta que quedan solo los que hemos pedido.
	while(personajes.size()>numero_de_personajes){
		int personaje_a_eliminar = generaEntero(0,personajes.size());

		personajes.erase(personajes.begin()+personaje_a_eliminar);
		tablero.erase(tablero.begin()+personaje_a_eliminar);
	}
}
