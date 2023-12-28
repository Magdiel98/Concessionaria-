#ifndef EXECUTOR_H
#define EXECUTOR_H
#include "sistema.h"
#include <istream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

class Executor {
  private:
  Sistema * sistema;
  stringstream ss;
  bool sair = false;

  public:
  Executor(Sistema &sistema);

  void iniciar(istream &in, ostream &out);

  string processarLinha(string linha);

  void menuPrincipal(); //Imprime o menu principal na tela 
};

#endif
