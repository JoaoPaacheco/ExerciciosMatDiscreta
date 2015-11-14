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
    
    printf("tamanho: %lx.\n",sizeof(ul1.pt1));
    printf("valor: %lx.\n",ul1.pt1);
    return 0;
}
