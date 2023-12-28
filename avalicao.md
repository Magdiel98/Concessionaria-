
# Identificação

* Nome:Magdiel Gomes Ferreira 

* Matrícula:20210049290
  
# Compilação  

Além de digitar make na raiz, para rodar o programa é necessário digitar ./programa na pasta bin.

Foi criada uma espécie de "Menu Principal" mostrando os comandos que são:
1 - create-concessionaria;
2 - add-car;
3 - add-truck;
4 - add-moto; 
5 - remove-vehicle;
6 - search-vehicle;
7 - list-concessionaria;
8 - raise-price; 
6 - quit. 

O comando create-concessionaria serve para criar a concessionaria e para usar esse comando deve ser digitado no terminal na seguinte sequência: 

create-concessionaria  Nome da concessionária  CNPJ  Quantidade de veículos

Exemplo para ser digitado: 
create-concessionaria AutoCar 12.340.600/0001-00 0
create-concessionaria CarMix 13.250.581/0001-02 0

Deve existir apenas um único espaço entre eles. Os outros comandos seguem da mesma forma. 

O comando add-car serve para adicionar carros e segue da seguinte forma: 

add-car  Nome da concessionária  Marca  Preço  Chassi  Ano  Motor

O motor apresenta duas opções: gasolina ou elétrico 

Exemplo:
add-car AutoCar Honda 150000 9BHHE22MX34060960 2002 gasolina 

Os comandos add-truck(adicionar caminhão) e add-moto(adicionar moto) seguem de forma semelhante ao add-car. A diferença é que em vez do motor, eles apresentam carga e modelo respectivamente: 

add-truck  Nome da concessionária  Marca  Preço  Chassi  Ano  Carga

add-moto  Nome da concessionária  Marca  Preço  Chassi  Ano  Modelo

Opções de carga: comum ou perigosa 

Opções de modelo: clássico ou esportivo 

Exemplos: 

add-truck CarMix JAC 600000 9BJGL23IG54040790 2016 comum

add-moto AutoCar Yamaha 18350 9BY116GW04C400001 2020 classico

O comando remove-vehicle serve para remover veículo:

remove-vehicle  Chassi

Exemplo:  
remove-vehicle 9BY116GW04C400001


Como observado, o veículo é removido através do chassi.

Para sair do programa basta digitar "quit". 

Foi colocado cin.get() e system("clear") para pausar o terminal e logo em seguida, limpá-lo. Portanto, após aparecer a confirmação de que foi adicionado um veículo, ou adicionada uma concessionária ou mesmo aparecer a mensagem de saída, é necessário digitar uma tecla para limpar o terminal ou sair do programa.

Se tentar adicionar um veículo a uma concessionária que não existe, também dará erro. Adicione as concessionárias já listadas anteriormente e tente o seguinte comando: 

add-truck Veiculos JAC 600000 9BJFT24IY54940790 2016 comum 


Ao tentar adicionar um veículo que já foi adicionado será impresso na tela uma mensagem de erro.

Adicione uma das concessionárias e um dos veículos já criados e tente criar o veículo novamente: 

create-concessionaria AutoCar 12.340.600/0001-00 0 
add-car AutoCar Honda 150000 9BHHE22MX34060960 2002 gasolina

Tente digitar o mesmo veículo:  

add-car AutoCar Honda 150000 9BHHE22MX34060960 2002 gasolina

Lembre-se sempre que quando for adicionar uma concessionária ou um veículo, logo após a adição pressione um tecla(Enter, por exemplo). 

Agora, remova o carro anterior pelo chassi: 

remove-vehicle 9BHHE22MX34060960

Tente remover novamente e aparecerá uma mensagem que o veículo não foi encontrado.


Com o comando search-vehicle você pode encontrar o veículo pelo chassi. Tente digitar um chassi
já adicionado na concessionária, exemplo: 

search-vehicle 9BHHE22MX34060960

Agora, tente procurar por um veículo não adicionado: 

search-vehicle 9BWWE33MM34060962

Você verá mensagem de veículo não encontrado.


