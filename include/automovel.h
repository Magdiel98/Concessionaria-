#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H


#include "veiculo.h"
#include <string>
using std::string; 


class Automovel : public Veiculo
{
	private: 
		string motor;	//tipo do motor gasolina ou elétrico 
	
	public: 
		//Construtores 
		Automovel();
		Automovel(string _marca, float _preco, string _chassi, int _ano, string _motor);
		
		//Métodos para o atributo motor 
		string getMotor();	
		void setMotor(string _motor);		
		
};


#endif 
