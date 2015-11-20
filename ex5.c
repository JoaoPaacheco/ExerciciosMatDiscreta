#include/* aqui espaco */<stdio.h>

typedef struct st_lista
{
    int c; // o item armazenado
    struct st_lista *prox; // ponteiro para o proximo
}lista;

lista *buscar (lista *cabeca, int x)
{
    lista *pl = cabeca;
    while (pl != NULL)
    {
        if(pl -> c == x)
            return pl;
        pl = pl -> prox;
    }
    return NULL;
}

void inserir(lista **cabeca, int x)
{
    lista *pl=*cabeca;
    lista *plant = NULL;
    while (pl != NULL)
    {
        plant = pl;
        pl = pl -> prox;
    }
    pl = malloc(sizeof(lista));
    pl -> c = x;
    pl -> prox = NULL;
    if(plant != NULL)
        plant -> prox = pl;
    else
        *cabeca = pl;
}

void remover (lista **cabeca, lista *r)
{
    lista *pl = *cabeca;
    lista *plant = NULL;
    if(r == NULL)
        return;
    while(pl != NULL && pl!=r) // ate achar r ou fim
    {
        plant = pl;
        pl = pl -> prox;
    }
    if(pl == NULL) // nao achou ou lista vazia
        return;
    if(plant != NULL) // tem anterior
        plant -> prox = pl -> prox;
    else // eliminando cabeca
        *cabeca = pl -> prox;
    free(pl);
    return;
}

lista *anterior(lista *cabeca, lista *r)
{
    lista *pl = cabeca;
    lista *plant = NULL;
    if (r == NULL)
        return NULL;
    while(pl != NULL && pl != r)
    {
        plant = pl;
        pl = pl -> prox;
    }
    return plant;
}

void imprimir(lista *cabeca)
{
    lista *pl = cabeca;
    while (pl != NULL)
    {
        printf("%d ->", pl-> c);
        pl = pl -> prox;
    }
    printf("NULL\n");
}

int main (void)
{
    lista *l1 = NULL, *b = NULL, *a = NULL;
    inserir(&l1, 1);
    imprimir(l1);
    inserir(&l1, 2);
    imprimir(l1);
    inserir(&l1, 3);
    imprimir(l1);
    b = buscar(l1, 2);
    if(b!=NULL)
        printf("b -> c: %d.\n", b -> c);
    a = anterior(l1, b);
    if (a != NULL)
        printf("a -> c: %d.\n", a -> c);
    b = buscar(l1, 2);
    remover(&l1, b);
    imprimir(l1);
    return 0;
}
