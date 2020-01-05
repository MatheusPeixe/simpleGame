#include "game.h"

void lerInformacoesJogador(player *jogador, classe classes[TOTAL_CLASSE]) {
  int i;
  printf("Como deseja ser chamado?(obs: maximo 100 caracteres)\n -->");
  scanf("%s", jogador->nickName);

  int classeEscolhidainvalida;

  do {
    system("clear");
    printf("Escolha uma das classes disponiveis:\n");

    for(i = 0; i < TOTAL_CLASSE; i++) {
      printf("\n%d - %s", i + 1, classes[i].nome);
    }
    printf("\n-->");

    scanf("%d", &jogador->classe);

    classeEscolhidainvalida = jogador->classe <= 0 || jogador->classe > 4;
    jogador->classe--;
    if (classeEscolhidainvalida) {
      system("read -p \"Opção escolhida invalida\" saindo");
    }
  } while(classeEscolhidainvalida);

}
