#include <stdio.h>
#include <stdlib.h>

typedef struct sorteios
{
    int dezena1, dezena2, dezena3, dezena4, dezena5, dezena6, ganhadores, sorteio;
    char data[9];
    float premio;
    struct sorteios *prox;
}sorteios;

void preencher(sorteios **cabeca);
void imprimirtodos(sorteios *cabeca);

int main(void)
{
    sorteios *cabeca = NULL;
    preencher(&cabeca);
    imprimirtodos(cabeca);
    return 0;
}

void preencher (sorteios **cabeca)
{
    sorteios *p1 = *cabeca;
    long int aux;
    int i = 1;
    while(i <= 1450)
    {
        p1 = malloc(sizeof(sorteios));
        scanf("%d %ld %d %d %d %d %d %d %d %f", &p1->sorteio, &aux, &p1->dezena1, &p1->dezena2, &p1->dezena3, &p1->dezena4, &p1->dezena5, &p1->dezena6, &p1->ganhadores, &p1->premio);
        sprintf(p1 -> data, "%ld", aux);
        p1 -> prox = NULL;
        if (i == 1)
            *cabeca = p1;
        p1 = p1 -> prox;
        i++;
    }
}

void imprimirtodos(sorteios *cabeca)
{
    sorteios *p1 = cabeca;
    printf("Imprimindo todos os sorteios.\n");
    printf("Concurso Data 1_Dezena 2_Dezena 3_Dezena 4_Dezena 5_Dezena 6_Dezena Ganhadores Rateio_por_Ganhador.\n");
    while(p1 != NULL)
    {
        printf("Concurso: %d. Data de realizacao: %s. Dezenas: %d, %d, %d, %d, %d e %d. Total de ganhadores: %d. Premio para cada ganhador: %f.\n", p1->sorteio, p1->data, p1->dezena1, p1->dezena2, p1->dezena3, p1->dezena4, p1->dezena5, p1->dezena6, p1->ganhadores, p1->premio);
        p1 = p1->prox;
    }
}
