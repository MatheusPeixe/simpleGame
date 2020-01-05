#include "main.h"

int main(){
  setlocale(LC_ALL,"");

  classe classes[TOTAL_CLASSE] = {
    {150, "Arqueiro"},
    {230, "Guerreiro"},
    {170, "Mago"},
    {250, "Barbaro"},
  };

  boss bosses[TOTAL_BOSSES] = {
    {"Cleric Best", 50, 600},
    {"Father Gascoigne", 70, 800},
    {"Vicar Amelia", 80, 900},
    {"One Reborn", 90, 1000},
    {"Gehrman, The First Hunter", 100, 1500},
  };

  equipamento equipamentosInicial[TOTAL_CLASSE] = {
    {"Girombinator", 0, 60, 100},
    {"LongSword", 0, 80, 110},
    {"Pirulinator", 0, 70, 100},
    {"BattleAxe", 0, 90, 100},
  };

  equipamento equipamentoArqueiro[TOTAL_ITEM_CLASSE] = {
    {"Arco Curvo", 100, 65, 100},
    {"Arco Longo", 160, 70, 110},
    {"Bosta de 2 Flecha", 300, 130, 150},
    {"Arco Celeste", 330, 150, 160},
    {"Arco Sagrado", 500, 200, 200},
  };

  equipamento equipamentosGuerreiro[TOTAL_ITEM_CLASSE] = {
    {"ClayMore", 100, 65, 100},
    {"Tempestade Negra", 160, 70, 110},
    {"Rapieira", 200, 80, 130},
    {"Espada de Gelo", 300, 90, 130},
    {"Lamina da Morte", 500, 100, 150},
  };

  equipamento equipamentosMago[TOTAL_ITEM_CLASSE] = {
    {"Cajado da Ameaça Vaporosa", 100, 65, 100,},
    {"Cajado Beatífico Menor", 160, 70, 100,},
    {"Cajado Beatífico Maior", 200, 80, 110,},
    {"Cajado do Carcereiro", 300, 90, 130},
    {"Cajado Carvalho da batalha", 500, 100, 150},
  };

  equipamento equipamentosBarbaro[TOTAL_ITEM_CLASSE] = {
    {"Machado Grande", 100, 60, 100},
    {"Martelo", 160, 70, 100},
    {"Mangual", 200, 80, 120},
    {"Machado de 2 Mãos", 290, 90, 130},
    {"Machado Estrela", 400, 100, 150},
  };

  int i, j;
  player jogador;

  printf("Como deseja ser chamado?(obs: maximo 100 caracteres)\n -->");
  scanf("%s", &jogador.nickName);

  int classeEscolhidainvalida;

  do {
    system("clear");
    printf("Escolha uma das classes disponiveis:\n");

    for(i = 0; i < TOTAL_CLASSE; i++) {
      printf("\n%d - %s", i + 1, classes[i].nome);
    }
    printf("\n-->");

    scanf("%d", &jogador.classe);

    classeEscolhidainvalida = jogador.classe <= 0 || jogador.classe > 4;
    jogador.classe--;
    if (classeEscolhidainvalida) {
      system("read -p \"Opção escolhida invalida\" saindo");
    }
  } while(classeEscolhidainvalida);

  // inicialização do jogador
  jogador.gold = GOLD_INICIAL;
  jogador.pocoes = POCOES_INICIAL;
  jogador.vida = classes[jogador.classe].vidaInicial;
  jogador.equipamentoAtual = equipamentosInicial[jogador.classe];

  return 0;
}
