#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

const int N=11111;
int n, c, pi[N][30], dep[N], head[N], chain[N], heavy[N], cont[N], cost[N];
vector<int> A[N];
vector<pii> adj[N];

int query(int c, int n, int b, int e, int i, int j) {
	if(j < b || i > e) return 0;
	if(b >= i && e <= j) return A[c][n];
	int m = (b+e)/2;
	return max(query(c, 2*n, b, m, i, j), query(c, 2*n+1, m+1, e, i, j));
}

int query(int c, int pa, int pb) { return query(c, 1, 1, cont[c], pa, pb); }

void update(int c, int n, int b, int e, int p, int v) {
	if(b==e) A[c][n] = v;
	else {
		int m = (b+e)/2;
		if(p <= m) update(c, 2*n, b, m, p, v);
		else update(c, 2*n+1, m+1, e, p, v);
		A[c][n] = max(A[c][2*n], A[c][2*n+1]);
	}
}

void update(int c, int p, int v) { update(c, 1, 1, cont[c], p, v); }

int hld(int v, int p) {
	int m=-1, smax=0, sum=0;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i].first;
		if(u==p) continue;
		int s = hld(u, v);
		sum += s;
		if(s > smax) {
			smax = s;
			m = u;
		}
	}
	if(m != -1) heavy[m] = 1;
	return sum+1;
}

void dfs(int v, int p, int d, int h, int ch) {
	pi[v][0]=p;
	dep[v]=d;
	head[v]=h;
	chain[v]=ch;
	cont[ch]++; 
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i].first;
		int w = adj[v][i].second;
		if(u==p) cost[v] = w;
		else if(heavy[u]) dfs(u, v, d+1, h, ch);
		else {
			c++;
			cont[c]=0;
			dfs(u, v, d+1, u, c);
		}
	}
}

int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	int d = dep[a] - dep[b];
	for(int i=0;i<15;i++) if(d & (1<<i)) a = pi[a][i];
	if(a==b) return a;
	for(int i=14;i>=0;i--) if(pi[a][i] != pi[b][i]) a = pi[a][i], b = pi[b][i];
	return pi[a][0];
}

inline int pos(int a) { return dep[a] - dep[head[a]] + 1; }

int query_up(int a, int c) {
	int ans=0;
	while(chain[a] != chain[c]) {
		ans = max(ans, query(chain[a], 1, pos(a)));
		a = pi[head[a]][0];
	}
	if(a == c) return ans;
	return max(ans, query(chain[a], pos(c)+1, pos(a)));
}

int query(int a, int b) {
	int c = lca(a, b);
	return max(query_up(a, c), query_up(b, c));
}

int from[N], to[N];

int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		int a, b, d;
		for(int i=1;i<=n;i++) adj[i].clear();
		for(int i=1;i<=n;i++) heavy[i] = 0;
		for(int i=1;i<=n-1;i++) {
			scanf("%d%d%d", &a, &b, &d);
			from[i]=a;
			to[i]=b;
			adj[a].push_back(pii(b, d));
			adj[b].push_back(pii(a, d));
		}
		hld(1, 1);
		c=1;
		cont[1]=0;
		dfs(1, 1, 1, 1, 1);
		for(int i=1;i<=c;i++) A[i] = vector<int>(5*cont[i], 0);
		for(int i=1;i<=n;i++) update(chain[i], pos(i), cost[i]);
		for(int j=1;j<30;j++) for(int i=1;i<=n;i++) pi[i][j] = pi[pi[i][j-1]][j-1];
		char s[11];
		while(scanf("%s", s) && s[0] != 'D') {
			scanf("%d%d", &a, &b);
			if(s[0] == 'C') {
				int x = from[a];
				int y = to[a];
				if(pi[x][0] != y) swap(x, y);
				update(chain[x], pos(x), b);
			}
			else {
				printf("%d\n", query(a, b));
			}
		}
	}
	return 0;
}
