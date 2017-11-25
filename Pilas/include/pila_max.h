using namespace std;

/**
 * @brief TDA Elemento
 *
 * Es un contenedor donde almacenaremos los valores a agregar a la pila
 * tiene 2 variables ele, el elemento entero y maximo, el valor maximo introducido
 *
 *  @author Juan Sánchez Rodríguez
 *  @date Octubre 2017 
 */
struct elemento
{
    int ele;    
    int maximo; 

    /**
     * @brief Sobrecarga del operador <<
     *
     * @param os stream de salida
     * @param e elemento
     * @return la instancia oss del ostream
     */
    friend ostream& operator<<(ostream &os, const  elemento& e)
    {
    	os << e.ele << " (" << e.maximo << ")" << endl;

    	return os;

    };
};


#define CUAL_COMPILA 1
#if CUAL_COMPILA==1
	#include <pila_max_vd.h>
#else
	#include <pila_max_cola.h>
#endif
