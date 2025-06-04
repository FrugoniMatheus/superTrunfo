#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX_CART 3
//INCLUDE CARTACACHORRO 
// Classes 
//FIlter by



typedef struct {
  char nome[50];
  int brincalhao;
  float peso;
  int agressividade;
  int agilidade;
  int obediencia;
  int superTrunfo; 
} CartaCachorro; 


typedef struct{
  char nome[50];
  int pontos;
  CartaCachorro cartas[MAX_CART];
} JogadorCartas;


void gerarNumeroAleatorio(int *v, int max){
  srand(time(NULL));
  *v = rand() % max;
}


void introducaoJogo(){
  printf(" ----------------------------------------------------------\n");
  printf("|                 JOGO SUPER TRUNFO CANINO                 |\n");
  printf("|__________________________________________________________|\n");
}

void imprimirLinhaDupla(int v1){
  int i = 0; 
  for(i = 0; i < v1; i++) printf("=");
}

void comoJogar(){
  imprimirLinhaDupla(100);
  printf("\n------------------------------------------------------------\n");
  printf("|Como jogar:                                               |\n");
  printf("|1- O jogador que inicia sera sorteado aleatoriamente ele  |\n");
  printf("|precisa pegar a sua primeira carta do seu monte escolher  |\n");
  printf("|o atributo que queira comparar(ex:'velocidade');          |\n");
  printf("|2- Os demais jogadrem tambem pegam a primeira carta do    |\n");
  printf("|monte deles e revelam o valor daquele mesmo atributo;     |\n");
  printf("|3- Aquele que tiver o maior atributo escolhido ganha a    |\n");
  printf("|rodada;                                                   |\n");
  printf("|4- O ganhador da rodada anterior, ira escolhe o proximo   |\n");
  printf("|atributo;                                                 |\n");
  printf("|5- Em caso de empata o jogado da rodada anterior ira      |\n");
  printf("|escolher o atributo novamente.                            |\n");
  printf("|6- Cartas SUPERTRUNFO, ganham indepedente no valor que    |\n");
  printf("|apresenta na carta.                                       |\n");
  printf("------------------------------------------------------------\n");
}


void jogoEmpatado(){
  printf("///         RESULTADO : JOGO EMPATADO          ///\n");
  printf("///          NENHUM PONTO ATRIBUIDO           ///\n");
}


void limparTela(){
  system("cls");
}

void escolhaAtributos(int **atributo){
  printf("|-------------------------------|\n");
  printf("|  Atributos para escolher:     |\n");
  printf("|  0 - Brincalhao               |\n");
  printf("|  1 - Peso                     |\n");
  printf("|  2 - Agressividade            |\n");
  printf("|  3 - Agilidade                |\n");
  printf("|  4 - Obediencia               |\n");
  printf("|_______________________________|\n\n");
  printf("Atributo escolhido: ");
  scanf( "%d", &**atributo);
}

void impressaoAtributoInteiro(char atributo[50], int v1, int v2){
  printf("Jogador escolheu o atributo : %s\n", atributo);
          printf("--------------------------------------------------\n");
          printf("|   cartas Adversario     |   Sua carta          |\n");
          printf("|      %s : %d        |   %s : %d     |\n",
          atributo,v1, atributo, v2 );
          printf("|_________________________|______________________|\n\n");
}

void impressaoAtributoFloat(char atributo[50],float v1, float v2){
  printf("Jogador escolheu o atributo : %s\n", atributo);
  printf("--------------------------------------------------\n");
  printf("|   cartas Adversario     |   Sua carta          |\n");
  printf("|         %s : %.1f      |     %s : %.1f      |\n",atributo,v1, 
    atributo, v2 );
    printf("|_________________________|______________________|\n\n");
}

void impressaoEscolhaAtributo(JogadorCartas jogadorAtributo[], int atributo){
  switch(atributo){
    case 0: 
      impressaoAtributoInteiro("Brincalhao",jogadorAtributo[0].cartas[0].brincalhao,
        jogadorAtributo[1].cartas[0].brincalhao);
      break;
    case 1:
      impressaoAtributoFloat("Peso",jogadorAtributo[0].cartas[0].peso,
        jogadorAtributo[1].cartas[0].peso);
      break;
    case 2:
      impressaoAtributoInteiro("Agressividade",jogadorAtributo[0].cartas[0].agressividade,
        jogadorAtributo[1].cartas[0].agressividade);
      break;
    case 3: 
      impressaoAtributoInteiro("Agilidade",jogadorAtributo[0].cartas[0].agilidade,
        jogadorAtributo[1].cartas[0].agilidade );
      break;
    case 4:
      impressaoAtributoInteiro("obediencia" ,jogadorAtributo[0].cartas[0].obediencia,
        jogadorAtributo[1].cartas[0].obediencia);
      break;

      default:
        printf("Erro atributo para o BOT\n");
        break;
  }
}

