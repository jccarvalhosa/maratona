#include <cstdio>
#include <iostream>
using namespace std;
#define M 1000000007

int sol=0;
int fat[1000001];

int exp(int a, int e) {
	if(e == 0) return 1;
	if(e % 2 == 0) return exp((1ll*a*a) % M, e/2);
	return (1ll * a * exp(a, e-1)) % M;
}

int inv(int a) {
	return exp(a, M-2);
}

void add(int na, int nb) {
	sol = (sol + 1ll * ((1ll * fat[na+nb] * inv(fat[na])) % M) * inv(fat[nb])) % M;
}

int main() {
	int a, b, n, na, nb, sum, m, i, x;
	cin>>a>>b>>n;
	fat[0] = 1;
	for(i=1;i<=n;i++) fat[i] = (1ll * i * fat[i-1]) % M;
	m = n*b;
	for(sum = 1; sum<=m; sum++) {
		for(i=sum; i != 0; i /= 10) if(i % 10 != a && i % 10 != b) break;
		if(i != 0 || ((m - sum) % (b-a) != 0)) continue;
		x = (m - sum) / (b-a);
		if(x < 0 || n-x < 0) continue;
		add(x, n-x);
	}
	cout << sol << endl;
	return 0;
}
