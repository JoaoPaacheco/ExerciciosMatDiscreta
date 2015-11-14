#include<stdio.h>

struct ullong
{
    unsigned long pt1;
    unsigned long pt2;
}ul1;

struct ullong somar(struct ullong x,unsigned long y)
{
    x.pt1 += y;
    if (x.pt1 < y)
    {
        x.pt2++;
        printf("%lu %lu\n", x.pt1,x.pt2);
    }
    return x;
}

int main(void)
{
    ul1.pt1 = 0;
    ul1.pt2 = 0;
    
    printf("Valor: %lu.\n", ul1.pt1);
    while(ul1.pt2 <=3)
        ul1 = somar (ul1, 10000000000);   

    printf("Valor: %lu.\n", ul1.pt1);
    
    return 0;
}