void jogadorAcaoAtributo(int *atributo, JogadorCartas jogCar[]){
  escolhaAtributos(&atributo);
  printf("---------------------------------------------\n");
  impressaoEscolhaAtributo(jogCar, *atributo);
  printf("---------------------------------------------\n");
}

void imprimirCartaInteira(JogadorCartas jogador[], int nJogador){
  printf("Dados da carta que possui: \n");
  printf("----------------------\n");
  printf("| Nome carta: %s  |\n", jogador[nJogador].cartas[0].nome);
  printf("|  Brincalhao: %d    |\n", jogador[nJogador].cartas[0].brincalhao);
  printf("|  Peso: %.1f       |\n",jogador[nJogador].cartas[0].peso);
  printf("|  Agressividade: %d |\n",jogador[nJogador].cartas[0].agressividade);
  printf("|  Agilidade: %d     |\n",jogador[nJogador].cartas[0].agilidade);
  printf("|  Obediencia: %d    |\n",jogador[nJogador].cartas[0].obediencia);
  printf("|___________________|\n\n");  
}

  int main(){

  // ----------Inicio criação Carta---------------------------------//
  CartaCachorro cc[7];

  strcpy(cc[0].nome, "Salsicha");
  cc[0].brincalhao = 4;
  cc[0].peso = 4.5;
  cc[0].agressividade = 6;
  cc[0].agilidade = 7;
  cc[0].obediencia = 7;
  cc[0].superTrunfo = 0;

  strcpy(cc[1].nome, "Husky");
  cc[1].brincalhao = 4;
  cc[1].peso = 27;
  cc[1].agressividade = 8;
  cc[1].agilidade = 6;
  cc[1].obediencia = 5;
  cc[1].superTrunfo = 1;

  strcpy(cc[2].nome, "Border Collie");
  cc[2].brincalhao = 6;
  cc[2].peso = 22;
  cc[2].agressividade = 2;
  cc[2].agilidade = 8;
  cc[2].obediencia = 9;
  cc[2].superTrunfo = 0;

  strcpy(cc[3].nome, "Sao Bernardo");
  cc[3].brincalhao = 1;
  cc[3].peso = 110;
  cc[3].agressividade = 6;
  cc[3].agilidade = 1;
  cc[3].obediencia = 3;
  cc[3].superTrunfo = 0;

  strcpy(cc[4].nome, "Beagle");
  cc[4].brincalhao = 5;
  cc[4].peso = 13.5;
  cc[4].agressividade = 5;
  cc[4].agilidade = 9;
  cc[4].obediencia = 1;
  cc[4].superTrunfo = 0;

  strcpy(cc[5].nome, "Dalmata");
  cc[5].brincalhao = 6;
  cc[5].peso = 58;
  cc[5].agressividade = 7;
  cc[5].agilidade = 6;
  cc[5].obediencia = 6;
  cc[5].superTrunfo = 0;
  
  strcpy(cc[6].nome, "Pit Bull");
  cc[6].brincalhao = 1;
  cc[6].peso = 27;
  cc[6].agressividade = 9;
  cc[6].agilidade = 8;
  cc[6].obediencia = 10;
  cc[6].superTrunfo = 0;
  // ----------FIM criação Carta---------------------------------------//


  // ----------Inicio criação Jogador---------------------------------//
  //FILTRER BY
  //  

  JogadorCartas jc[1];
  strcpy(jc[0].nome,"Robo");
  jc[0].pontos = 0;
  strcpy(jc[0].cartas[0].nome ,cc[0].nome);
  jc[0].cartas[0].brincalhao = cc[0].brincalhao;
  jc[0].cartas[0].peso = cc[0].peso;
  jc[0].cartas[0].agressividade = cc[0].agressividade;
  jc[0].cartas[0].agilidade = cc[0].agilidade;
  jc[0].cartas[0].obediencia = cc[0].obediencia;


  // Esse Jogador sera o Player
  char nomeJogador[50];
  printf("Informe o seu nome (Colocar letras apenas em CAPSLOCK): ");
  fgets(nomeJogador, 49, stdin);
  nomeJogador[strcspn(nomeJogador, "\n")] = 0;
  limparTela();
  
  strcpy(jc[1].nome, nomeJogador);
  jc[1].pontos = 0;
  strcpy(jc[1].cartas[0].nome ,cc[1].nome);
  jc[1].cartas[0].brincalhao = cc[1].brincalhao;
  jc[1].cartas[0].peso = cc[1].peso;
  jc[1].cartas[0].agressividade = cc[1].agressividade;
  jc[1].cartas[0].agilidade = cc[1].agilidade;
  jc[1].cartas[0].obediencia = cc[1].obediencia;
  // ----------FIM criação Jogador---------------------------------//


  // ----------Inicio Jogo----------------------------------------//
  

  introducaoJogo();
  comoJogar();


  int acabarJogo;
  printf("Deseja Jogar? [0]Nao [1]Sim: ");
  scanf("%d", &acabarJogo);

  int atributoEscolhido = 0;
  int atributoRandomico = 0;  
  char nomeGanhador[50];
  

  //----Atribuir Aleatóriamente que irá começar--------//
  int ganhadorAleatorio = 0;
  gerarNumeroAleatorio(&ganhadorAleatorio, 2);
  strcpy(nomeGanhador, jc[ganhadorAleatorio].nome);


  //---------Inicio Partida----------
  while(acabarJogo == 1){ 

    //----Rodada Jogador IA. ---------------------------
    limparTela();
    
    if (strcmp(nomeGanhador, jc[0].nome) == 0){

      printf("--------------------------------------------\n");
      printf("Jogador da vez: %s\n", jc[0].nome);

      gerarNumeroAleatorio(&atributoRandomico, 5);

      impressaoEscolhaAtributo(jc, atributoRandomico);

      atributoEscolhido = atributoRandomico;
    }

    //---Inicio Rodada Player---------------------------
    else if (strcmp(nomeGanhador, jc[1].nome) == 0){
      //----Mensagem Vez Player
      printf("///////////////////////////////////\n");
      printf("||     Jogador da Vez : %s       ||\n",nomeGanhador);
      printf("///////////////////////////////////\n");
    
      //---Escolha Ação Player
      int acaoJogador; 
      retornoAcaoJogador:
      printf("O que deseja fazer? \n[0]Consultar Dados Cartas \n[1]Escolher atributo\n");
      printf("[2]Rever Regras do jogo\n[3]Limpar Tela\n");
      printf(": ");
      scanf("%d",&acaoJogador);

      //---Ação Player
      if(acaoJogador == 0){
        printf("\n");
        imprimirCartaInteira(jc, 1);
        goto retornoAcaoJogador;  
      }
      else if(acaoJogador == 1){
        jogadorAcaoAtributo(&atributoEscolhido, jc);
      } 
      else if(acaoJogador == 2){
        printf("\n");
        comoJogar();
        goto retornoAcaoJogador;
      }
      else if(acaoJogador == 3){
        limparTela();
        goto retornoAcaoJogador;
      }
      else{
        printf("Erro identificacao acao do jogador");
      }
    }
    else {
      printf("Erro identificacao nome jogador");
    }
    // -----Fim Rodada Player----------------------- 


    //--- Inicio Verificação do Resultado da Rodada --------------
    printf("///////////////////////////////////////////////////\n");
    
    
    switch(atributoEscolhido){

      case 0: 

        if(jc[0].cartas[0].brincalhao == jc[1].cartas[0].brincalhao){
          jogoEmpatado();;
        } 
        else if (jc[0].cartas[0].brincalhao > jc[1].cartas[0].brincalhao){
          printf("///   RESULTADO : JOGADOR %s VENCEU A RODADA   ///\n\n", jc[0].nome);
          strcpy(nomeGanhador,jc[0].nome);
          jc[0].pontos += 1;
        } 
        else if(jc[0].cartas[0].brincalhao < jc[1].cartas[0].brincalhao){
          printf("///   RESULTADO : JOGADOR %s VENCEU A RODADA   ///\n", jc[1].nome);
          strcpy(nomeGanhador,jc[1].nome);
          jc[1].pontos += 1;
        } 
        else{
          printf("Erro na comparacao das cartas, revisar codigo!!\n");
        }

        break;
      case 1:

        if(jc[0].cartas[0].peso == jc[1].cartas[0].peso){
          jogoEmpatado();
        } 
        else if(jc[0].cartas[0].peso > jc[1].cartas[0].peso){
          printf("///   RESULTADO : JOGADOR %s VENCEU A RODADA   ///\n", jc[0].nome);
          strcpy(nomeGanhador,jc[0].nome);
          jc[0].pontos += 1;
        } 
        else if(jc[0].cartas[0].peso < jc[1].cartas[0].peso){
          printf("///   RESULTADO : JOGADOR %s VENCEU A RODADA   ///\n", jc[1].nome);
          strcpy(nomeGanhador,jc[1].nome);
          jc[1].pontos += 1;
        } 
        else{
          printf("Erro na comparacao das cartas, revisar codigo!!\n");
        }

        break;
      case 2:

        if(jc[0].cartas[0].agressividade == jc[1].cartas[0].agressividade){
          jogoEmpatado();
        } 
        else if (jc[0].cartas[0].agressividade > jc[1].cartas[0].agressividade){
          printf("///   RESULTADO : JOGADOR %s VENCEU A RODADA   ///\n", jc[0].nome);
          strcpy(nomeGanhador,jc[0].nome);
          jc[0].pontos += 1;
        } 
        else if(jc[0].cartas[0].agressividade < jc[1].cartas[0].agressividade){
          printf("///   RESULTADO : JOGADOR %s VENCEU A RODADA   ///\n", jc[1].nome);
          strcpy(nomeGanhador,jc[1].nome);
          jc[1].pontos += 1;
        } 
        else{
          printf("Erro na comparacao das cartas, revisar codigo!!\n");
        }

        break;
      case 3:

        if(jc[0].cartas[0].agilidade == jc[1].cartas[0].agilidade){
          jogoEmpatado();
        } 
        else if (jc[0].cartas[0].agilidade > jc[1].cartas[0].agilidade){
          printf("///   RESULTADO : JOGADOR %s VENCEU A RODADA   ///\n", jc[0].nome);
          strcpy(nomeGanhador,jc[0].nome);
          jc[0].pontos += 1;
        } 
        else if(jc[0].cartas[0].agilidade < jc[1].cartas[0].agilidade){
          printf("///   RESULTADO : JOGADOR %s VENCEU A RODADA   ///\n", jc[1].nome);
          strcpy(nomeGanhador,jc[1].nome);
          jc[1].pontos += 1;
        } 
        else{
          printf("Erro na comparacao das cartas, revisar codigo!!\n");
        }

        break;
      case 4:

        if(jc[0].cartas[0].obediencia == jc[1].cartas[0].obediencia){
          jogoEmpatado();
        } 
        else if (jc[0].cartas[0].obediencia > jc[1].cartas[0].obediencia){
          printf("///   RESULTADO : JOGADOR %s VENCEU A RODADA   ///\n", jc[0].nome);
          strcpy(nomeGanhador,jc[0].nome);
          jc[0].pontos += 1;
        } 
        else if(jc[0].cartas[0].obediencia < jc[1].cartas[0].obediencia){
          printf("///   RESULTADO : JOGADOR %s VENCEU A RODADA   ///\n", jc[1].nome);
          strcpy(nomeGanhador,jc[1].nome);
          jc[1].pontos += 1;
        } 
        else{
          printf("Erro na comparacao das cartas, revisar codigo!!\n");
        }

        break;
      default:
      
        printf("Atributo indefinido!!\n");
        printf("---------------------------------------------\n");
        
        break;
    }//--- Fim Verificação do Resultado da Rodada --------------
    
    
    printf("////////////////////////////////////////////////\n\n");


    //----Inicio Exibição de pontos-----------
    printf("---------------------------------------------\n");
    printf("Jogador: %s \nPossui: %d pontos\n", jc[0].nome, jc[0].pontos);
    printf("Jogador: %s \nPossui: %d pontos\n", jc[1].nome, jc[1].pontos);
    printf("---------------------------------------------\n");
    //----Fim Exibição de pontos-----------


    printf("Deseja continuar a proxima rodada? [0]Nao [1]Sim: ");
    scanf("%d", &acabarJogo);
    printf("\n");
    if(acabarJogo == 0){
      if(jc[0].pontos == jc[1].pontos){
        printf("PARTIDA EMPATADA");
      }
      else if(jc[0].pontos > jc[1].pontos){
        printf("PARTIDA GANHAR POR %s", jc[0].nome);
      }
      else if(jc[1].pontos > jc[0].pontos){
        printf("PARTIDA GANHAR POR %s", jc[1].nome);
      }
      else{ 
        printf("NÃO FOI POSSÍVEL RANKEAR");
      }
    }
    
  }//---------Fim Partida----------
  
  
  return 0;
}

