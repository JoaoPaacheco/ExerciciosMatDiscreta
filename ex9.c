#include<stdio.h>
#include<pthread.h>

#define max 1000

int result[max][max], mat1[max][max], mat2[max][max];

void* preencher(void *z, void *y)
{
    int *x = (int *) z;
    int limitesup = *x;
    int *f = (int *) y;
    int limiteinf = *f;
    int i,s;
    for(i = limiteinf; i< limitesup; i++)
    {
        for (s = 0; s < max ; s++)
        {
            mat1[i][s] = 1;
            mat2[i][s] = 2;
        }
    }
    pthread_exit(0);
}

void* mult(void *z, void *y)
{
    int *x = (int *) z;
    int limitesup = *x;
    int *f = (int *) y;
    int limiteinf = *f;
    int i, s, a;
    for(i = limiteinf; i < limitesup; i++)
    {
        for (s = 0; s < max ; s++)
        {
            a = 0;
            while (a < max)
            {
                result[i][s] += mat1[i][a] * mat2[a][s];
                a++;
            }
        }
    }
    pthread_exit(0);
}

int main(void)
{
    return 0;
}
