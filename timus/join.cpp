#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000
typedef long long ll;

int N, n, m;

ll A[111][111], D[111], dp[2][82][82][82];

ll Determinant()
{
	for(int p=0; p<2; p++) for(int u=0; u<n; u++) for(int v=0; v<n; v++) for(int w=0; w<n; w++) dp[p][u][v][w]=0;
	int b=n%2;
	for(int u=0; u<n; u++) dp[b][u][u][0]=1;
	for(int i=0; i<=n-2; i++) for(int u=0; u<n; u++) for(int v=u; v<n; v++) for(int p=0; p<2; p++) for(int w=u+1; w<n; w++) {
		dp[p][u][w][i+1]=(dp[p][u][w][i+1]+dp[p][u][v][i]*A[v][w])%MOD;
		dp[1-p][w][w][i+1]=(dp[1-p][w][w][i+1]+dp[p][u][v][i]*A[v][u])%MOD;
	}
	ll x[2]={0, 0};
	for(int u=0; u<n; u++) for(int v=u; v<n; v++) {
		x[0]=(x[0]+dp[1][u][v][n-1]*A[v][u])%MOD;
		x[1]=(x[1]+dp[0][u][v][n-1]*A[v][u])%MOD;
	}
	return (x[0]-x[1]+MOD)%MOD;
}

int nn, mm, vis[111][111];
int dx[]={0, 1, 0, -1};
int dy[]={1, 0, -1, 0};
char g[111][111];

void dfs(int x, int y) {
	int i, du, dv;
	vis[x][y]=n++;
	for(i=0; i<4; i++) {
		du=x+dx[i];
		dv=y+dy[i];
		if(du>=0 && du<nn && dv>=0 && dv<mm && vis[du][dv]==-1 && g[du][dv]!='*') dfs(du, dv);
	}
}

int main()
{
	int i, j, k, di, dj, f, cnt=0;
	scanf("%d %d", &nn, &mm);
	n=f=0;
	memset(A, 0, sizeof(A));
	memset(D, 0, sizeof(D));
	for(i=0; i<nn; i++) {
		scanf("%s", g[i]);
		for(j=0; j<mm; j++)
		{
			vis[i][j]=-1;
			if(g[i][j]=='.') cnt++;
		}
	}
	if(cnt==1)
	{
		printf("1\n");
		return 0;
	}
	for(i=0; i<nn; i++) for(j=0; j<mm; j++) if(g[i][j]=='.' && vis[i][j]==-1) dfs(i, j);
	for(i=0; i<nn; i++) for(j=0; j<mm; j++) if(vis[i][j]>-1) {
		for(k=0; k<4; k++) {
			di=i+dx[k];
			dj=j+dy[k];
			if(di>=0 && di<nn && dj>=0 && dj<mm && vis[di][dj]>-1) {
				A[vis[i][j]][vis[di][dj]]=A[vis[di][dj]][vis[i][j]]=MOD-1;
				D[vis[i][j]]++;
				D[vis[di][dj]]++;
			}
		}
		vis[i][j]=-1;
	}
	for(i=0; i<n; i++) A[i][i]=D[i];
	n--;
	printf("%lld\n", Determinant());
	return 0;
}
