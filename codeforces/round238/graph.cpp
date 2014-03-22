#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;

struct tri {
	int a, b, c;
	tri(){}
	tri(int a, int b, int c) : a(a), b(b), c(c) {}
};

vector<tri> ans;
set<pii> s;

inline int exists(int a, int b) {
	if(a > b) swap(a, b);
	return s.count(pii(a, b));
}

inline void add(int a, int b) {
	if(a > b) swap(a, b);
	s.insert(pii(a, b));
}

const int N=1e5+10;
vector<int> adj[N];
int n, m, vis[N];

int dfs(int v, int p) {
	vis[v] = 1;
	int w = -1;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(u == p) continue;
		if(vis[u] || dfs(u, v)) {
			if(exists(v, u)) continue;
			if(w == -1) w = u;
			else {
				ans.push_back(tri(w, v, u));
				add(w, v);
				add(v, u);
				w = -1;
			}
		}
	}
	if(w == -1) {
		return 1;
	}
	else {
		ans.push_back(tri(w, v, p));
		add(w, v);
		add(v, p);
		return 0;
	}
}

int solve() {
	for(int i=1;i<=n;i++) if(!vis[i]) if(dfs(i, -1) == 0) return 0;
	return 1;
}

int main() {
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if(solve()) {
		for(int i=0;i<ans.size();i++) printf("%d %d %d\n", ans[i].a, ans[i].b, ans[i].c);
	}
	else {
		printf("No solution\n");
	}
	return 0;
}
