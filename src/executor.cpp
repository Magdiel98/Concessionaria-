#include "executor.h"
#include <istream>
#include <ostream>
#include <iostream>
#include <sstream>
#include <queue>
#include <string>


using namespace std;

// Função de apoio que recebe um istringstream e
// le todo texto restante até o fim da linha
string restoDe(istringstream &ss) {
  string resto;
  getline(ss, resto, '\0'); // ler o resto da linha
  if (resto != "" && (resto[0] == ' ' || resto[0] == '\t')) {
    resto = resto.substr(1); // o primeiro caractere é um espaço, descartar
  }
  return resto;
}

// Construtor. Recebe uma referência ao sistema que vai operar
// Guarda o seu endereço para executar as operações.
Executor::Executor(Sistema &sistema) {
  this->sair = false;
  this->sistema = &sistema;
}

// Inicia o processamento dos comentarios.
// Esse método recebe por exemplo o "cin" e o "cout" no main
// Dessa forma ele faz o necessário para ler 1 comando por linha e
// o processar corretamente, colocando no stream de saída o resultado de cada um.
void Executor::iniciar(istream &inputStream, ostream &outputStream) {
  string linha, saida;
  this->sair = false;
  while (! this->sair)
  { menuPrincipal();
    if (std::getline(inputStream, linha)) {
      saida = processarLinha(linha);
      outputStream << saida << endl;
      cin.get();//Pausar o terminal esperando uma tecla 
      system("clear"); //Limpa o terminal 
    }
  }
}

// Método responsável por processar cada linha, capturando o nome do comando
// e seus parâmetros em variáveis e executar o método correspondente no sistema
string Executor::processarLinha(string linha) {
  istringstream buf(linha);
  string nomeComando;
  buf >> nomeComando;
   

  if (nomeComando.empty()) {
    return "Comando Inválido <vazio>";
  }

  if (nomeComando == "quit" ) {
    this->sair = true;
    return sistema->quit();
  }
  else if (nomeComando == "create-concessionaria") {
    string nome;    
    nome = restoDe(buf);
    return sistema->create_concessionaria(nome);
  }
  else if(nomeComando == "add-car")
  {
    string nome; 
    nome = restoDe(buf);
    return sistema->add_car(nome); 
  }
  else if(nomeComando == "add-truck")
  {
    string nome; 
    nome = restoDe(buf);	
    return sistema->add_truck(nome); 		
  }
  else if(nomeComando == "add-moto")
  {
    string nome; 
    nome = restoDe(buf);
    return sistema->add_moto(nome);
  }
  else if(nomeComando == "remove-vehicle")
  {
    string nome; 
    nome = restoDe(buf);
    return sistema->remove_vehicle(nome); 
  }
  else if(nomeComando == "search-vehicle")
  {
    string nome; 
    nome = restoDe(buf);
    return sistema->search_vehicle(nome); 
  }
  else if(nomeComando == "list-concessionaria")
  {
    string nome; 
    nome = restoDe(buf);
    return sistema->list_concessionaria(nome); 
  }
  else if(nomeComando == "raise-price")
  {
    string nome; 
    nome = restoDe(buf);
    return sistema->raise_price(nome);
  
  }

  return "\e[31;1mErro\e[0m";	
}

void Executor::menuPrincipal() 
{            
	 cout<< endl
	     << "\e[33;1m---------------------------" << endl	
	     << "Bem-Vindo ao Menu Principal" << endl 
	     << "---------------------------\e[0m" << endl << endl 
	     << "\e[32;1mComandos: \e[0m"<< endl 
             << "\e[37;1m1 - Criar concessionaria: create-concessionaria;\e[0m" << endl
	     << "\e[33;1m(Ex.: create-concessionaria  Nome da concessionária  CNPJ  Quantidade de veículos)\e[0m" << endl << endl 
	     << "\e[37;1m2 - Adicionar Carro: add-car;\e[0m" << endl 
	     << "\e[33;1m(Ex.: add-car  Nome da concessionária  Marca  Preço  Chassi  Ano  Motor(gasolina ou elétrico))\e[0m" << endl << endl 
	     << "\e[37;1m3 - Adicionar Caminhão: add-truck;\e[0m" << endl
             << "\e[33;1m(Ex.: add-truck  Nome da concessionária  Marca  Preço  Chassi  Ano  Carga(comum ou perigosa))\e[0m" << endl << endl
	     << "\e[37;1m4 - Adicionar Moto: add-moto;\e[0m" << endl 
	     << "\e[33;1m(Ex.: add-moto  Nome da concessionária  Marca  Preço  Chassi  Ano  Modelo(clássico ou esportivo))\e[0m" << endl << endl
	     << "\e[37;1m5 - Remover Veículo: remove-vehicle.\e[0m" << endl
	     << "\e[33;1m(Ex.: remove-vehicle Chassi)\e[0m" << endl << endl
	     << "\e[37;1m6 - Procurar Veículo: search-vehicle.\e[0m" << endl
	     << "\e[33;1m(Ex.: search-vehicle Chassi)\e[0m" << endl << endl
	     << "\e[37;1m7 - Listar Veículos: list-concessionaria.\e[0m" << endl
	     << "\e[33;1m(Ex.: list-concessionaria Concessionária)\e[0m" << endl << endl
	     << "\e[37;1m8 - Aumentar Preço: raise-price.\e[0m" << endl
	     << "\e[33;1m(Ex.: raise-price Concessionária Porcentagem)\e[0m" << endl << endl
	     << "\e[37;1m9 - Finalizar programa: quit\e[0m." << endl << endl
	     << "\e[36;1mDigite o comando: \e[0m" << endl;    	
	    	 
}

