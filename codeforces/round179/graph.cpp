#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[501][501], d[501][501], ord[501];
long long ans[501];

int main() {
	int n, i, j, k, v, u, w;
	cin>>n;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) cin>>a[i][j];
	for(i=1;i<=n;i++) cin>>ord[i];
	ans[n]=0;
	for(i=n-1;i>=1;i--) {
		v = ord[i];
		for(j=i+1;j<=n;j++) {
			u = ord[j];
			d[v][u] = a[v][u];
			d[u][v] = a[u][v];
		}
		for(j=i+1;j<=n;j++) for(k=i+1;k<=n;k++) {
			u=ord[j]; w=ord[k];
			d[v][w] = min(d[v][w], d[v][u] + d[u][w]);
			d[w][v] = min(d[w][v], d[w][u] + d[u][v]);
		}
		for(j=i+1;j<=n;j++) for(k=i+1;k<=n;k++) {
			u=ord[j]; w=ord[k];
			d[u][w] = min(d[u][w], d[u][v] + d[v][w]);
		}
		for(j=1;j<=n;j++) for(k=1;k<=n;k++) ans[i] += d[j][k];
	}
	for(i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
