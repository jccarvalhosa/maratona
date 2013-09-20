#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 1000000000

using namespace std;

int d[111][111], adj[111][111];
int dp[111][111];
vector<int> p;

int main()
{
	int i, j, k, t=1, n, m, s;
	while(scanf("%d", &n) && n)
	{
		p.clear();
		s=0;
		for(i=0; i<n; i++) for(j=0; j<n; j++)
		{
			scanf("%d", &d[i][j]);
			if(!d[i][j] && i!=j) d[i][j]=INF;
			adj[i][j]=d[i][j];
		}
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			int x;
			scanf("%d", &x);
			p.push_back(x);
		}
		for(k=0; k<n; k++) for(i=0; i<n; i++) for(j=0; j<n; j++) d[i][j]=min(d[i][j], d[i][k]+d[k][j]);

		for(int i=0;i<m;i++) dp[i][i]=0;
		for(int tam=1;tam<m;tam++) {
			for(int i=0;;i++) {
				int j = i+tam;
				if(j >= m) break;
				int s=0;
				for(int f=i;f<j;f++) s += adj[p[f]][p[f+1]];
				if(s == d[p[i]][p[j]]) dp[i][j]=0;
				else {
					dp[i][j] = INF;
					for(int f=i;f<j;f++) dp[i][j] = min(dp[i][j], 1 + dp[i][f] + dp[f+1][j]);
				}
			}
		}
		printf("Case %d: %d\n", t++, dp[0][m-1]);
	}
	return 0;
}
