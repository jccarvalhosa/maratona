#include <stdio.h>
#include <stdlib.h>

typedef struct Jogador{
    int pos;
    char tipo;
}Jogador;

int compara(const void * jog1, const void *jog2)
{
    Jogador *j1 = (Jogador*) jog1;
    Jogador *j2 = (Jogador*) jog2;
    if( j1->pos > j2->pos ) return 1;
    else if( j1->pos < j2->pos || ( j1->tipo == 'D' && j2->tipo=='A' ) ) return -1;
    else if ( j1->tipo == 'A' && j2->tipo=='D' ) return 1;
    return 0;
}

int main()
{
    int atac, def, imp=0;
    while(scanf("%d%d", &atac, &def) && atac)
    {
        Jogador jogs[atac + def];
        imp = 0;
        int i;
        for(i=0;i<atac;i++)
        {
            scanf("%d", &jogs[i].pos);
            jogs[i].tipo = 'A';
        }
        for(;i<def + atac;i++)
        {
            scanf( "%d", &jogs[i].pos );
            jogs[i].tipo = 'D';
        }
        qsort(jogs, atac + def, sizeof(Jogador), compara);
        for(i=0;i<2;i++) if(jogs[i].tipo == 'A') imp = 1;
        if(imp) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}


