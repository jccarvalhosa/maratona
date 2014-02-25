#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll M=1000003;
const int N=1e5+10;

ll exp(ll a, ll e) {
	if(!e) return 1;
	if(e&1) return (a*exp(a, e-1))%M;
	return exp((a*a)%M, e/2);
}

ll fat[M+1];

int a[N], d[N], p[N];

struct seg { ll sum, sprod, prod, w; };

seg I[5*N];

void init(int n, int b, int e) {
	I[n].w=0;
	if(b==e) {
		I[n].sum = p[b];
		I[n].prod = d[b];
		I[n].sprod = exp(d[b], p[b]);
	}
	else {
		int m = (b+e)/2;
		init(2*n, b, m);
		init(2*n+1, m+1, e);
		I[n].sum = I[2*n].sum + I[2*n+1].sum;
		I[n].prod = (I[2*n].prod * I[2*n+1].prod)%M;
		I[n].sprod = (I[2*n].sprod * I[2*n+1].sprod)%M;
	}
}

void fix(int n, int b, int e) {
	I[n].sum += (e-b+1)*I[n].w;
	I[n].sprod = (I[n].sprod * exp(I[n].prod, I[n].w))%M;
	if(b!=e) {
		I[2*n].w += I[n].w;
		I[2*n+1].w += I[n].w;
	}
	I[n].w=0;
}

void update(int n, int b, int e, int i, int j, int v) {
	fix(n, b, e);
	if(i<=b && e<=j) {
		I[n].w += v;
		fix(n, b, e);
	}
	else if(i>e || j<b) return;
	else {
		int m = (b+e)/2;
		update(2*n, b, m, i, j, v);
		update(2*n+1, m+1, e, i, j, v);
		I[n].sum = I[2*n].sum + I[2*n+1].sum;
		I[n].sprod = (I[2*n].sprod * I[2*n+1].sprod)%M;
	}
}

seg query(int n, int b, int e, int i, int j) {
	seg ret;
	fix(n, b, e);
	if(i<=b && e<=j) return I[n];
	if(i>e || j<b) {
		ret.sum = -1;
		return ret;
	}
	int m = (b+e)/2;
	seg s1 = query(2*n, b, m, i, j);
	seg s2 = query(2*n+1, m+1, e, i, j);
	if(s1.sum == -1) return s2;
	if(s2.sum == -1) return s1;
	ret.sum = s1.sum+s2.sum;
	ret.sprod = (s1.sprod * s2.sprod)%M;
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	fat[0]=1;
	for(int i=1;i<=M;i++) fat[i] = (i*fat[i-1])%M;
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d", &a[i], &d[i], &p[i]);
		d[i] %= M;
	}
	init(1, 1, n);
	int q;
	scanf("%d", &q);
	while(q--) {
		int t, i, j;
		scanf("%d%d%d", &t, &i, &j);
		if(t==0) {
			seg ans = query(1, 1, n, i, j);
			printf("%lld %lld\n", ans.sum, (fat[min(M, ans.sum)]*ans.sprod)%M);
		}
		else {
			int v;
			scanf("%d", &v);
			update(1, 1, n, i, j, v);
		}
	}
	return 0;
}
