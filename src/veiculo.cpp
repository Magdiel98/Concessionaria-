#include "veiculo.h"
#include <string>
using std::string;


Veiculo::Veiculo()
{
	marca = " "; 
	preco = 0; 
	chassi = " "; 
	ano = 0; 
}

Veiculo::Veiculo(string _marca, float _preco, string _chassi, int _ano)
{
	marca = _marca; 
	preco = _preco;
	chassi = _chassi;
	ano = _ano; 
}




string Veiculo::getMarca()
{
	return marca; 	
}

void Veiculo::setMarca(string _marca)
{
	marca = _marca; 
}





float Veiculo::getPreco()
{
	return preco; 
}


void Veiculo::setPreco(float _preco)
{
	preco = _preco; 
}





string Veiculo::getChassi()
{
	return chassi; 
}

void Veiculo::setChassi(string _chassi)
{
	chassi = _chassi; 
}




int Veiculo::getAno()
{
	return ano; 
}

void Veiculo::setAno(int _ano)
{
	ano = _ano; 
}
