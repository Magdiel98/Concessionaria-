#ifndef SISTEMA_H
#define SISTEMA_H
#include "concessionaria.h"
#include <vector>
#include <string>
#include <iostream>

// Sistema deve concentrar todas as operações
class Sistema {
  private:
		int cont = 0;  		 
		std::vector<Concessionaria> concessionarias; //um vetor com todos as concessionarias
  public:

		/*Encerra o funcionamento do programa.
			@return uma string com a mensagem "Saindo.."
		*/
		std::string quit();

		/* Cria uma concessionaria e retorna uma string de erro/sucesso 
			@param nome o nome da concessionaria
			@return uma string contendo uma mensagem de erro ou "Concessionaria Criada"
		*/

		//Métodos usados para funções de acordo com os comandos enviados pelo usuário. 
		std::string create_concessionaria (const std::string nome);
		std::string add_car (const std::string nome);
		std::string add_truck (const std::string nome);
		std::string add_moto (const std::string nome);
		std::string remove_vehicle(const std::string nome); 
		std::string search_vehicle(const std::string nome);
		std::string list_concessionaria(const std::string nome);  
		std::string raise_price(const std::string nome);	     
  
                int Posicao(string conc); //Posicao da concessionaria
  					  // encontrada	
};

#endif
