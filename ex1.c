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
    
    /*printf("tamanho: %lx.\n",sizeof(ul1.pt1));
    printf("valor: %lx.\n",ul1.pt1);
    ul1.pt1--;
    printf("valor: %lx.\n", ul1.pt1);
    ul1.pt1++;
    printf("valor: %lx.\n", ul1.pt1);
    Esta parte do codigo foi feita para confirmar que a variavel tem
    o tamanho de oito bytes, que sua representacao hexadecimal e 0x'acompanha 16 letras/numeros'
    e a comprovacao do overflow.*/

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
