#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H 

#include <string>
#include <vector>
#include <algorithm>
#include "automovel.h"
#include "moto.h"
#include "caminhao.h"
using std::string; 
using std::find;
using std::distance; 
class Concessionaria
{	
	//atributos da concessionaria; 
	private: 
		string nome; //Nome da concessionária  
		string cnpj; //Cnpj 
		int aut = 0; //Quantidade de automoveis adicionados
		int cm = 0;  //Quantidade de caminhões
		int mt = 0;  //Quantidade de motos 
		int estoque; 

		float ap = 0; //Valor geral dos automoveis adicionados 
		float cp = 0; //Valor geral  dos caminhões adicionados 
		float mp = 0; //Valor geral das motos adicionadas 

		float vp = 0; //Valor geral dos veículos adicionados 
		

 		//Vector de cada veículo 
		std::vector<Automovel> car; 		  		                
		std::vector<Moto> moto; 
		std::vector<Caminhao> truck; 		

	public: 
		//Construtores 
		Concessionaria();
		Concessionaria(string _nome, string _cnpj, int _estoque);
		
		//Para colocar e capturar valores dos atributos 
		string getNome(); //nome da concessionaria
		void setNome(string _nome);

		string getCnpj();
		void setCnpj(string _cnpj);

		int getEstoque();
		void setEstoque();

		//Faz atribuição do Carro   	
		void setAutomovel(string _marca, float _preco, string _chassi, int _ano, string _motor);
	   
		//Atribuição da Moto 
		void setMoto(string _marca, float _preco, string _chassi, int _ano, string _modelo);
	   
		//Atribuição do Caminhao
		void setCaminhao(string _marca, float _preco, string _chassi, int _ano, string _Carga);
		
		//Incremento e busca da quantidade de cada automóvel quando for adicionado na 
		//concessionária 
		void setAut(); 
		int getAut();
		
		void setMt();
		int getMt();
		
		void setCm();
		int getCm();

	    
                //Valor geral de cada veículo  
		float getApr();	

		float getMpr();

		float getCpr(); 
                
		//Valor geral dos veículos 
		float getVge();
	
		

		//Para encontrar o veiculo 
		int Pesquisa(string _chassi); 

		//Remover veiculo 
		int Remover(string _chassi);

		//Para devolver detalhes do veículo 
		string Detalhes(string _chassi); 

		//Para fazer aumento dos valores na concessionária 
		string Aumento(float _aumento);
		 		
};  

#endif 
