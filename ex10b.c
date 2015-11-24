#include <stdio.h>

void banco_dados(int di[10],int dj[10], int dk[10]);
void chute_senha(int di[10],int dj[10],int dk[10]);

int main(void)
{
    int bi[10] = {0}, bj[10] = {0}, bk[10] = {0};
    banco_dados(bi, bj, bk);
    chute_senha(bi, bj, bk);
    return 0;
}

void banco_dados(int di[10],int dj[10],int dk[10])
{
    int i,j,k,cont;
    for(cont=0; cont<50; cont++)
    {
        scanf("%d %d %d", &i, &j, &k);
        di[i]++;
        dj[j]++;
        dk[k]++;
    }
}

void chute_senha(int di[10],int dj[10],int dk[10])
{
    int i,s, auxi, auxj, auxk, senha[6] = {0};
    for(s=0; s<2; s++)
    {
        auxi = auxj = auxk = 0;
        for(i=0; i<10; i++)
        {
            if(di[i] > di[auxi])
                auxi = i;
            if(dj[i] > dj[auxj])
                auxj = i;
            if(dk[i] > dk[auxk])
                auxk = i;
        }
        senha[s] = auxi;
        di[auxi] = 0;
        senha[s+2] = auxj;
        dj[auxj] = 0;
        senha[s+4] = auxk;
        dk[auxk] = 0;
    }
    printf("A senha mais provavel e: ");
    for(i=0; i<6; i++)
        printf("%d",senha[i]);
    printf("\n");
}
