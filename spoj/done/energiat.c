#include <stdio.h>

int main(){
	int F, P, E, A, Energia[5000][20], Tempo[5000][20];
	int i, j, k;
	long long int f[5000][20], novo;
	while(scanf("%d%d%d%d", &F, &P, &E, &A) && F){
		for(i=0;i<P;i++) for(j=0;j<F;j++) scanf("%d%d", &Energia[i][j], &Tempo[i][j]);
		//define os valores iniciais para a funcao f com o programa 0.
		f[0][0] = Energia[0][0] * Tempo[0][0];
		for(i=1;i<20;i++) f[0][i] = Energia[0][i] * Tempo[0][i] + E * A;
		//agora atualiza a funcao recursivamente para o numero de programas.
		for(k=1;k<P;k++) for(i=0;i<20;i++){
			f[k][i] = f[k-1][i] + Energia[k][i] * Tempo[k][i];
			for(j=0;j<F;j++) if(j != i){
				novo = f[k-1][j] + Energia[k][i] * Tempo[k][i] + E * A;
				if(f[k][i] > novo) f[k][i] = novo;
			}
		}
		novo = f[P-1][0];
		for(i=1;i<F;i++) if(novo > f[P-1][i]) novo = f[P-1][i];
		printf("%lld\n", novo);
	}
	return 0;
}
