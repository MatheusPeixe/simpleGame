#include "game.h"

void utilizarPocao(player *jogador, classe classes[TOTAL_CLASSE]) {
  if (jogador->pocoes > 0) {
    if (jogador->vida >= classes[jogador->classe - 1].vidaInicial) {
      printf("\nVocê já possui a vida maxima\n");
      getchar();
      return;
    } else if (jogador->vida < classes[jogador->classe - 1].vidaInicial && (jogador->vida + POCAO_VIDA) > classes[jogador->classe - 1].vidaInicial){
      jogador->vida = classes[jogador->classe - 1].vidaInicial;
    } else {
      jogador->vida += POCAO_VIDA;
    }
    jogador->pocoes--;
    printf("\nVocê usou uma poção, restantes %d\n", jogador->pocoes);
    getchar();
  } else {
    printf("\nVocê não tem pocões no momento %d\n", jogador->pocoes);
    getchar();
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
    printf("%d - %s(%d-%d)       Preço: %d gold\n", 
    i + 1,
    todosEquipamentos[jogador->classe - 1][i].nome,
    todosEquipamentos[jogador->classe - 1][i].danoBase,
    todosEquipamentos[jogador->classe - 1][i].danoEspecial,
    todosEquipamentos[jogador->classe - 1][i].preco);
  }
  printf("%d - %s                   Preço: %d gold\n", i + 1, "Poção", PRECO_POCAO);

  printf("\n                 7 - Sair\n");
  printf("\nQual ação deseja Fazer ->");
  scanf("%d", &itemEscolhido);

  if (itemEscolhido == OPCAO_SAIR_LOJA) {
    return;
  }

  int escolheuPocao = itemEscolhido == i + 1;
  int qtdPocoes;

  if (escolheuPocao) {
    system("clear");
    printf("Classe: %s            Gold: %d\n\n", classes[jogador->classe - 1].nome, jogador->gold);
    printf("\nQuantas poções?\n ->");
    scanf("%d", &qtdPocoes);
  }

  int precoItemEscolhido = escolheuPocao ? (PRECO_POCAO * qtdPocoes) : todosEquipamentos[jogador->classe - 1][itemEscolhido - 1].preco;

  system("clear");

  if (temGoldSuficiente(jogador->gold, precoItemEscolhido)) {
    jogador->gold -= precoItemEscolhido;
    if (escolheuPocao) {
      jogador->pocoes += qtdPocoes;
      printf("\nPoções: %d", jogador->pocoes);
    } else {
      strcpy(jogador->equipamentoAtual.nome, todosEquipamentos[jogador->classe - 1][itemEscolhido - 1].nome);
      jogador->equipamentoAtual.danoBase = todosEquipamentos[jogador->classe - 1][itemEscolhido - 1].danoBase;
      jogador->equipamentoAtual.danoEspecial = todosEquipamentos[jogador->classe - 1][itemEscolhido - 1].danoEspecial;
    }
    printf("\nItem Adiquirido!!\n");
  } else {
    printf("\nGold Insuficiente!!\n");
  }
  printf("\nCarteira: %d", jogador->gold);
  getchar();
}

void aplicarAtaqueNormal(int danoBase, boss *bossAtual) {
  bossAtual->vida -= danoBase;
  printf("\nVocê atacou o boss com %d de dano\n", danoBase);
  getchar();
}

void aplicarAtaqueEspecial(int danoEspecial, boss *bossAtual) {
  if (rand() % 100 <= 95) {
    bossAtual->vida -= danoEspecial;
    printf("\nVocê atacou o boss com %d de dano\n", danoEspecial);
    getchar();
  } else {
    printf("\nO boss esquivou\n");
    getchar();
  }
}
