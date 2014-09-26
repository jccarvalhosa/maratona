#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=1e5+1;
int v[N], vu[N], c[N];
ll dp[N];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) scanf("%d", &v[i]);
	sort(v, v+n);
	for(int i=0;i<n;i++) vu[i] = v[i];
	int tam = unique(vu, vu+n) - vu;
	int j=0;
	for(int i=0;i<tam;i++) {
		while(j < n && v[j] == vu[i]) {
			j++;
			c[i]++;
		}
	}
	dp[tam] = 0;
	dp[tam-1] = 1ll * c[tam-1] * vu[tam-1];
	for(int i=tam-2;i>=0;i--) {
		ll aux = 1ll * c[i] * vu[i];
		if(vu[i+1] != vu[i] + 1) aux += dp[i+1];
		else aux += dp[i+2];
		dp[i] = max(dp[i+1], aux);
	}
	cout << dp[0] << endl;
	return 0;
}
