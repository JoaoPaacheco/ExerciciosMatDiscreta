#include<stdio.h>
#include<time.h>

#define QNTPESSOAS 10 //define a quantidade de pessoas da tabela
#define TAMNOME 11 //define o tamanho maximo dos nomes
#define TAMCEL 11 //define o tamanho dos telefenos celulares de acordo com o padrao do DDD 81 ex: xxxxx-xxxx

int main(void)
{
    char listanomes[QNTPESSOAS][TAMNOME];
    char listanumeros[QNTPESSOAS][TAMCEL];
    int i, s, aux;

    srand(time(NULL));

    printf("Segue a lista de nomes e numeros.");

    for(i = 0 ; i <= QNTPESSOAS; i++)
    {
        listanomes[i][TAMNOME - 1] = '\0';
        listanumeros[i][TAMCEL - 1] = '\0';
    }

    for(i = 0; i <= QNTPESSOAS - 1; i++)
    {
        for(s = 0; s <= TAMNOME - 2; s++)
        {
            if(s != 0)
            {
                aux = (97 + rand()%(123-97));
                listanomes[i][s] = (char) aux;
            }
            else
            {
                aux = (65 + rand()%(91-65));
                listanomes[i][s] = (char) aux;
            }
        }
        printf("Nome: %s.",listanomes[i]);
        for(s = 0; s <= TAMCEL - 2; s++)
        {
            if(s == 0)
                listanumeros[i][s] = '9';
           else
           {
                if(s == 5)
                {
                listanumeros[i][s] = '-';
                }
                else
                {
                    aux = (48 + rand()%10);
                    listanumeros[i][s] = (char) aux;
                }
           }
        }
        printf(" Numero: %s.\n", listanumeros[i]);
    }

    printf("Escolha um nome da lista para confirmar o numero do celular:\n");

    return 0;
}
