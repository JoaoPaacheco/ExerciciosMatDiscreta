#include<stdio.h>

typedef struct sorteios
{
    int dezena1, dezena2, dezena3, dezena4, dezena5, dezena6, ganhadores, sorteio;
    char data[9];
    float premio;
    struct sorteios *prox;
}sorteios;

void preencher (sorteios **cabeca)
{
    sorteios *p1 = *cabeca;
    int i = 1;
    long int aux;
    while(i <= 1450)
    {
        printf("%d\n", i);
        p1 = malloc(sizeof(sorteios));
        printf("aqui?\n");
        scanf("%d %ld %d %d %d %d %d %d %d %f", p1->sorteio, aux, p1->dezena1, p1->dezena2, p1->dezena3, p1->dezena4, p1->dezena5, p1->dezena6, p1->ganhadores, p1->premio);
        printf("ou aqui?\n");
        sprintf(p1 -> data, "%ld", aux);
        printf("Talvez?\n");
        p1 -> prox = NULL;
        if (i == 1)
            *cabeca = p1;
        p1 = p1 -> prox;
        i++;
    }
}

int main(void)
{
    printf("Que comecem os jogos.\n");
    sorteios *cabeca = NULL;
    preencher(&cabeca);
    return 0;
}
