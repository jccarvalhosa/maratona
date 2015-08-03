#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<double, ll> pii;

double dp[31][31][201];
int v[31];

int main() {
	int n, k;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j][0]=v[i]>v[j];
	for(int t=1;t<=k;t++) for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
		int total = 0;
		for(int p1=0;p1<n;p1++) for(int p2=p1;p2<n;p2++) {
			total++;
			int ni=i, nj=j;
			if(i>=p1 && i<=p2) ni = p1+p2-i;
			if(j>=p1 && j<=p2) nj = p1+p2-j;
			dp[i][j][t] += dp[ni][nj][t-1];
		}
		dp[i][j][t] /= total;
	}
	double p=0;
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) p += dp[i][j][k];
	printf("%.12lf\n", p);
	return 0;
}
