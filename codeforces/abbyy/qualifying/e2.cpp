#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n, t[200011][2], val[200011], fib[200011], coef[200011][2];

int mod(long long a, int m=1000000000) { return (a%m + m) % m; }

void update(int i, int v) {
	int r=i, delta=mod(v-val[i]);
	val[i] = v;
	for(; r<=n; r += r&-r) {
		t[r][0] = mod(t[r][0] + 1ll*delta*fib[i-1]);
		t[r][1] = mod(t[r][1] + 1ll*delta*fib[i]);
	}
}

int query(int i, int type) {
	int ret=0;
	for(; i ; i -= i&-i) ret = mod(ret + t[i][type]);
	return ret;
}

void precalc() {
	int i, j;
	fib[0] = fib[1] = 1;
	for(i=2;i<=n;i++) fib[i] = mod(fib[i-1]+fib[i-2]);
	coef[0][0] = 1; coef[0][1] = 0;
	coef[1][0] = 0; coef[1][1] = 1;
	for(i=2;i<=n;i++) for(j=0;j<2;j++) coef[i][j] = mod(coef[i-2][j] - coef[i-1][j]);
}

int main() {
	int m, a, i, t, x, v, l, r, q0, q1;
	cin>>n>>m;
	precalc();
	for(i=1;i<=n;i++) {
		cin>>a;
		update(i, a);
	}
	while(m--) {
		cin>>t;
		if(t==1) {
			cin>>x>>v;
			update(x, v);
		}
		if(t==2) {
			cin>>l>>r;
			q0 = mod(query(r, 1) - query(l-1, 1));
			q1 = mod(query(r, 0) - query(l-1, 0));
			cout << mod(1ll*q0*coef[l][0] + 1ll*q1*coef[l][1]) << endl;
		}
	}
	return 0;
}
