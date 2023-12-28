#ifndef VEICULO_H 
#define VEICULO_H

#include <string>
using std::string; 

class Veiculo
{
	protected: 
		string marca; 
		float preco; 
		string chassi;
		int ano; 

	public:
		Veiculo();
		Veiculo(string _marca, float _preco, string _chassi, int _ano);

		string getMarca();
		void setMarca(string _marca);
	
		float getPreco();
		void setPreco(float _preco);

		string getChassi();
		void setChassi(string _chassi);
		
		int getAno();
		void setAno(int _ano);
};

/*
class Automovel : public Veiculo
{
	private: 
		string motor; 	
};

class Moto : public Veiculo
{
	private: 
		string modelo; 
};

class Caminhao : public Veiculo
{
	private: 
		string carga;  
};
*/


#endif 
