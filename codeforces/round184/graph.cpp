#include <iostream>
#include <cstdio>
#include <cstring>
#define M 1000000007
using namespace std;

int exp(int n, int e) {
	if(e==0) return 1;
	if(e % 2 == 0) return exp((1ll*n*n)%M, e/2);
	return (1ll * n * exp(n, e-1)) % M;
}

int main() {
	int i, f, ini, fim, n, m, k, a, b, c=0, t, sum;
	cin>>n>>m>>k;
	fim=0;
	ini=n+1;
	for(i=0;i<m;i++) {
		cin>>a>>b;
		if(b-a == 1) continue;
		if(b-a != k+1) break;
		ini = min(ini, a);
		fim = max(fim, a);
		c++;
	}
	if(i != m || fim-ini > k) cout << 0 << endl;
	else {
		sum=0;
		for(i=1;i<ini;i++) {
			if(i+k+1 <= fim) continue;
			f = min(n-k, i+k+1);
			t = f-i-1-c;
			if(t >= 0) sum = (sum + exp(2, t)) % M;
		}
		if(fim == 0) sum++;
		else {
			f = min(n-k, ini+k+1);
			t = f-ini-1-c+1;
			sum = (sum + exp(2, t)) % M;
		}
		cout << sum << endl;
	}
	return 0;
}
