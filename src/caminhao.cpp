#include "caminhao.h"
#include <string>
using std::string; 


Caminhao::Caminhao()
{
	marca = " ";
	preco = 0; 
	chassi = " "; 
	ano = 0;
	carga = " "; 	
}


Caminhao::Caminhao(string _marca, float _preco, string _chassi, int _ano, string _carga)
{
	marca = _marca;
 	preco = _preco; 
	chassi = _chassi;
	ano = _ano;
	carga = _carga; 
}


string Caminhao::getCarga()
{
	return carga; 
} 

void Caminhao::setCarga(string _carga)
{
	carga = _carga; 
}
