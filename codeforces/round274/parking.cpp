#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

const int N=2005;
int n, m, k;
char tab[N][N];
int d[N][N], r[N][N], qx[N], qy[N], dp[N][N], sol[N], up[N], down[N];
set<int> s[N];

int main() {
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) scanf("%s", tab[i]);
	for(int i=0;i<k;i++) {
		scanf("%d%d", &qx[i], &qy[i]); 
		qx[i]--; qy[i]--;
		tab[qx[i]][qy[i]]='X';
	}
	for(int i=n-1;i>=0;i--) for(int j=0;j<m;j++) {
		if(tab[i][j] == 'X') d[i][j]=i;
		else if(i==n-1) d[i][j] = i+1;
		else d[i][j] = d[i+1][j];
	}
	for(int j=m-1;j>=0;j--) for(int i=0;i<n;i++) {
		if(tab[i][j] == 'X') r[i][j]=j;
		else if(j==m-1) r[i][j] = j+1;
		else r[i][j] = r[i][j+1];
	}
	for(int i=0;i<n;i++) {
		s[i].insert(-1);
		s[i].insert(m);
	}
	int ans=0;
	for(int i=n-1;i>=0;i--) for(int j=m-1;j>=0;j--) {
		if(tab[i][j] == 'X') {
			dp[i][j]=0;
			s[i].insert(j);
		}
		else if(i==n-1 || j==m-1) dp[i][j]=1;
		else dp[i][j] = min(dp[i+1][j+1]+1, min(r[i][j]-j, d[i][j]-i));
		ans = max(ans, dp[i][j]);
	}
	for(int q=k-1;q>=0;q--) {
		sol[q] = ans;
		int x = qx[q];
		int y = qy[q];
		s[x].erase(y);
		tab[x][y]='.';
		for(int i=0;i<n;i++) {
			up[i] = *s[i].lower_bound(y);
			down[i] = *--s[i].upper_bound(y);
		}
		for(int i=x+1;i<n;i++) {
			up[i] = min(up[i], up[i-1]);
			down[i] = max(down[i], down[i-1]);
		}
		for(int i=x-1;i>=0;i--) {
			up[i] = min(up[i], up[i+1]);
			down[i] = max(down[i], down[i+1]);
		}
		for(int i=0;i<=x;i++) {
			int best=max(ans+1, x-i);
			while(i+best-1<n && min(up[i+best-1], up[i]) - max(down[i+best-1], down[i]) -1 >= best) ans=best++;
		}
	}
	for(int i=0;i<k;i++) printf("%d\n", sol[i]);
	return 0;
}
