#include <stdio.h>

int main(){
	int n, A[31], i, j, teste=1, alcancados[1001], novos[1001], aseq;
	while(scanf("%d", &n) != EOF){
		for(i=0;i<n;i++) scanf("%d", &A[i]);
		printf("Case #%d: ", teste++);
		for(i=0;i<n;i++) printf("%d ", A[i]);
		printf("\n");
		//para cada numero da sequencia, verifica se ele pode ser alcançado pelos anteriores e marca novos pontos como alcancados
		aseq = 1;
		if(A[0] <= 0) aseq = 0;
		else{
			for(i=1;i<=1000;i++) alcancados[i] = 0;
			alcancados[A[0]] = 1;
			for(i=1;i<n;i++){
				if(A[i] <= A[i-1]){
					aseq = 0;
					break;
				}
				if(alcancados[A[i]]){
					aseq = 0;
					break;
				}
				novos[0] = 1;
				novos[1] = A[i];
				for(j=A[i]+1;j<=1000;j++){
					if(alcancados[j-A[i]] && !alcancados[j]){
						novos[++novos[0]] = j;
					}
				}
				for(j=1;j<=novos[0];j++) alcancados[novos[j]] = 1;
			}
		}
		if(aseq) printf("This is an A-sequence.\n");
		else printf("This is not an A-sequence.\n");
	}
	return 0;
}
