#include<stdio.h>

struct ullong
{
    unsigned long pt1;
    unsigned long pt2;
}ul1;

struct ullong somar(struct ullong x,unsigned long y) //funcao para somar ullong com unsigned long.
{
    x.pt1 += y;
    if (x.pt1 < y)
    {
        x.pt2++;
        //printf("%lu %lu\n", x.pt1,x.pt2); //utilizado para debug
    }
    return x;
}

struct ullong subtrair(struct ullong x, unsigned long y) //funcao para subtrair um unsigned long do ullong.
{
    if (x.pt1 >= y)
        x.pt1 -= y;
    else
    {
        if(x.pt2 == 0)
        {
            printf("Impossivel subtrair %lu, valor maximo para subtracao: %lu.\n", y, x.pt1);
        }
        else
        {
            x.pt1 -= y;
            x.pt2--;
            //printf("%lu %lu\n", x.pt1, x.pt2);
        }
    }
    return x;
}

int main(void)
{
    /*Este codigo nao tem aplicacao, realizado apenas para conferir e provar fucionalidade da estrutura e funcoes aqui criadas.*/
    ul1.pt1 = 0;
    ul1.pt2 = 0;
    
    printf("Valor parte 1: %lu. Valor parte 2: %lu.\n", ul1.pt1, ul1.pt2);
    while(ul1.pt2 <=3)
        ul1 = somar (ul1, 1000000000000);
    printf("Valor parte 1: %lu. Valor parte 2: %lu.\n", ul1.pt1, ul1.pt2);
    while(ul1.pt1 != 0)
        ul1 = subtrair(ul1, 1000000000000);
    printf("Valor parte 1: %lu. Valor parte 2: %lu.\n", ul1.pt1, ul1.pt2);
    ul1 = subtrair(ul1,1000000000000);
    printf("Programa realizado com sucesso.\n");
    return 0;
}
