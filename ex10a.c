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
    printf("A senha e: %s.\n",senha);
    return 0;
}

void gerasenha(char v[7])
{
    int i = 0;
    for(; i<6; i++)
        v[i]=(char) (48+rand()%10);
    v[6]= '\0';
}

void imprimecombinacoes(char v[7])
{
    int i, j, k, cont = 0;
    while(cont<50)
    {
        i = j = k = 0;
        while(!(i<j && j<k))
        {
            i = rand()%4;
            j = rand()%5;
            k = rand()%6;
        }
        printf("%c%c%c\n",v[i],v[j],v[k]);
        cont++;
    }
}
