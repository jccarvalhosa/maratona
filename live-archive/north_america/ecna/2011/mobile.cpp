#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
#define M 55555

ll mdc(ll a, ll b) { return a%b ? mdc(b, a%b): b; }
ll mmc(ll a, ll b) { return a*b/mdc(a, b); }

struct frac {
    ll n, d;
    frac(ll a=0, ll b=1): n(a), d(b) {
        ll m = mdc(n, d);
        n /= m;
        d /= m;
    }
    frac operator+(frac f) { return frac(n*f.d + f.n*d, d*f.d); }
    frac operator-(frac f) { return frac(n*f.d - f.n*d, d*f.d); }
    frac operator*(frac f) { return frac(n*f.n, d*f.d); }
    frac operator/(frac f) { return *this * frac(f.d, f.n); }
    bool operator <(const frac &f)const { return n * f.d < f.n * d; }
    bool operator ==(const frac &f)const { return n * f.d == f.n * d; }
};

int n, m, dr[M], dl[M], pai[M], childr[M], childl[M];
frac val[M];

int dfs_up(int v) {
	int p = pai[v];
	if(p == -1) return v;
	if(childl[p] == v) val[p] = val[v] * (frac(dl[p], dr[p]) + 1);
	if(childr[p] == v) val[p] = val[v] * (frac(dr[p], dl[p]) + 1);
	return dfs_up(p);
}

void dfs_down(int v) {
	int vl = childl[v];
	int vr = childr[v];
	val[vr] = val[v] / (frac(dr[v], dl[v]) + 1);
	val[vl] = val[v] / (frac(dl[v], dr[v]) + 1);
	if(vl <= n) dfs_down(vl);
	if(vr <= n) dfs_down(vr);
}

int main() {
	int t=1;
	while(1) {
		cin>>n;
		if(n==0) return 0;
		m = n+1;
		for(int i=1;i<M;i++) pai[i]=-1;
		for(int i=1;i<=n;i++) {
			cin>>dl[i]>>dr[i];
			char typel, typer;
			cin>>typel>>typer;
			int nl, nr;
			cin>>nl>>nr;
			if(typel == 'W') nl += n;
			if(typer == 'W') nr += n;
			pai[nl]=pai[nr]=i;
			childl[i] = nl;
			childr[i] = nr;
		}
		int ini, w;
		cin>>ini>>w;
		ini += n;
		val[ini] = frac(1);
		int root = dfs_up(ini);
		dfs_down(root);
		ll x = 1;
		for(int i=1;i<=m;i++) x = mmc(x, val[n+i].d);
		if(x>=w) w=x;
		else w = w + (x - w%x) % x;
		int ans=0;
		for(int i=1;i<=m;i++) ans += w / val[n+i].d * val[n+i].n;
		printf("Case %d: %d\n", t++, ans);
	}
}
