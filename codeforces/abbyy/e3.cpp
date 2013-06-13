#include <cstdio>
#include <iostream>
#include <cstring>
#define MOD 1000000000
using namespace std;

int n, fib[200011], coef[200011][2], fibsum[200011];

inline int mod(long long a, int m=MOD) { return (a%m + m) % m; }

struct inter {
	int sum, fibsum0, fibsum1, w;
	inter(int sum=0, int fibsum0=0, int fibsum1=0, int w=0): sum(sum), fibsum0(fibsum0), fibsum1(fibsum1), w(w) {}
};

struct inter M[600000];

inline void fix(int n, int b, int e) {
	if(M[n].w) {
		/*change*/
		M[n].sum = mod(M[n].sum + 1ll*M[n].w*(e-b+1));
		M[n].fibsum0 = mod(M[n].fibsum0 + 1ll*M[n].w*(fibsum[e]-fibsum[b-1]));
		M[n].fibsum1 = mod(M[n].fibsum1 + 1ll*M[n].w*(fibsum[e+1]-fibsum[b]));
		if(b != e) {
			/*propagate*/
			M[2*n].w = (M[2*n].w + M[n].w) % MOD;
			M[2*n+1].w = (M[2*n+1].w + M[n].w) % MOD;
		}
		M[n].w = 0;
	}
}

inter query(int n, int b, int e, int i, int j) {
	fix(n, b, e);
	if(j<b || i>e) return inter();
	if(i<=b && j>=e) return M[n];
	inter p1 = query(2*n, b, (b+e)/2, i, j);
	inter p2 = query(2*n+1, (b+e)/2+1, e, i, j);
	return inter((p1.sum+p2.sum)%MOD, (p1.fibsum0+p2.fibsum0)%MOD, (p1.fibsum1+p2.fibsum1)%MOD);
}

void update(int n, int b, int e, int i, int j, int v) {
	if(i<=b && j>=e) {
		M[n].w = (M[n].w+v)%MOD;
		fix(n, b, e);
	}
	else if(j<b || i>e) { fix(n, b, e); }
	else {
		fix(n, b, e);
		update(2*n, b, (b+e)/2, i, j, v);
		update(2*n+1, (b+e)/2+1, e, i, j, v);
		/*sync*/
		M[n].sum = (M[2*n].sum + M[2*n+1].sum) % MOD;
		M[n].fibsum0 = (M[2*n].fibsum0 + M[2*n+1].fibsum0) % MOD;
		M[n].fibsum1 = (M[2*n].fibsum1 + M[2*n+1].fibsum1) % MOD;
	}
}

void precalc() {
	int i, j;
	fib[0] = fib[1] = 1;
	for(i=2;i<=n;i++) fib[i] = mod(fib[i-1]+fib[i-2]);
	fibsum[1] = 1;
	for(i=2;i<=n+1;i++) fibsum[i] = mod(fibsum[i-1]+fib[i-1]);
	coef[0][0] = 1; coef[0][1] = 0;
	coef[1][0] = 0; coef[1][1] = 1;
	for(i=2;i<=n;i++) for(j=0;j<2;j++) coef[i][j] = mod(coef[i-2][j] - coef[i-1][j]);
}

int main() {
	int m, a, i, t, x, v, l, r;
	inter q;
	cin>>n>>m;
	precalc();
	for(i=1;i<=n;i++) {
		cin>>a;
		update(1, 1, n, i, i, a);
	}
	while(m--) {
		cin>>t;
		if(t==1) {
			cin>>x>>v;
			q = query(1, 1, n, x, x);
			update(1, 1, n, x, x, mod(v-q.sum));
		}
		if(t==2) {
			cin>>l>>r;
			q = query(1, 1, n, l, r);
			cout << mod(1ll*q.fibsum1*coef[l][0] + 1ll*q.fibsum0*coef[l][1]) << endl;
		}
		if(t==3) {
			cin>>l>>r>>v;
			update(1, 1, n, l, r, v);
		}
	}
	return 0;
}
