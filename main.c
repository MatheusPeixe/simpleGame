#include "game.h"

int main(){
  setlocale(LC_ALL,"");

  classe classes[TOTAL_CLASSE] = {
    {190, "Arqueiro"},
    {230, "Guerreiro"},
    {200, "Mago"},
    {250, "Barbaro"},
  };

  boss bosses[TOTAL_BOSSES] = {
    {"Cleric Best", 22, 600},
    {"Father Gascoigne", 27, 800},
    {"Vicar Amelia", 32, 900},
    {"One Reborn", 30, 1000},
    {"Gehrman, The First Hunter", 50, 1500},
  };

  equipamento equipamentosInicial[TOTAL_CLASSE] = {
    {"Girombinator", 0, 50, 100},
    {"LongSword", 0, 50, 100},
    {"Pirulinator", 0, 50, 100},
    {"BattleAxe", 0, 50, 100},
  };

  equipamento todosEquipamentos[TOTAL_CLASSE][TOTAL_ITEM_CLASSE] = {
    { // arqueiro
      {"Arco Curvo       ", 100, 60, 100},
      {"Arco Longo       ", 160, 65, 110},
      {"Bosta de 2 Flecha", 300, 80, 150},
      {"Arco Celeste     ", 330, 100, 160},
      {"Arco Sagrado     ", 500, 110, 200},
    },
    { // guerreiro
      {"ClayMore        ", 100, 60, 100},
      {"Tempestade Negra", 160, 65, 110},
      {"Rapieira        ", 200, 80, 130},
      {"Espada de Gelo  ", 300, 100, 130},
      {"Lamina da Morte ", 500, 110, 200},
    },
    { // mago
      {"Cajado da Ameaça Vaporosa ", 100, 60, 80},
      {"Cajado Beatífico Menor    ", 160, 65, 100},
      {"Cajado Beatífico Maior    ", 200, 80, 110},
      {"Cajado do Carcereiro      ", 300, 100, 130},
      {"Cajado Carvalho da batalha", 500, 110, 200},
    },
    { // barbáro
      {"Machado Grande   ", 100, 60, 100},
      {"Martelo          ", 160, 65, 100},
      {"Mangual          ", 200, 80, 120},
      {"Machado de 2 Mãos", 290, 100, 130},
      {"Machado Estrela  ", 500, 110, 150},
    },
  };

  player jogador;

  lerInformacoesJogador(&jogador, classes);

  // inicialização do jogador
  jogador.gold = GOLD_INICIAL;
  jogador.pocoes = POCOES_INICIAL;
  jogador.vida = classes[jogador.classe - 1].vidaInicial;
  jogador.equipamentoAtual = equipamentosInicial[jogador.classe - 1];

  int gameOver = false;
  int bossAtual = 0;
  int chargeAtack = 0;
  int acao;

  while(gameOver == false) {
    if (jogador.vida <= 0) {
      system("clear");
      printf("gameOver");
      getchar();
      gameOver = true;
      continue;
    }
    system("clear");
    printf("\nboss atual: %s  | vida: %d ", bosses[bossAtual].nome, bosses[bossAtual].vida);
    printf("\n%s(%s) | vida: %d | poções: %d | chargeAtack: %d", jogador.nickName, classes[jogador.classe - 1].nome, jogador.vida, jogador.pocoes, chargeAtack);
    printf("\nequipamento atual: %s | dano base: %d | dano especial %d", jogador.equipamentoAtual.nome, jogador.equipamentoAtual.danoBase, jogador.equipamentoAtual.danoEspecial);
    printf("\n\nselecione sua ação:");
    printf("\n1 - Ataque normal    2 - Ataque especial      3 - Poção\n -> ");
    scanf("%d", &acao);

    switch(acao) {
      case(1):
        aplicarAtaqueNormal(jogador.equipamentoAtual.danoBase, &bosses[bossAtual]);
        chargeAtack++;
        break;
      case(2): 
        if (chargeAtack >= 3) {
          aplicarAtaqueEspecial(jogador.equipamentoAtual.danoEspecial, &bosses[bossAtual]);
          chargeAtack -= 3;
        } else {
          printf("\nVocê deve carregar ao menos 3 ataques para usar a habilidade especial\n");
          fflush(stdin);
          getchar();
        }
        break;
      case(3): utilizarPocao(&jogador, classes); continue; break;
      default: printf("\nAção invalida\n"); getchar(); continue; break;
    }
    getchar();

    if (bosses[bossAtual].vida <= 0) {
      printf("\nmatou o boss\n");
      getchar();
      jogador.gold += 50 * (bossAtual + 1);
      
      bossAtual++;
      if (bossAtual == TOTAL_BOSSES) {
        printf("\nParabens, derrotou todos\n");
        getchar();
        break;
      }
      exibirLoja(&jogador, classes, todosEquipamentos);
    } else {
      jogador.vida -= bosses[bossAtual].dano;
      printf("\nO boss te atacou, você tomou %d de dano\n", bosses[bossAtual].dano);
      getchar();
    }

  }

  return 0;
}
