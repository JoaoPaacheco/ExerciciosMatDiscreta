#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerasenha(char v[7]);
void imprimecombinacoes(char v[7]);

int main(void)
{
    srand(time(NULL));
    char senha[7];
    gerasenha(senha);
    imprimecombinacoes(senha);
    /*printf("A senha e: %s.\n",senha);*/ /*Linha para debug*/
    return 0;
}

void gerasenha(char v[7]) /*funcao que gera a senha*/
{
    int i = 0;
    for(; i<6; i++)
        v[i]=(char) (48+rand()%10);
    v[6]= '\0';
}

void imprimecombinacoes(char v[7]) /*Funcao que imprime as combinacoes*/
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
        printf("%c%c%c\n",v[i],v[j],v[k]);
        cont++;
    }
}
