#include "cronologia.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con la cronologia"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   cronologia mi_cronologia;
   f>>mi_cronologia; //Cargamos en memoria la cronolog√≠a.
   
	
   int fecha,anioDesde,anioHasta;
   cout<<"Dime un aÒo a consultar:";
   cin >> fecha;

   vector<string> fechas = mi_cronologia.getFechas(fecha);
   /* Escribimos */
   cout << fecha << ":";
   for (int i=0;i<fechas.size(); ++i)
     cout<<fechas[i]<<';';
     
   cout<<endl;
   cout << "Dime un intervalo de anios para crear una subcronologia: ";
   cin >> anioDesde;
   cin >> anioHasta;
   
   cronologia sub, sub2, sub3;
   
   sub = mi_cronologia.subcronologia(anioDesde, anioHasta);
   cout << "\nSUBCRONOLOGIA PEDIDA:\n" << sub << endl;
   
   cout << "Dime un intervalo de anios para crear una subcronologia2: ";
   cin >> anioDesde;
   cin >> anioHasta;
  
   sub2 = mi_cronologia.subcronologia(anioDesde, anioHasta);
   cout << "\nSUBCRONOLOGIA2:\n" << sub2 << endl;
   
   
   sub3=sub+sub2;

   cout << "\nSUMA:\n" << sub3 << endl;
}
