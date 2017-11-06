#include "cronologia.h"
#include "fechahistorica.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

cronologia cronologia::subcronologia(int inicio, int final)
{
	cronologia sub;
	
	for(int i=0;i<fechas.size();i++)
	{
		if(fechas[i].getfecha() >= inicio && fechas[i].getfecha() <= final)
			sub.aniadirfecha(fechas[i]);
	}
	return sub;
} 


vector<fechahistorica> cronologia::getfechas()
{
	return fechas;
}

vector<string> cronologia::getFechas(int f)
{
	vector<string> respuesta;
	for(int i=0;i<fechas.size();i++)
	{
		if(fechas[i].getfecha()==f)
		{
			for(int j=0;j<fechas[i].totaleventos();j++)
			{
				respuesta.push_back(fechas[i].getevento(j));
			}
		}
	} 
	return respuesta;
}

void cronologia::aniadirfecha(fechahistorica& f)
{
	fechas.push_back(f);	
}

void cronologia::eliminarfecha(int fecha)
{
	for(int i=0;i<fechas.size();i++)
	{
		if(fechas[i].getfecha()==fecha)
			fechas.erase(fechas.begin()+i);
	}
}

fechahistorica cronologia::buscarfecha(int fecha)
{
	fechahistorica respuesta;
	
	for(int i=0;i<fechas.size();i++)
	{
		if(fechas[i].getfecha()==fecha)
			return fechas[i];
	}
	
	return respuesta;
}

cronologia cronologia::buscarfecha(const string& f)
{
	cronologia respuesta;
	
	for(int i=0;i<fechas.size();i++)
	{
		for(int j=0;j<fechas[i].totaleventos();j++)
		{
			if(f==fechas[i].getevento(j))
				respuesta.fechas.push_back(fechas[i]);
		}
	}
	return respuesta;
}

cronologia cronologia::operator+(const cronologia& orig)
{
	cronologia suma;
	
	for(int i=0;i<fechas.size();i++)
	{
		suma.fechas.push_back(fechas[i]);
	}
	
	for(int i=0;i<orig.fechas.size();i++)
	{
		suma.fechas.push_back(orig.fechas[i]);
	}
	
	for(int i=0;i<suma.fechas.size()-1;i++)
	{
		for(int j=i+1;j<suma.fechas.size();j++)		//juntar eventos con la misma fecha
		{
			if(suma.fechas[i].getfecha()==suma.fechas[j].getfecha())
			{
				suma.fechas[i] = suma.fechas[i] + suma.fechas[j];
				suma.fechas.erase(suma.fechas.begin()+j);
			}
		}
		
		int aux=i;
		
		for(int j=i+1;j<suma.fechas.size();j++)		//ordenar eventos
		{
			if(suma.fechas[j].getfecha()<suma.fechas[aux].getfecha())
				aux=j;
		}
		
		fechahistorica cambia = suma.fechas[i];
		suma.fechas[i]=suma.fechas[aux];
		suma.fechas[aux]=cambia;
	}	
	return suma;
}

ostream& operator<<(ostream& f, const cronologia& orig)
{
	for(int i=0;i<orig.fechas.size();i++)
	{
			f << orig.fechas[i];
			f << '\n';
	}
	
	return f;
} 

istream& operator>>(istream& f, cronologia& orig)
{
	if(f)
	{
		while(f.peek()!='\0' && !f.eof())
		{
			fechahistorica fec;
			f >> fec;
			orig.fechas.push_back(fec);
		}
	}
	return f;
}




