#include <stdio.h>

int adj[150][150], valor[150];
void dfs(int ini, int p){
	int i;
	for(i=0;i<p;i++){
		if(adj[ini][i]){
			if(valor[i] == -1){
				dfs(i, p);
			}
			if(valor[ini] < valor[i] + 1) valor[ini] = valor[i] + 1;
		}
	}
	if(valor[ini] == -1) valor[ini] = 0;
}

int main(){
	int j, k, p,l,i, teste=1, altitude[150], x, y;
	while(scanf("%d%d%d", &p, &l, &i) && p){
		i--;
		for(k=0;k<p;k++) scanf("%d", &altitude[k]);
		for(j=0;j<p;j++) for(k=0;k<p;k++) adj[j][k]=0;
		for(k=0;k<p;k++) valor[k]=-1;
		for(k=0;k<l;k++){
			scanf("%d%d", &x, &y);
			x--;
			y--;
			if(altitude[x] > altitude[y]){
				adj[x][y]=1;
			}
		}
		dfs(i, p);
		printf("Teste %d\n", teste++);
		printf("%d\n\n", valor[i]);
	}
	return 0;
}	



