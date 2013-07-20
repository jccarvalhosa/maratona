#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <complex>
using namespace std;

int vis[10000];

int main() {
	int n, m, i, j;
	cin>>n>>m;
	for(i=0;i<m;i++) {
		int a, b;
		cin>>a>>b;
		vis[a]=vis[b]=1;
	}
	for(i=1;i<=n;i++) if(!vis[i]) break;
	cout<<n-1<<endl;
	for(j=1;j<=n;j++) if(j!=i) cout<<i<<" "<<j<<endl;
	return 0;
}
