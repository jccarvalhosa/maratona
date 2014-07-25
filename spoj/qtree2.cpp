#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

const int N=1e4+1;
const int L=15;
int n, pi[N][L], di[N], dep[N];
vector<pii> adj[N];

int dfs(int v, int p, int d) {
	pi[v][0] = p;
	dep[v] = d;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i].first;
		if(u==p) di[v] = adj[v][i].second + di[p];
		else dfs(u, v, d+1);
	}
}

int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	int d = dep[a] - dep[b];
	for(int i=0;i<L;i++) if(d & (1<<i)) a = pi[a][i];
	if(a==b) return a;
	for(int i=L-1;i>=0;i--) if(pi[a][i] != pi[b][i]) a=pi[a][i], b=pi[b][i];
	return pi[a][0];
}

int par(int a, int k) {
	for(int i=0;i<L;i++) if(k & (1<<i)) a = pi[a][i];
	return a;
}

int kth(int a, int b, int k) {
	if(k==1) return a;
	int c = lca(a, b);
	if(k <= dep[a] - dep[c] + 1) return par(a, k-1);
	k -= dep[a] - dep[c];
	k = dep[b] - dep[c] - k + 2;
	return par(b, k-1);
}

int dist(int a, int b) { return di[a] + di[b] - 2*di[lca(a, b)];}

int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1;i<=n;i++) adj[i].clear();
		for(int i=1;i<n;i++) {
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d);
			adj[a].push_back(pii(b, d));
			adj[b].push_back(pii(a, d));
		}
		dfs(1, 1, 1);
		for(int j=1;j<L;j++) for(int i=1;i<=n;i++) pi[i][j] = pi[pi[i][j-1]][j-1];
		char op[10];
		while(scanf("%s", op) && op[1] != 'O') {
			if(op[1] == 'T') {
				int a, b, k;
				scanf("%d%d%d", &a, &b, &k);
				printf("%d\n", kth(a, b, k));
			}
			else {
				int a, b;
				scanf("%d%d", &a, &b);
				printf("%d\n", dist(a, b));
			}
		}
	}
	return 0;
}
