#include "concessionaria.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std; 

//Construtores 
Concessionaria::Concessionaria()
{
	nome = " "; 
	cnpj = " "; 
	estoque = 0; 
}

Concessionaria::Concessionaria(string _nome, string _cnpj, int _estoque)
{
	nome = _nome; 
	cnpj = _cnpj;
	estoque = _estoque; 
}


//Retorna o nome da concessionária 

string Concessionaria::getNome()
{
	return nome; 
}

//Atribui o nome de uma concessionária 

void Concessionaria::setNome(string _nome)
{
	nome = _nome; 
}


//Retorna o Cnpj 
string Concessionaria::getCnpj()
{
	return cnpj; 
}


//Atribui o Cnpj 
void Concessionaria::setCnpj(string _cnpj)
{
	cnpj = _cnpj; 
}



//Retorna a quantidade de veículos no estoque 
int Concessionaria::getEstoque()
{
	return estoque; 
}


//Acrescenta a quantidade de veículos no estoque 
void Concessionaria::setEstoque()
{
	estoque++; 
}



//Atribuição dos valores de Automóvel, Moto e Caminhão 
void Concessionaria::setAutomovel(string _marca, float _preco, string _chassi, int _ano, string _motor)
{
	Automovel a(_marca, _preco, _chassi, _ano, _motor);
	car.push_back(a);
	ap += _preco; //Para adicionar o valor total de automóveis  
	vp += _preco; //Valor total de veículos 
}

void Concessionaria::setMoto(string _marca, float _preco, string _chassi, int _ano, string _modelo)
{
	Moto m(_marca, _preco, _chassi, _ano, _modelo); 
	moto.push_back(m);
	mp += _preco; //Para adicionar o valor total de motos 
	vp += _preco; //Valor total de veículos 	
}

void Concessionaria::setCaminhao(string _marca, float _preco, string _chassi, int _ano, string _carga)
{
	Caminhao t(_marca, _preco, _chassi, _ano, _carga);
	truck.push_back(t);
	cp += _preco; //Adicionar valor total de caminhões 
	vp += _preco; //Valor total de veículos 	
}


//Incrementa a quantidade dos veículos e retorna a quantidade  
int Concessionaria::getAut()
{
	return aut;	
}

void Concessionaria::setAut()
{
	aut++; 
}

int Concessionaria::getMt()
{
	return mt;	
}

void Concessionaria::setMt()
{
	mt++; 
}

int Concessionaria::getCm()
{
	return cm;	
}

void Concessionaria::setCm()
{
	cm++; 
}



//Valor geral de Automóveis de uma concessionária 
float Concessionaria::getApr()
{
	return ap; 
}


//Valor geral de Caminhões de uma concessionária 
float Concessionaria::getCpr()
{
	return cp;
}


//Valor geral de Motos de uma concessionária 
float Concessionaria::getMpr()
{
	return mp; 
}


//Valor geral de todos os veículos de uma concessionária  
float Concessionaria::getVge()
{
	return vp;
}



//Procurar por chassi e devolver resultado com inteiro
int Concessionaria::Pesquisa(string _chassi)
{
	int num; 
	for(num = 0; num < aut; num++)
	{
		if(car[num].getChassi() == _chassi)
			return 1; //Se já estiver na lista 
	}
	
	for(num = 0; num < cm; num++)
	{
		if(truck[num].getChassi() == _chassi)
			return 1; //Se já estiver na lista 
	} 

	for(num = 0; num < mt; num++)
	{
		if(moto[num].getChassi() == _chassi)
			return 1; //Se já estiver na lista 
	} 

	return 0; //Se não estiver na lista 
}


//Método para procurar e remover veículo 

