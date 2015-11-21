#include <stdio.h>
#include <stdlib.h>

#define qtdsorteios 1450

typedef struct sorteios
{
    int dezena1, dezena2, dezena3, dezena4, dezena5, dezena6, ganhadores, sorteio;
    char data[9];
    float premio;
    struct sorteios *prox;
}sorteios;

void preencher(sorteios **cabeca);
void imprimirtodos(sorteios *cabeca);
void jogoprovavel(sorteios *cabeca, int moda[6]);

int main(void)
{
    long int aux;
    int moda[6] = {0};
    sorteios *cabeca = NULL;
    cabeca = malloc(sizeof(sorteios));
    scanf("%d %ld %d %d %d %d %d %d %d %f", &cabeca->sorteio, &aux, &cabeca->dezena1, &cabeca->dezena2, &cabeca->dezena3, &cabeca->dezena4, &cabeca->dezena5, &cabeca->dezena6, &cabeca->ganhadores, &cabeca->premio);
    sprintf(cabeca->data, "%ld", aux);
    preencher(&cabeca);
    /*imprimirtodos(cabeca); linha de codigo para debug*/
    jogoprovavel(cabeca, moda);
    printf("O jogo mais provavel de acontecer e o: %d, %d, %d, %d, %d e %d.\n", moda[0], moda[1], moda[2], moda[3], moda[4], moda[5]);
    return 0;
}

void jogoprovavel(sorteios *cabeca, int *moda) /*funcao para descobrir a moda das dezenas.*/
{
    int i,s, numero[100] = {0}, aux;
    sorteios *p1 = cabeca;
    for(s=0; s<6; s++)
        moda[s] = 0;
    while(p1 != NULL) /*construindo o banco de dados*/
    {
        numero[p1->dezena1]++;
        numero[p1->dezena2]++;
        numero[p1->dezena3]++;
        numero[p1->dezena4]++;
        numero[p1->dezena5]++;
        numero[p1->dezena6]++;
        p1=p1->prox;
    }
    for(s=0; s<6; s++) /*buscando pelos maiores numeros.*/
    {
        aux = 0;
        for(i=0; i<100; i++)
        {
            if(numero[i] > numero[aux])
            {
                aux = i;
                moda[s] = aux;
            }
        }
        numero[moda[s]] = 0; /*tirando o maior numero para a obtencao do seu subsequente.*/
        moda[s]++; /*somando um ao numero pois o numero que estava aqui era o numero do indice do vetor numero[]*/
    }
}

void preencher (sorteios **cabeca)/*construindo banco de dados.*/
{
    long int aux;
    int i = 1;
    sorteios *p1 = *cabeca;
    while(i <= qtdsorteios-1) /* sorteios - 1 pois um ja foi contado pela cabeca */
    {
        p1->prox = malloc(sizeof(sorteios));
        p1 = p1->prox;
        scanf("%d %ld %d %d %d %d %d %d %d %f", &p1->sorteio, &aux, &p1->dezena1, &p1->dezena2, &p1->dezena3, &p1->dezena4, &p1->dezena5, &p1->dezena6, &p1->ganhadores, &p1->premio);
        sprintf(p1->data, "%ld", aux);
        p1->prox = NULL;
        i++;
    }
}

void imprimirtodos(sorteios *cabeca)/*imprimindo todos para realizar debug*/
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
