#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=3e5+10;
const int M=1e9+7;
int n, d[N], ini[N], fim[N], pos[N], c;
int tx[N], tc[N];
vector<int> adj[N];

ll val(int *t, int a) { ll ret=0; for(;a<N;a+=a&-a) ret = (ret+t[a])%M; return ret;}
void add(int *t, int a, int v) { for(;a;a-=a&-a) t[a] = (t[a]+v)%M; }
void add(int *t, int a, int b, int v) { add(t, b, v); add(t, a-1, -v); }

void dfs(int v, int p) {
	if(p!=-1) d[v] = d[p]+1;
	ini[v] = pos[v] = c++;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(u==p) continue;
		dfs(u, v);
	}
	fim[v] = c-1;
}

int main() {
	cin>>n;
	for(int i=2;i<=n;i++) {
		int a;
		scanf("%d", &a);
		adj[a].push_back(i);
	}
	c=1;
	dfs(1, -1);
	int q;
	cin>>q;
	while(q--) {
		int t, v;
		scanf("%d %d", &t, &v);
		if(t==1) {
			int x, k;
			scanf("%d%d", &x, &k);
			add(tc, ini[v], fim[v], (x+1ll*d[v]*k)%M);
			add(tx, ini[v], fim[v], -k);
		}
		else cout<<(((val(tc, pos[v]) + d[v]*val(tx, pos[v]))%M)+M)%M<<"\n";
	}
	return 0;
}
