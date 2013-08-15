#include <stdio.h>

int alcancados[101], D[101][101], total, n;

void prim(){
		//escolhe o menor caminho que parte de um vertice alcancado ate um que nao esteja alcancado.
		int i, j, imin, jmin, dmin, aux;
		dmin = 1000000;
		for(i=1;i<=n;i++) for(j=1;j<=n;j++){
			if(alcancados[i] && !alcancados[j] && dmin > D[i][j]){
				dmin = D[i][j];
				imin = i;
				jmin = j;
			}
		}
		alcancados[jmin] = 1;
		total++;
		if(jmin < imin){
			aux = jmin;
			jmin = imin;
			imin = aux;
		}
		printf("%d %d\n", imin, jmin);
		if(total < n) prim();
}

int main(){

	int  m, i, j, a, b, d, teste=1;
	while(scanf("%d%d", &n, &m) && n){
		for(i=1;i<=n;i++){
			alcancados[i] = 0;
			for(j=1;j<=n;j++) D[i][j] = 1000000;
		}
		alcancados[1] = 1;
		for(i=1;i<=m;i++){
			scanf("%d%d%d", &a, &b, &d);
			D[a][b] = d;
			D[b][a] = d;
		}
		printf("Teste %d\n", teste++);
		total = 1;
		prim();
		printf("\n");
	}
	return 0;
}
