#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef struct{
    int topo;
    int valor[MAX];
}pilha;

void iniciapilha(pilha *p)
{
    p->topo=-1;
}


void push(pilha *p, float a)
{
    if(p->topo!=MAX-1)
    {
        p->topo++;
        p->valor[p->topo]=a;
    }
}

float pop(pilha *p)
{
    float ans;
    if(p->topo!=-1)
    {
        ans=p->valor[p->topo];
        p->topo--;
    }
    return ans;
}


int main(){
	
	pilha* p;
	int i, N, D, num, substituidos;
	char lixo, entrada[100000];
	
	p=malloc(sizeof(pilha));
	
while(1){
	iniciapilha(p);
	substituidos = 0;
	scanf("%d", &N);
	scanf("%d", &D);
	if(N == 0 && D == 0) return 0;
	scanf("%c", &lixo);
	for(i=0;i<N;i++){
		scanf("%c", &entrada[i]);
	}
	for(i=0;i<N;i++){
		num = (int)entrada[i] - 48;		
		while(p->topo != -1 && p->valor[p->topo] < num && substituidos < D){
			pop(p);
			substituidos++;
		}
		push(p, num);
	}
	while(substituidos < D){
		pop(p);
		substituidos++;
	}
	for(i=0;i<N-D;i++)  printf("%d", p->valor[i]);
	printf("\n");
}
	free(p);
	return 0;
}
