#ifndef MOTO_H
#define MOTO_H

#include "veiculo.h"
#include <string>
using std::string; 


class Moto : public Veiculo
{
	private: 
		string modelo; //modelo clássico ou esportivo

	public:
		Moto();
		Moto(string _marca, float _preco, string _chassi, int _ano, string _modelo);

		string getModelo();
		void setModelo(string _modelo); 
};


#endif 
