#include <stdio.h>

int main(){
	int n, i, cont=0, aux, vencedor[20000];
	do{
		scanf("%d", &n);
		for(i=1; i<=n; i++){
			scanf("%d", &aux);
			if(aux == i){
				vencedor[cont] = i;
				vencedor[cont++] = aux;
			}
		}
	}while(n != 0);
	i=0;
	while(i<cont){
		printf("Teste %d", vencedor[i++]);
		printf("\n%d\n\n", vencedor[i++]);
	}
	return 0;
}
