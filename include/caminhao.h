#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "veiculo.h"
#include <string>
using std::string; 

class Caminhao : public Veiculo
{
	private: 
		string carga; //Tipo de carga comum ou perigosa

	public: 
		Caminhao();
		Caminhao(string _marca, float _preco, string _chassi, int _ano, string _carga);

		string getCarga();
		void setCarga(string _carga); 

};

#endif 



