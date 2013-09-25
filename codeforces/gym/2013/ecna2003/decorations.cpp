#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

long long dp[666][666], adj[666][666];
string a[666];
int m, l, n;

bool match(int i, int j)
{
	for(int k=1;k<a[i].size();k++) if(a[i][k] != a[j][k-1]) return 0;
	return 1;
}

int main()
{
	while(scanf("%d%d%d", &n, &l, &m) && (n|l|m))
	{
		for(int i=0;i<m;i++) cin >> a[i];
		int s = a[0].size();
		memset(adj,0,sizeof(adj));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<m;i++) for(int j=0;j<m;j++) if(match(i,j)) adj[i][j] = 1;
		for(int i=0;i<m;i++) dp[0][i] = 1;
		for(int i=0;i<(l-s);i++) for(int j=0;j<m;j++) for(int k=0;k<m;k++) if(adj[j][k]) dp[i+1][k] += dp[i][j];
		long long r=0;
		for(int i=0;i<m;i++) r += dp[l-s][i];
		cout << r << endl;
	}
	return 0;
}
