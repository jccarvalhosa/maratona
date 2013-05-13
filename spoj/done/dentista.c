#include <stdio.h>

typedef struct{
    int ini;
    int fim;
}Consulta;

int max(int a, int b){
	if(a < b) return b;
	return a;
} 

int busca(int buscado, int n, Consulta* c){
	int max=n, min=0, mid;
	mid = (max + min)/2;
	do{
		if(c[mid].fim == buscado) return mid;
		if(c[mid].fim > buscado){
			max = mid;
			mid = (max + min)/2;
		}
		if(c[mid].fim < buscado){
			min = mid;
			mid = (max + min)/2;
		}
	}while(mid != min && mid != max);
	if(c[max].fim > buscado) return min;
	else return max;
}

int main(){
    int i, n, comeco, termino, maximo[10000], indice;
    Consulta c[10000];
    scanf("%d", &n);
    for(i=0;i<n;i++){
		scanf("%d%d", &comeco, &termino);
		if(i== 0 || termino > c[i-1].fim){
			c[i].ini = comeco;
			c[i].fim = termino;
		}
		else while(termino <= c[i-1].fim){
			i--;
			n--;
			c[i].ini = comeco;
			c[i].fim = termino;
		}
	}
	for(i=0;i<n;i++){
		//nova consulta: c[i].
		//se ela participar das consultas, o valor maximo[i] sera maximo[consultas ate onde nao tem intersecao] + 1.
		//se ela nao participar, maximo[i] sera maximo[i-1].
		indice = busca(c[i].ini, i, c);
		if(indice == 0 && c[indice].fim > c[i].ini)  maximo[i] = 1;
		else maximo[i] = max(maximo[indice] + 1, maximo[i-1]);
	}
	printf("%d\n", maximo[n-1]);
		
    return 0;
}

