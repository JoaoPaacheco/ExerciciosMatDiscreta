#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamsenha 6

void gerasenha(int v[tamsenha]);
void imprimecombinacoes(int v[tamsenha]);
void imprime_senha(int v[tamsenha]);

int main(void)
{
    srand(time(NULL));
    int senha[tamsenha];
    gerasenha(senha);
    imprimecombinacoes(senha);
    /*imprime_senha(senha); codigo para debug*/
    return 0;
}

void gerasenha(int v[tamsenha]) /*funcao que gera a senha*/
{
    int i = 0;
    for(; i<tamsenha; i++)
        v[i]=rand()%10;
}

void imprimecombinacoes(int v[tamsenha]) /*Funcao que imprime as combinacoes*/
{
    int i, j, k, cont = 0;
    while(cont<50)
    {
        i = j = k = 0; /*Certificando-se que uma nova combinacao sera rodada todas as vezes*/
        while(!(i<j && j<k)) /*regra: i < j < k*/
        {
            i = rand()%4; /*implicacoes da regra: i nao pode ser maior que 4, j que 5 e k que 6.*/
            j = rand()%5; /*Portanto, pode-se retirar os numeros que as variaveis nunca irao poder assumir.*/
            k = rand()%6;
        }
        printf("%d%d%d\n",v[i],v[j],v[k]);
        cont++;
    }
}

void imprime_senha(int v[tamsenha])
{
    int i = 0;
    printf("A senha e: ");
    for(; i<tamsenha; i++)
        printf("%d", v[i]);
    printf("\n");
}
