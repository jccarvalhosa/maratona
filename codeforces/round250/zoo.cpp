#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N=1e5+10;
int n, c[N], f[N], sz[N];

struct edge {
	int a, b, m;
	bool operator<(const edge &e) const { return m < e.m; }
};

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

edge e[N];

int main() {
	int m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<m;i++) {
		int a, b;
		cin>>a>>b;a--;b--; 
		e[i].a = a;
		e[i].b = b;
		e[i].m = min(c[a], c[b]);
	}
	sort(e, e+m);
	reverse(e, e+m);
	for(int i=0;i<n;i++) {
		sz[i] = 1;
		f[i] = i;
	}
	ll ans=0;
	for(int i=0;i<m;i++) {
		int fa = find(e[i].a);
		int fb = find(e[i].b);
		if(fa == fb) continue;
		ans += 1ll * sz[fa] * sz[fb] * e[i].m;
		sz[fa] += sz[fb];
		f[fb] = fa;
	}
	printf("%.12lf\n", 2.0*ans/n/(n-1));
	return 0;
}
