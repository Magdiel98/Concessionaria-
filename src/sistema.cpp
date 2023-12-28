#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;
  

/* COMANDOS */
string Sistema::quit() {
  return "\e[31;5mSaindo...\e[0m";
}

//Cria concessionária 
string Sistema::create_concessionaria (const string nome) {
  
  int num; //numero para percorrer a lista
   
  istringstream con(nome); //Armazena o restante da linha em nome 

  string no; //Nome da concessionaria 
  string cn; //CNPJ da concessionaria 
  int est; 	//Quantidade em estoque 

 

  con >> no >> cn >> est; //Distribuição de cada parte da string para as 
			// variáveis

     
  Concessionaria c(no, cn, est); 
  
  concessionarias.push_back(c); 
  
  cont++; //incremento da quantidade de concessionárias para ajudar na busca.   
 
  return "Concessionária criada";
}


//Adicionada carro a uma concessionaria 
string Sistema::add_car (const string nome) {   
  
  string concessionaria;  
  string marca; 
  double preco; 
  string chassi; 
  int ano; 
  string motor; //gasolina ou elétrico

  istringstream cr(nome); 
  
  cr >> concessionaria;  
  cr >> marca; 
  cr >> preco; 
  cr >> chassi; 
  cr >> ano; 
  cr >> motor;
   
  int valor = Posicao(concessionaria); //Devolve a posicao da concessionaria se existir 
 
  int ch = 0;

  //Pesquisa se já existe o chassi 
  if(valor != -1){
	  if(concessionarias[valor].getAut() > 0)
	  {
		ch = concessionarias[valor].Pesquisa(chassi); 
	  }   
  } 
	

  //Para adicionar automovel
  if(valor != -1){
     if(ch == 0){
  	concessionarias[valor].setAutomovel(marca, preco, chassi, ano, motor); 
	concessionarias[valor].setAut(); //Implementa a quantidade de automóveis     
 	concessionarias[valor].setEstoque(); //Implementa a quantidade de veículos 
       	return "Veículo adicionado";
      }       
      return "ERRO - Veículo " + chassi + " já adicionado à concessionária " + concessionaria;
  } 
        	 
  
     
  
  return "Concessionária não encontrada!";  
}



//Adiciona caminhão a uma concessionária 
string Sistema::add_truck (const string nome) {
    
  string concessionaria;  
  string marca; 
  double preco; 
  string chassi; 
  int ano; 
  string carga; //comum ou perigosa 

  istringstream tr(nome); 
  
  tr >> concessionaria;  
  tr >> marca; 
  tr >> preco; 
  tr >> chassi; 
  tr >> ano; 
  tr >> carga; 

 
  int valor = Posicao(concessionaria); //Devolve a posicao da concessionaria
			 	       //Primeira posicao e zero
  int ch = 0;
   
  if(valor != -1){
	  if(concessionarias[valor].getCm() > 0)
	  {
		ch = concessionarias[valor].Pesquisa(chassi); 
	  }   
  }

  //Adicionar caminhao 
  
  if(valor != -1){
    if(ch == 0){
  	concessionarias[valor].setCaminhao(marca, preco, chassi, ano, carga); 
	concessionarias[valor].setCm();
	concessionarias[valor].setEstoque();
   	return "Veículo adicionado";
    }

	return "ERRO - Veículo " + chassi + " já adicionado à concessionária " + concessionaria;  
  }
 
   return "Concessionária não encontrada!";
}


//Adiciona moto a uma concessionária 
string Sistema::add_moto (const string nome) {
  
  string concessionaria;  
  string marca; 
  double preco; 
  string chassi; 
  int ano; 
  string modelo; //classico ou esportivo 

  istringstream mt(nome); 
  
  mt >> concessionaria;  
  mt >> marca; 
  mt >> preco; 
  mt >> chassi; 
  mt >> ano; 
  mt >> modelo; //classico ou esportivo

  	
   
  int valor = Posicao(concessionaria); //Devolve a posicao da concessionaria
			 	       //Primeira posicao e zero
  int ch = 0; 
  if(valor != -1){
	  if(concessionarias[valor].getMt() > 0)
	  {
		ch = concessionarias[valor].Pesquisa(chassi); 
	  }   
  } 

  //Adicionar moto

  if(valor != -1)
  {
    if(ch == 0){
  	concessionarias[valor].setMoto(marca, preco, chassi, ano, modelo);
	concessionarias[valor].setMt();
 	concessionarias[valor].setEstoque();      
    	return "Veículo adicionado";
    } 
	
	 return "ERRO - Veículo " + chassi + " já adicionado à concessionária " + concessionaria;
  }

  return "Concessionária não encontrada!";	 
}


//Remove veículo de uma concessionária 
string Sistema::remove_vehicle(const string nome){
 
   //Armazenar o chassi 
   string chassi; 

   istringstream sv(nome); 

   sv >> chassi;
 
   int num, valor; 
   
   //Passar por cada concessionaria para procurar chassi		
   if(cont > 0)
   {
	for(num = 0; num < cont; num++)
	{
		valor = concessionarias[num].Remover(chassi); //Procurar por chassi e remover  
		if(valor == 1)
		{
		   return "Veículo " + chassi + " removido da concessionária " + concessionarias[num].getNome();
		} 
  	}
   } 

      	

   return "Veículo não encontrado";
}


//Pesquisa e imprime veiculo na tela através do chassi
string Sistema::search_vehicle(const string nome){
    
    string chassi;

    istringstream sv(nome);
    sv >> chassi; 

    int num;
    string detalhe; 

    if(cont > 0)
    {
    	for(num = 0; num < cont; num++)
	{
		detalhe = concessionarias[num].Detalhes(chassi);
		if(detalhe != "Veículo não encontrado")
		{
			return detalhe;
		}
	}
    }			
	return "Veículo não encontrado"; 
}


//Lista os veículos de uma concessionária  
string Sistema::list_concessionaria(const string nome)
{
	string concessionaria; 
	
	istringstream li(nome);
	
	li >> concessionaria; 
	
	int valor = Posicao(concessionaria); 
	
	if(valor != -1)
	{
	  return "Total de Automóveis: " + to_string(concessionarias[valor].getAut()) + "; Valor total: R$ " + to_string(concessionarias[valor].getApr()) + "\n" + "Total de Motos: " + to_string(concessionarias[valor].getMt()) + "; Valor total: R$ " + to_string(concessionarias[valor].getMpr()) + "\n" + "Total de Caminhões: " + to_string(concessionarias[valor].getCm()) + "; Valor total: R$ " + to_string(concessionarias[valor].getCpr()) + "\n" + "Valor Total da frota: R$ " + to_string(concessionarias[valor].getVge());    
	}
	 
	return "Concessionária não encontrada"; 
}


//Faz ou não o aumento do preço dos veículos de uma concessionária 
string Sistema::raise_price(const string nome)
{
    string concessionaria; 
    float aumento;     

    istringstream rp(nome); 
	
    rp >> concessionaria; 
    rp >> aumento; 
  
    int valor = Posicao(concessionaria);

    string total;
 	
    if(valor != -1)
    {
	  return total = concessionarias[valor].Aumento(aumento);	
    }



   return "Concessionária não encontrada";    

}

//Posicao da concessionaria encontrada

int Sistema::Posicao(string conc)
{        
      int num;
      if(cont > 0){ 
	for(num = 0; num < cont; num++)
	{
	  if(concessionarias[num].getNome() == conc)
		return num; 
	}
      } 
	return -1; 
}


/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
