#include <cstdio>
#include <cstring>

int n, N, adj[15][15], cor[15], vis[15];

int valid(int s) {
	for(int i=0;i<s;i++) if(adj[s][i] && cor[i] == cor[s]) return 0;
	return 1;
}

int go(int s) {
	if(s == n) return 1;
	for(int i=0;i<N;i++) {
		cor[s]=i;
		if(!valid(s)) continue;
		if(go(s+1)) return 1;
	}
	return 0;
}

int main()
{
	int i, j;
	double x[15], y[15];
	int t=1;
	while(scanf("%d", &n) && n)
	{
		memset(adj, 0, sizeof(adj));
		for(i=0; i<n; i++) scanf("%lf %lf", &x[i], &y[i]);
		for(i=0; i<n; i++) for(j=i+1; j<n; j++) if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=400.0) adj[i][j]=adj[j][i]=1;
		cor[0]=0;
		for(N=1;N<=4;N++) if(go(1)) break;
		printf("The towers in case %d can be covered in %d frequencies.\n", t++, N);
	}
	return 0;
}
