#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define QTDPESSOAS 15 /*define a quantidade de pessoas da tabela*/
#define TAMNOME 15 /*define o tamanho maximo dos nomes. OBS: o nome real tem o nome inferior deste valor - 1*/
#define TAMCEL 11 /*define o tamanho dos telefenos celulares de acordo com o padrao do DDD 81 ex: xxxxx-xxxx*/
#define QTDCHAVES 5 /*numero de chaves que podem ser utilizadas, para efeito de colisoes o numero sera menor que QTDPESSOAS*/

char *geranome(char m[TAMNOME]);
int hashing(char mn[TAMNOME]);

int main(void)
{
    int i, chave, chavesutilizadas[QTDCHAVES] = {0}, numcolisoes = 0;
    char listanomes[QTDPESSOAS][TAMNOME]; /*lista com chave e nome*/
    char listanumeros[QTDPESSOAS][TAMCEL]; /*lista com chave e numero*/
    char aux1[TAMNOME];

    srand(time(NULL));
    for(i=0; i<QTDPESSOAS; i++)
    {
        strcpy(aux1, geranome(aux1));
        chave = hashing(aux1);
        if(chavesutilizadas[chave] == 0)
        {
            strcpy(listanomes[chave], aux1);
            chavesutilizadas[chave] == 1;
            /*TODO: gerar numero.*/
        }
        else
        {
            printf("Colisao! Posicionando nome em outra posicao.\n");
            chave = QTDCHAVES + numcolisoes;
            strcpy(listanomes[chave], aux1);
            numcolisoes++;
            /*TODO: gerar numero.*/
        }
    }
    
    return 0;
}   


int hashing(char mn[TAMNOME])   /*funcao que recebe um nome e retorna sua chave*/
{
    int chave = (int) mn[0] + (int) mn[TAMNOME-2];
    return chave%10;
}

char *geranome(char m[TAMNOME]) /*funcao para gerar nomes plausiveis*/
{
    int i=0, aux;
    for(i=0 ; i<TAMNOME-2; i++)
    {
        if(i != 0)
        {
            aux = 1;
            while(aux)
            {
                if(m[i-1] == 'a' || m[i-1] == 'e' || m[i-1] == 'i' || m[i-1] == 'o' || m[i-1] == 'u')
                {
                    m[i] = (char) (97+rand()%(123-97));
                    if(m[i] != 'a' && m[i] != 'e' && m[i] != 'i' && m[i] != 'o' && m[i] != 'u')
                        aux = 0;
                }
                else
                {
                    m[i] = (char) (97+rand()%(123-97));
                    if(m[i] == 'a' || m[i] == 'e' || m[i] == 'i' || m[i] == 'o' || m[i] == 'u')
                        aux = 0;
                }
            }
        }
        else
            m[i] = (char) (97+rand()%(123-97));
    }
    m[TAMNOME-1] = '\0';
    return m;
}

char *geranumero()
{
    return m;
}
