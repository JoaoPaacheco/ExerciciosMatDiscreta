#include<stdio.h>
#include<time.h>
#include<string.h>


#define QNTPESSOAS 10 //define a quantidade de pessoas da tabela
#define TAMNOME 6 //define o tamanho maximo dos nomes. OBS: o nome real tem o nome inferior deste valor - 1
#define TAMCEL 11 //define o tamanho dos telefenos celulares de acordo com o padrao do DDD 81 ex: xxxxx-xxxx

int main(void)
{
    char listanomes[QNTPESSOAS][TAMNOME]; //lista com referência e nome
    char listanumeros[QNTPESSOAS][TAMCEL]; // lista com referêcia e numero
    int i, s, aux; //variaveis auxiliares ao longo do programa
    char nomeaux[TAMNOME]; // nome auxliar utilizado para compacao

    srand(time(NULL));

    printf("Segue a lista de nomes e numeros.");

    for(i = 0 ; i <= QNTPESSOAS; i++) // realizado para se certificar que no final encontraremos um caractere nulo
    {
        listanomes[i][TAMNOME - 1] = '\0';
        listanumeros[i][TAMCEL - 1] = '\0';
    }

    for(i = 0; i <= QNTPESSOAS - 1; i++) // preencher nomes
    {
        for(s = 0; s <= TAMNOME - 2; s++) // lembrar de deixar um espaco no final para o caractere nulo
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
        printf("Nome: %s.",listanomes[i]); //imprimir nomes
        for(s = 0; s <= TAMCEL - 2; s++) // mesmo comentario do for anterior
        {
            if(s == 0)
                listanumeros[i][s] = '9'; //atualmente todos os numeros no DDD 81 comecam com 9.
           else
           {
                if(s == 5)
                {
                listanumeros[i][s] = '-'; // espacamento para melhor identificacao dos numeros.
                }
                else
                {
                    aux = (48 + rand()%10);
                    listanumeros[i][s] = (char) aux; // transferir inteiro para char atilizando a tabela ascii.
                }
           }
        }
        printf(" Numero: %s.\n", listanumeros[i]); //imprimir numeros logo apos o nome.
    }

    printf("Escolha um nome da lista para confirmar o numero do celular:\n");
    gets(nomeaux); // pedindo o nome ao usuario.

    s = 0;
    for (i = 0 ; i <= QNTPESSOAS - 1 ; i++) // verificando a existencia deste nome
    {
        if(!strcmp(listanomes[i],nomeaux))
        {
            printf("O numero de celular desta pessoa e: %s.\n", listanumeros[i]);
            s = 1;// nome existe.
        }
    }

    if(s == 0) // caso nome nao tenha sido encontrado.
        printf("Nome nao encontrando, favor tentar novamente.\n");

    printf("Programa terminado com sucesso.\n");

    return 0;
}
