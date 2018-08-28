#include <stdio.h>
#include <stdlib.h>

typedef struct Carta{
    int valor;
    char naipe;
    char nome;
} carta;

typedef struct Baralho{
    carta deck[52];
    carta deck_nao_comprado[52];

} baralho;


int valor_carta(carta x){
    if (x.nome=='A') return 1;
    else if (x.nome=='J'|| x.nome=='K' || x.nome=='Q' || x.nome=='0') return 10;
    return x.nome-48;
}

int main()
{
    carta as;
    scanf("%c%c", &as.nome, &as.naipe);
    printf("%c valor %c naipe\n", as.nome, as.naipe);
    printf("%d\n", valor_carta(as));
    return 0;
}
