#include <stdio.h>
#include <stdlib.h>

typedef struct Carta{ //struct para armazenar as informacoes da carta
    char naipe;
    char nome;
    int valor;
} carta;


typedef struct Baralho{ //struct para armazenar as cartas, separadas entre que ja foram sorteadas e as que ainda estao no deck
    carta deck_usado[52];
    carta deck[52];
    int cont; //variavel para armazenar a quantidade que ja sairam do deck
} baralho;


typedef struct Pontuacao{
    int pontos;
} pontuacao;


typedef struct Player{
    pontuacao pontos;
    int ganhos;
} player;


int valor_carta(carta x){
    if (x.nome=='A') return 1;
    else if (x.nome=='J'|| x.nome=='K' || x.nome=='Q' || x.nome=='0') return 10;
    return x.nome-48; //convertendo o char para inteiro, baseado na tabela ascii q tem o 0 como 48
}

int main()
{
    //declaracao das variaveis que seram usadas no programa principal
    char apostando = 'S';
    player jogador;
    jogador.ganhos=0

    //declaração e leitura das cartas:
    baralho cartas;
    cartas.cont=0;
    for (int i=0;i<52;i++){
        scanf("%c%c", &cartas.deck[i].nome, &cartas.deck[i].naipe);
        cartas.deck[i].valor=valor_carta(cartas.deck[i]);
    }

    while (jogando=='S'){ //começa aqui o jogo
        //declaracao das variaveis que serao usadas no jogo

    }
    return 0;
}
