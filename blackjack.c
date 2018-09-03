#include <stdio.h>
#include <stdlib.h>
#define MAX_NOME 30
#define NUM_CARTAS 52

typedef struct Carta{ //struct para armazenar as informacoes da carta
    char naipe;
    char nome;
    int valor;
} carta;


typedef struct Baralho{ //struct para armazenar as cartas
    carta deck[NUM_CARTAS];
    int cont; //variavel para armazenar a quantidade que ja sairam do deck
} baralho;



typedef struct Player{
    int pontos;
    int ganhos;
    char nome[MAX_NOME];
} player;


int valor_carta(carta x){
    if (x.nome=='A') return 1; //ás
    else if (x.nome=='J'|| x.nome=='K' || x.nome=='Q' || x.nome=='0') return 10; //cartas com valor 10
    return x.nome-48; //convertendo o char para inteiro, baseado na tabela ascii q tem o 0 como 48
}


int compra_cartas(baralho cartas){ //
    carta comprada = cartas.deck[cartas.cont];
    printf("Carta: %d-%c \n", comprada.valor, comprada.naipe);
    return comprada.valor;
}


int main(int argc, char *argv[])
{
    //declaracao das variaveis que seram usadas no programa principal
    char jogando = 'S';
    player jogador;
    jogador.ganhos=0;

    //declaracao e leitura das cartas:
    baralho cartas;
    cartas.cont=0;
    for (int i=0;i<NUM_CARTAS;i++){
        char entrada[3];
        scanf(" %s", entrada);
        cartas.deck[i].nome = entrada[0];
        cartas.deck[i].naipe = entrada[1];
        cartas.deck[i].valor=valor_carta(cartas.deck[i]);
    }
    printf("Digite seu nome: \n");
    scanf("%s", jogador.nome);

    while (jogando=='S'){ //comeca o jogo

        //declaracao das variaveis que serao usadas no jogo
        char continuar = 'S';
        jogador.pontos = 0;
        int aposta;
        player dealer;
        dealer.pontos = 0;
        dealer.ganhos = 0;
        char turn='P';
        char continua;

        printf("Digite sua aposta: \n");
        scanf("%d", &aposta);
        jogador.ganhos-=aposta;
        printf("Jogador\n");

        while (turn=='P'){ //rodada do jogador
            jogador.pontos+=compra_cartas(cartas);
            cartas.cont++;
            if (jogador.pontos==21) turn='W'; //ganhou a partida
            else if (jogador.pontos>21) turn='L'; //perdeu automaticamente
            else{
              printf("Deseja continuar? (S/N) \n");
              char contin;
              scanf(" %c", &contin);
              if (contin!='S'){ //nao quer continuar, turno do dealer
                turn='D';
              }

            }
        }

        printf("Dealer \n");

        while (turn=='D'){
            if (dealer.pontos<17){ //para de comprar assim que tiver 17 pontos os mais
              dealer.pontos+=compra_cartas(cartas);
              cartas.cont++;
            }
            else if (dealer.pontos>21) turn='W'; //se tiver mais que 21, jogador ganha
            else if (dealer.pontos==21) turn = 'L'; //se chegar a 21, ganhou o jogo
            else{
              if (dealer.pontos>jogador.pontos) turn ='L'; //se fizer mais pontos, dealer ganha
              else turn='W'; //empate, jogador ganha
            }
        }

        if (turn=='W'){
          printf("Voce ganhou!\n");
          jogador.ganhos+=2*aposta; //ganhando, a aposta dobra
        }
        else if (turn=='L'){
          printf("Voce perdeu!\n");
          if (jogador.ganhos>0) jogador.ganhos-=aposta; //se ja tiver ganho alguma coisa, desconta as perdas do ganho
        }

        printf("Deseja fazer nova aposta (S/N): \n");
        scanf(" %c", &jogando);

        }
        if (jogador.ganhos<0) jogador.ganhos=0;
        printf("%s, voce ganhou %d reais.",jogador.nome, jogador.ganhos);

        
    return 0;
}