int Concessionaria::Remover(string _chassi)
{	
	int num; 
	if(aut > 0 )
	{
		for(num = 0; num < aut; num++)
		{
			if(car[num].getChassi() == _chassi)
			{       car.erase(car.begin() + num); //Remover veículo
				aut--; //subtrai a quantidade de automóveis
				estoque--; 
				return 1; 	
			}
		}
	}

	if(cm > 0 )
	{
		for(num = 0; num < cm; num++)
		{
			if(truck[num].getChassi() == _chassi)
			{       truck.erase(truck.begin() + num);
				cm--;   //subtrai a quantidade de caminhões
				estoque--;
				return 1; 	
			}
		}
	}
		
	if(mt > 0 )
	{
		for(num = 0; num < mt; num++)
		{
			if(moto[num].getChassi() == _chassi)
			{       moto.erase(moto.begin() + num);
				mt--; //subtrai a quantidade de motos
				estoque--;
				return 1; 	
			}
		}
	}
	

	return 0; 
}



//Procura por veículo e devolve string: 
string Concessionaria::Detalhes(string _chassi)
{
	int num;
	
	for(num = 0; num < aut; num++)
	{
		if(car[num].getChassi() == _chassi)
			return "Concessionaria: " + getNome() + "\nMarca: " + car[num].getMarca() + "\nPreço: " + to_string(car[num].getPreco()) + "\nChassi: " + car[num].getChassi() + "\nAno: " + to_string(car[num].getAno()) + "\nTipo de motor: " + car[num].getMotor(); 
	}
	
	for(num = 0; num < cm; num++)
	{
		if(truck[num].getChassi() == _chassi)
			return "Concessionaria: " + getNome() + "\nMarca: " + truck[num].getMarca() + "\nPreço: " + to_string(truck[num].getPreco()) + "\nChassi: " + truck[num].getChassi() + "\nAno: " + to_string(truck[num].getAno()) + "\nTipo de motor: " + truck[num].getCarga(); 
	}

	for(num = 0; num < mt; num++)
	{
		if(moto[num].getChassi() == _chassi)
			return "Concessionaria: " + getNome() + "\nMarca: " + moto[num].getMarca() + "\nPreço: " + to_string(moto[num].getPreco()) + "\nChassi: " + moto[num].getChassi() + "\nAno: " + to_string(moto[num].getAno()) + "\nTipo de motor: " + moto[num].getModelo(); 
	}

    return "Veículo não encontrado";
}


//Faz o aumento no preço dos veículos de acordo com a porcentagem enviada pelo usuário
string Concessionaria::Aumento(float _aumento)
{
	string total = ""; 
	int num = 0;
	float valor; 
	
	if(_aumento <=  0)
	{
		return "Não houve aumento";
	}

	if((aut > 0) || (cm > 0) || (mt > 0))
	{
		if(aut > 0)
		{
			for(num = 0; num < aut; num++)
			{
				valor = car[num].getPreco();
				ap += (valor * (_aumento))/100; 
				vp += (valor * (_aumento))/100; 
				valor += (valor * (_aumento))/100;
				car[num].setPreco(valor); 	
			}
			total += "Aumento de " + to_string(_aumento) + "% nos preços de automóveis da Concessionária " + getNome() + " realizado\n";
		}
		if(cm > 0)
		{
			for(num = 0; num < cm; num++)
			{
				valor = truck[num].getPreco();
				cp += (valor * (_aumento * 2))/100;
				vp += (valor * (_aumento) * 2)/100;
				valor += (valor * (_aumento * 2))/100; 
				truck[num].setPreco(valor);
			}
			total += "Aumento de " + to_string(_aumento * 2) + "% nos preços de motos da Concessionária " + getNome() + " realizado\n";
		}
		if(mt > 0)
		{
			for(num = 0; num < mt; num++)
			{
				valor = moto[num].getPreco();
				mp += (valor * (_aumento * 3))/100;
				vp += (valor * (_aumento * 3))/100; 
				valor += (valor * (_aumento * 3))/100;
				moto[num].setPreco(valor);
			}
			
			total += "Aumento de " + to_string(_aumento * 3) + "% nos preços de caminhões da Concessionária " + getNome() + "realizado\n";
		}
		
		return total; 
	}	
	
	return "não existe veículo";
	
}
