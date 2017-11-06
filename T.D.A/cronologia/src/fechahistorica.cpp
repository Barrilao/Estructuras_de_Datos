#include "fechahistorica.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

fechahistorica::fechahistorica():fecha(0)
{}

fechahistorica::fechahistorica(int fec, vector<string>& eve)
{
	fecha = fec;
	eventos = eve;
} 

fechahistorica::~fechahistorica()
{
	fecha = 0;
	//el vector se destruye automaticamente
}

fechahistorica::fechahistorica(const fechahistorica& orig)
{
	fecha = orig.fecha;
	eventos = orig.eventos;
}

fechahistorica& fechahistorica::operator=(const fechahistorica& orig)
{
	if(this != &orig)
	{
		fecha = orig.fecha;
		eventos = orig.eventos;
	}
	
	return *this;
}

fechahistorica& fechahistorica::operator+(const fechahistorica& orig)	//mod
{
	if(fecha == orig.fecha)
	{
		for(int i=0;i<orig.eventos.size();i++)
		{
			eventos.push_back(orig.eventos[i]);
		}	
	}
	
	return *this;
}

bool fechahistorica::operator==(const fechahistorica& orig)
{
	if(fecha == orig.fecha && eventos== orig.eventos)
		return true;
	else
		return false;
}

bool fechahistorica::operator<(const fechahistorica& orig)
{
	if(fecha<orig.fecha)
		return true;
	else
		return false;
}

bool fechahistorica::operator>(const fechahistorica& orig)
{
	if(fecha>orig.fecha)
		return true;
	else
		return false;
}

int fechahistorica::getfecha()
{
	return fecha;
}

string& fechahistorica::getevento(int n)
{
	return eventos.at(n);
}

int fechahistorica::totaleventos()
{
	return eventos.size();
}

void fechahistorica::insertarevento(string eve)
{
	eventos.push_back(eve);
}

void fechahistorica::eliminarevento(int n)
{
	eventos.erase(eventos.begin()+n);
}

bool fechahistorica::eliminarevento(const string& eve)
{
	for(int i=0;i<eventos.size();i++)
	{
		if(eventos[i]==eve)
		{
			eventos.erase(eventos.begin()+i);
			return true;
		}
	}
	return false;
}

ostream& operator<<(ostream& f, const fechahistorica& orig)
{
	f << orig.fecha;
	for(int i=0;i<orig.eventos.size();i++)
		f << '#' << orig.eventos[i];
	
	return f;
}

istream& operator>>(istream& f, fechahistorica& orig)
{
	if(f)
	{
		f >> orig.fecha;
		
		string cadena;
		bool primera_vuelta = true;
		
		while(f.peek()!='\n'&& !f.eof()	)
		{
			if(f.peek()=='#' && !primera_vuelta)
			{
				f.ignore();
				orig.eventos.push_back(cadena);
				cadena='\0'; //vaciar cadena
			}
			
			else
			{
				if(f.peek()!='#')
				{
					cadena.push_back(f.get());
					primera_vuelta=false;
				}
				
				else
					f.ignore();
				
			}
		}
		orig.eventos.push_back(cadena);
	}
	return f;
} 

