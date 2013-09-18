#include <cstdio>
#include <cstring>
typedef long long ll;
#define m 1000000

struct Matrix { ll v[2][2]; };

Matrix mul(Matrix a, Matrix b) {
	Matrix ans;
	memset(ans.v, 0, sizeof(ans.v));
	for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) {
		ans.v[i][j] += a.v[i][k] * b.v[k][j];
		ans.v[i][j] %= m;
	}
	return ans;
}

Matrix exp(Matrix M, ll e) {
	if(e==0) {
		Matrix I;
		I.v[0][0]=I.v[1][1]=1;
		I.v[1][0]=I.v[0][1]=0;
		return I;
	}
	if(e%2==0) return exp(mul(M, M), e/2);
	return mul(M, exp(M, e-1));
}

int main() {
	ll n, k, l;
	while(scanf("%lld %lld %lld", &n, &k, &l) != EOF) {
		n /= 5;
		k %= m;
		l %= m;
		Matrix M;
		M.v[0][0] = k; M.v[0][1] = l;
		M.v[1][0] = 1; M.v[1][1] = 0;
		M = exp(M, n-1);
		ll ans = M.v[0][0]*k + M.v[0][1];
		ans %= m;
		printf("%06lld\n", ans);
	}
	return 0;
}
