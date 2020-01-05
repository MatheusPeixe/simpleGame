#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//defines para quantitação
#define TOTAL_BOSSES 5
#define TOTAL_CLASSE 4
#define TOTAL_ITEM_CLASSE 5

//identificadores de classe
#define CLASSE_ARQUEIRO 1
#define CLASSE_GUERREIRO 2
#define CLASSE_MAGO 3
#define CLASSE_BARBARO 4

//valores iniciais
#define GOLD_INICIAL 100
#define POCOES_INICIAL 3
#define POCAO_VIDA 50

//estruturas
typedef struct {
  char nome[30];
  int preco;
  int danoBase;
  int danoEspecial;
} equipamento;

typedef struct {
  char nickName[100];
  int classe;
  int gold;
  int vida;
  int pocoes;
  equipamento equipamentoAtual;
} player;

typedef struct {
  int vidaInicial;
  char nome[50];
} classe;

typedef struct {
  char nome[50];
  int dano;
  int vida;
} boss;
