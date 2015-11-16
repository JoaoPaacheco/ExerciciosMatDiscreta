#include<stdio.h>
#include<time.h>

#define QNTPESSOAS 10 //define a quantidade de pessoas da tabela
#define TAMNOME 21 //define o tamanho maximo dos nomes
#define TAMCEL 12 //define o tamanho dos telefenos celulares de acordo com o padrao do DDD 81 ex: xxxxx-xxxx

int main(void)
{
    char listanomes[QNTPESSOAS][TAMNOME];
    char listanumeros[QNTPESSOAS][TAMCEL];
    int i, s, aux;
    //preencher(listanomes[QNTPESSOAS][TAMNOME]);

    srand(time(NULL));

    for(i = 0 ; i <= QNTPESSOAS; i++)
        for(s = 0 ; s <= TAMNOME; s++)
            listanomes[i][s] = '\0';

    for(i = 0; i <= QNTPESSOAS; i++)
    {
        for(s = 0; s <= TAMNOME - 1; s++)
        {
            aux = (66 + rand()%(91-66));
            listanomes[i][s] = (char) aux;
        }
        printf("%s.\n",listanomes[i]);
    }

    return 0;
}
