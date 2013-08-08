#include <stdio.h>

int main(){
	int i, j, num, x, y, n, soma, v[100], teste=1, podeChegar[500000], maior, novoMaior, chegouNaRodada[500000], nrodada;
	while(scanf("%d%d%d", &x, &y, &n) && x){
		printf("Teste %d\n", teste++);
		num = x - y;
		if(num < 0) num = -num;
		soma = 0;
		for(i=0;i<n;i++){
			scanf("%d", &v[i]);
			soma += v[i];
		}
		//como os coeficientes so podem ser 1 ou -1, pode-se retirar 2 * v[i] em qualquer quantidade de i's.
		if((soma - num) % 2 == 1) printf("N\n\n");
		//agora os numeros so podem ter coeficientes positivos.
		else{
			num = (soma - num) / 2;
			for(i=0;i<=num;i++) podeChegar[i] = 0;
			podeChegar[0] = 1;
			for(i=0;i<n;i++){
				nrodada = 0;
				for(j=v[i];j<=num;j++){
					if(podeChegar[j - v[i]]){
						chegouNaRodada[nrodada++] = j;
					}
				}
				for(j=0;j<nrodada;j++)	podeChegar[chegouNaRodada[j]] = 1;
			}
			if(podeChegar[num]) printf("S\n\n");
			else printf("N\n\n");
		}
	}
	return 0;
}


