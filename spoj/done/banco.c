#include <stdio.h>

int main(){
	int n, i, inst=1, jaCalculados=0;
	double fat[1000000], resposta;
	fat[0] = 1;
	while(scanf("%d", &n) == 1){
	if(n > jaCalculados){
		for(i=jaCalculados+1;i<=n;i++){
			fat[i] = fat[i-1] * i;
		}
		jaCalculados = n;
	}
	resposta = fat[n];
	while(resposta > 10){
		resposta = resposta  / 10;
	}
	printf("Instancia %d\n%f\n%d\n\n", inst, fat[n], int(resposta));
	inst++;
	}
	return 0;
}
