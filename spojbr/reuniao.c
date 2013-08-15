#include <stdio.h>

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int a, b, d, i, j, D[n][n], max;
	for(i=0;i<n;i++) for(j=0;j<n;j++) D[i][j] = 0;
	for(i=0;i<m;i++){
		scanf("%d%d%d", &a,&b,&d);
		if(D[a][b] == 0 || D[a][b] > d){
			D[a][b] = d;
			D[b][a] = d;
		}
		for(j=0;j<n;j++){
			if(j != a && j != b){
				if(D[j][a] != 0 && D[j][b] > D[j][a] + d){
					D[j][b] = D[j][a] + d;
					D[b][j] = D[j][b];
					j=-1;
				}
				if(D[j][b] != 0 && D[j][a] > D[j][b] + d){
					D[j][a] = D[j][b] + d;
					D[a][j] = D[j][a];
					j=-1;
				}
			}
		}
	}
	max = D[0][1];
	for(i=0;i<n;i++) for(j=i+1;j<n;j++) 	if(max < D[i][j]) max = D[i][j];
	return 0;
}
			
