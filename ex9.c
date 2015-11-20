#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define max 1000

int result[max][max], mat1[max][max], mat2[max][max], numthread = 1;

void *preencher(void *z);

void* mult(void *z);

int main(void)
{
    int i;
    pthread_t tid[max];
    time_t inicio, fim;


    while(numthread<max)
    {
        time(&inicio);
        for(i=1; i<=numthread; i++)
            pthread_create(&tid[i], NULL, preencher, (void*) &i);
        for(i=1; i<=numthread; i++)
            pthread_join(tid[i], NULL);
        for(i=1; i<=numthread; i++)
            pthread_create(&tid[i], NULL, mult, (void*) &i);
        for(i=1; i<=numthread; i++)
            pthread_join(tid[i], NULL);
        time(&fim);
        printf("Utilizando %d threads o a multiplicacao demorou: %g segundos.\n", numthread, difftime(fim,inicio));
        numthread++;
    }
    return 0;
}

void *preencher(void *x)
{
    int qtd = *((int *) x);
    int i,s;
    for(i = ((qtd-1)*(max/numthread)); i<(qtd*(max/numthread)); i++)
    {
        for (s=0; s<max ; s++)
        {
            mat1[i][s] = 1;
            mat2[i][s] = 2;
        }
    }
    pthread_exit(0);
}

void *mult(void *x)
{
    int qtd = *((int *) x);
    int i,s,a;
    for(i = ((qtd-1)*(max/numthread)); i<(qtd*(max/numthread)); i++)
    {
        for (s = 0; s < max ; s++)
        {
            a = 0;
            while (a<max)
            {
                result[i][s] += mat1[i][a] * mat2[a][s];
                a++;
            }
        }
    }
    pthread_exit(0);
}