Com o comando list-concessionaria podemos listar os veículos da concessionária, exemplo: 

list-concessionaria AutoCar

Procure por outra concessionária adicionada: 

list-concessionaria CarMix

Ao tentar listar uma concessionária que não foi adicionada a mensagem de que a concessionária não
foi encontrada aparecerá: 

list-concessionaria Default


O Comando raise-price faz aumentar em uma porcentagem dada pelo usuário o preço de todos os veículos de uma concessionária:

raise-price CarMix 10 

Tente na outra concessionária: 

raise-price AutoCar 10

Comprove o aumento listando a concessionária: 

list-concessionaria AutoCar ou CarMix




# Limitações

Houve dificuldades na utilização da função de busca da biblioteca "algorithm", o find(), portanto foram criadas funções para realizar buscas. 
Outra dificuldade foi usar os iteradores, portanto foram criadas variáveis para fazer o incremento e o decremento para poder acessar posições dos vectores. 
Essas dificuldades são decorrentes de não saber como capturar informações usando iteradores e métodos juntos, ou, find e métodos.
   
Não consegui implementar a tempo a manipulação de arquivos e também a questão de não usar a busca exaustiva. 

# Autoavaliação

- Modelagem e implementação das classes Concessionária, Veículo, Automóvel, Moto, Caminhão | **10 / 10**
  - 0: sem modelagem e implementação de classes
  - 5: apenas algumas classes modeladas e implementadas; ausência de herança
  - 10: modelagem e implementação completa com uso de herança
  
- Implementação e uso do comando `create-concessionaria` | **10 / 10**
  - 0: não cria concessionária via linha de comando 
  - 5: permite criar apenas uma concessionária
  - 10: permite criar mais do que uma concessionária
  
- Implementação e uso dos comandos para adicionar veículos `add-car/add-bike/add-truck` | **10 / 10**
  - 0: não permite criar veículos via linha de comando
  - 5: permite criar apenas um ou outro veículo em uma única concessionária
  - 10: permite criar qualquer tipo de veículo em qualquer uma das concessionárias disponíveis

- Não permitir adicionar um veículo que já tenha sido anteriormente adicionado | **10 / 10**
  - 0: não realiza o teste
  - 10: realiza o teste e indica o erro  

- Implementação e uso do comando para remover veículos `remove-vehicle` | **10 / 10**
  - 0: comando não implementado
  - 10: comando implementado e funcional

- Implementação e uso do comando para busca de veículos `search-vehicle` | **15 / 15 - Bônus: ...**
  - 0: não implementado
  - 15: implementado e funcional
  - bonus +10: implementado com estratégia de busca diferente da busca exaustiva
  - bonus +10: uso de métodos virtuais para impressão na tela
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `list-concessionaria` | **10 / 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional   
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `raise-price` | **10 / 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional 
  - bonus +10: implementado com uso de método virtual

- Implementação e uso do comando `save-concessionaria` e `load-concessionaria` | **0 / 30**
  - 0: não implementado
  - 15: ambos os comandos implementados e funcionais
  
- Implementação eficiente através do uso de referencias e contêineres da STL | **5 / 10**
  - 0: não usou contêiner da STL nem fez uso eficiente dos recursos computacionais
  - 5: usou contêiner da STL mas não otimizou uso dos recursos computacionais
  - 10: usou contêiner da STL junto a algoritmos e práticas de bom uso de recursos computacionais
  
- Organização do código em src, include, data | **5 / 5**
  - 0: não organizou o código
  - 5: organizou o código 
  
- Documentação do código | **5 / 5**
  - 0: não documentou o código
  - 5: documentou o código 
  
- Implementação e documentação de arquivos e procedimentos de compilação e teste | **0 / 15**
  - 0: não implementou arquivos e procedimentos de compilação e teste
  - 5: implementou alguns arquivos e procedimentos de compilação e teste (com alguma documentação) 
  - 15: Ampla implementação e documentação de arquivos e procedimentos de compilação e teste (com exemplos)
 
 # Total
 
 **... / 150 ** pontos (sem bônus)
 
 **... / 200 ** pontos (com bônus)
