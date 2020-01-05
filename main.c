#include<stdio.h>

#define TOTAL_CLASSE 4
#define CLASSE_ARQUEIRO 0
#define CLASSE_GUERREIRO 1
#define CLASSE_MAGO 2
#define CLASSE_BARBARO 3

typedef struct {
  char nickName[100];
  int classe;
} player;

int main(){
	int classesDisponiveis[TOTAL_CLASSE] = {
		CLASSE_ARQUEIRO,
		CLASSE_GUERREIRO,
		CLASSE_MAGO,
		CLASSE_BARBARO,
	};

	char *classesDisponiveisTexto[TOTAL_CLASSE] = {
		"Arquiero",
		"Guerreiro",
		"Mago",
		"Barbaro",
	};

  return 0;
}
