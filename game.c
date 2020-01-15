#include "game.h"

void utilizarPocao(player *player, classe classes[TOTAL_CLASSE]) {
  if (player->pocoes > 0) {
    player->pocoes--;

    player->vida += POCAO_VIDA;

    if (player->vida > classes[player->classe].vidaInicial) {
      player->vida = classes[player->classe].vidaInicial;
    }
  } else {
    system("read -p \"Você não tem pocões no momento\" saindo");
  }
}

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
    // jogador->classe--;
    if (classeEscolhidainvalida) {
      system("read -p \"Opção escolhida invalida\" saindo");
    }
  } while(classeEscolhidainvalida);
}

int temGoldSuficiente(int dinheiroAtual, int precoItem) {
  return dinheiroAtual >= precoItem;
}

void exibirLoja(player *jogador, classe classes[TOTAL_CLASSE], equipamento todosEquipamentos[TOTAL_CLASSE][TOTAL_ITEM_CLASSE]){
  system("clear");
  printf("Classe: %s            Gold: %d\n\n", classes[jogador->classe - 1].nome, jogador->gold);
  int i, itemEscolhido;

  for (i = 0; i < TOTAL_ITEM_CLASSE; i++) {
    printf("%d - %s       Preço: %d gold\n", i + 1, todosEquipamentos[jogador->classe - 1][i].nome, todosEquipamentos[jogador->classe - 1][i].preco);
  }
  printf("%d - %s                   Preço: %d gold\n", i + 1, "Poção", PRECO_POCAO);

  printf("\n                 7 - Sair\n");
  printf("\nQual ação deseja Fazer ->");
  scanf("%d", &itemEscolhido);

  if (itemEscolhido == OPCAO_SAIR_LOJA) {
    return;
  }

  int escolheuPocao = itemEscolhido == i + 1;
  int precoItemEscolhido = escolheuPocao ? PRECO_POCAO : todosEquipamentos[jogador->classe - 1][itemEscolhido - 1].preco;

  if (temGoldSuficiente(jogador->gold, precoItemEscolhido)) {
    jogador->gold -= precoItemEscolhido;
    if (escolheuPocao) {
      jogador->pocoes++;
      printf("\nPoções: %d", jogador->pocoes);
    } else {
      jogador->equipamentoAtual = todosEquipamentos[TOTAL_CLASSE][itemEscolhido - 1];
    }
    printf("\nItem Adiquirido!!");
  } else {
    printf("\nGold Insuficiente!!");
  }
  printf("\nCarteira: %d", jogador->gold);
}
