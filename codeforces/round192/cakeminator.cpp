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

string G[100];

int main() {
	int n, m, i, j;
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>G[i];
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) if(G[i][j] == 'S') break;
		if(j==m) for(j=0;j<m;j++) G[i][j] = 'X';
	}
	for(j=0;j<m;j++) {
		for(i=0;i<n;i++) if(G[i][j] == 'S') break;
		if(i==n) for(i=0;i<n;i++) G[i][j] = 'X';
	}
	int ans=0;
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) if(G[i][j]=='X') ans++;
	}
	cout<<ans<<endl;
	return 0;
}
