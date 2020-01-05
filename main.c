#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define TOTAL_CLASSE 4
#define CLASSE_ARQUEIRO 1
#define CLASSE_GUERREIRO 2
#define CLASSE_MAGO 3
#define CLASSE_BARBARO 4

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

  setlocale(LC_ALL,"");

  int i, j;
  player jogador;

  printf("Como deseja ser chamado?(obs: maximo 100 caracteres)\n -->");
  scanf("%s", &jogador.nickName);

  int classeEscolhidainvalida;

  do {
    system("clear");
    printf("Escolha uma das classes disponiveis:\n");

    for(i = 0; i < TOTAL_CLASSE; i++) {
      printf("\n%d - %s", i + 1, classesDisponiveisTexto[i]);
    }
    printf("\n-->");

    scanf("%d", &jogador.classe);
    jogador.classe--;

    classeEscolhidainvalida = jogador.classe < 0 || jogador.classe > 4;
    if (classeEscolhidainvalida) {
      system("read -p \"Opção escolhida invalida\" saindo");
    }
  } while(classeEscolhidainvalida);

  printf("jogador: %s escolheu a classe %s", jogador.nickName, classesDisponiveisTexto[jogador.classe]);

  return 0;
}
