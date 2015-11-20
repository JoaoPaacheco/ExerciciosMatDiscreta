#include<stdio.h>

int main(void)
{
    typedef struct
    {
        unsigned long pt1; /*primeira parte da variavel maior*/
        unsigned long pt2; /*segunda parte da variavel maior*/
    }ullong;

    ullong ul1;
    ul1.pt1 = 0;
    ul1.pt2 = 0;
    

   while(ul1.pt1 != 0xFFFFFFFFFFFFFFFF && ul1.pt2 != 0xFFFFFFFFFFFFFFFF) /*condicao ira rodar ate que as duas variaveis estejam completamente cheias.*/
    {
        if(ul1.pt1 == 0xFFFFFFFFFFFFFFFF)//no momento do overflow o programa adiciona um a segunda metade da variavel.
        {   
            printf("Passou.\n");
            ul1.pt2++;
            printf("%lu\n.", ul1.pt2);
        }
        ul1.pt1++;
    }

   printf("Criado tipo com capacidade para 16 bytes de armazenamento.\n");
    
   return 0;
}

ullong somar(ullong x, ullong y)
{
    ullong aux;
    aux.pt1 = 0;
    while(x.pt1 && x.pt2 != 0)

}
