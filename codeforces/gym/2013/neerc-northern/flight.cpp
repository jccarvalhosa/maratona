#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int p[1111], dp[55][1111], d[1111], c[1111][1111], t[1111];
int n, s;

void add(int x, int v) { for(;x;x-=x&-x) t[x] += v; }
int sum(int x) { int ret=0; for(;x<=s;x+=x&-x) ret += t[x];	return ret; }

int main() {
	int k;
	ifstream in("flight.in");
	ofstream out("flight.out");
	in >> n >> s >> k;
	for(int i=1;i<=n;i++) in >> p[i];
	for(int i=1;i<=s;i++) {
		memset(t,0,sizeof(t));
		memset(d,0,sizeof(d));
		for(int j=1;j<=n;j++) {
			if(p[j] >= i) {	add(p[j],-1); add(s,1); }
			d[p[j]] += sum(p[j]);
		}
		c[i][i] = 0;
		for(int j=i+1;j<=s;j++) c[i][j] = c[i][j-1] + d[j];
	}
	for(int i=1;i<=s;i++) dp[1][i] = c[i][s];
	for(int i=2;i<=k;i++) for(int j=1;j<=s;j++)	{
		dp[i][j] = 1000000000;
		for(int l=j+1;l<=s;l++) dp[i][j] = min(dp[i][j],dp[i-1][l]+c[j][l-1]);
	}
	out << dp[k][1];
	return 0;
}
