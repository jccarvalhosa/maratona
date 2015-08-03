#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, pii> pp;

double dp[101][101][2];
vector<pp> adj[101][101];
int v[101];
int cont[10001];

int main() {
	int n, k;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>v[i];
	if(k >= 850) {
		cout << n*(n-1)/4.0 << endl;
		return 0;
	}
	double total = n*(n+1)/2;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
		memset(cont, 0, sizeof(cont));
		for(int p1=0;p1<n;p1++) for(int p2=p1;p2<n;p2++) {
			int ni=i, nj=j;
			if(i>=p1 && i<=p2) ni = p1+p2-i;
			if(j>=p1 && j<=p2) nj = p1+p2-j;
			cont[ni*n+nj]++;
		}
		for(int ni=0;ni<n;ni++) for(int nj=ni+1;nj<n;nj++) if(cont[ni*n+nj]) {
			adj[ni][nj].push_back(pp(cont[ni*n+nj]/total, pii(i, j)));
		}
	}
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j][0]=v[i]>v[j];
	for(int t=1;t<=k;t++) {
		for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
			dp[i][j][t&1]=0;
			for(int c=0;c<adj[i][j].size();c++) {
				dp[i][j][t&1] += dp[adj[i][j][c].second.first][adj[i][j][c].second.second][t+1&1] * adj[i][j][c].first;
			}
			dp[j][i][t&1] = 1 - dp[i][j][t&1];
		}
	}
	double ans=0;
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) ans += dp[i][j][k&1];
	printf("%.12lf\n", ans);
	return 0;
}
