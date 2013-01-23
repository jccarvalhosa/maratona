#include <cstdio>
#define MAX 100001

typedef long long ll;

int B, L, P;
ll hash[MAX], val[MAX], exp[MAX], inv[MAX];

ll pow(int n, int e) {
	ll resp=1, aux=n%P;
	while(e != 0) {
		if(e % 2 == 1) resp = (resp * aux) % P;
		aux = (aux * aux) % P;
		e /= 2;
	}
	return resp;
}

void update(int p, ll v) {
	ll delta = (v - val[p] + P) % P;
	val[p] = v;
	while(p <= L) {
		hash[p] = (hash[p] + delta) % P;
		p = p + (p & -p);
	}
}

ll query(int p) {
	ll resp = 0;
	while(p > 0) {
		resp = (resp + hash[p]) % P;
		p = p - (p & -p);
	}
	return resp;
}

int main() {
	int N, i, p, a, b; 
	ll Binv, v;
	char c;
	while(scanf("%d%d%d%d", &B, &P, &L, &N) && B) {
		Binv = pow(B, P-2);
		exp[0] = inv[0] = 1;
		for(i=1;i<=L;i++) {
			exp[i] = (exp[i-1] * B) % P;
			inv[i] = (inv[i-1] * Binv) % P;
		}
		for(i=0;i<=L;i++) hash[i] = val[i] = 0;
		for(i=0;i<N;i++) {
			scanf(" %c ", &c);
			if(c == 'E') {
				scanf("%d %lld", &p, &v);
				v = (v * exp[L-p]) % P;
				update(p, v);
			}
			if(c == 'H') {
				scanf("%d %d", &a, &b);
				v = ((query(b) - query(a-1)) % P + P) % P;
				v = (v * inv[L-b]) % P;
				printf("%lld\n", v);
			}
		}
		printf("-\n");
	}
	return 0;
}
