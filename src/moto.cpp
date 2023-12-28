#include "moto.h"
#include <string>
using std::string; 

Moto::Moto()
{
	marca = " ";
	preco = 0; 
	chassi = " ";
	ano = 0; 
	modelo = " ";  
}

Moto::Moto(string _marca, float _preco, string _chassi, int _ano, string _modelo)
{	
	
	marca = _marca; 
	preco = _preco; 
	chassi = _chassi; 
	ano = _ano;
	modelo = _modelo;
}


string Moto::getModelo()
{
	return modelo; 
}

void Moto::setModelo(string _modelo)
{
	modelo = _modelo; 
}

