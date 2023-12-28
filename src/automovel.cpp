#include "automovel.h"
#include <string>
using std::string; 


Automovel::Automovel()
{
	marca = " ";
	preco = 0; 
    	chassi = " ";
 	ano = 0; 
	motor = " "; 
}


Automovel::Automovel(string _marca, float _preco, string _chassi, int _ano, string _motor)
{	
	marca = _marca; 
	preco = _preco; 
	chassi = _chassi; 
	ano = _ano;
	motor = _motor;
}


string Automovel::getMotor()
{
	return motor; 
}

void Automovel::setMotor(string _motor)
{
	motor = _motor; 
}
