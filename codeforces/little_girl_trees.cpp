#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 100001
typedef long long ll;

vector<int> adj[MAX], tree[MAX];
int n, b=0, branch[MAX], tam[MAX], ord[MAX], vis[MAX];

void dfs(int v) {
    int i, u;
    vis[v] = 1;
	if(v==1) ord[v]=1;
    else ord[v] = ++tam[b];
    branch[v] = b;
    for(i=0;i<adj[v].size();i++) {
        u = adj[v][i];
        if(v == 1) {
            b = i+1;
			tam[b]=1;
        }
        if(!vis[u]) dfs(u);
    }
}

void update(int t, int p, int v) {
	for(; p; p -= p&-p) tree[t][p] += v;
}

void add(int v, int x, int d) {
	if(v == 1) update(0, d+1, x);
	else {
		update(branch[v], min(tam[branch[v]], ord[v]+d), x);
		if(ord[v]-d > 1) update(branch[v], ord[v]-d-1, -x);
		else {
			int m = d-ord[v]+2;
			update(0, m, x);
			update(branch[v], min(tam[branch[v]], m), -x);
		}
	}
}

ll query(int t, int p) {
	ll ret=0;
	for(; p<=tam[t]; p += p&-p) ret += tree[t][p];
	return ret;
}

ll value(int v) {
    if(v == 1) return query(0, 1);
    return query(0, ord[v]) + query(branch[v], ord[v]);
}

int main() {
    int q, u, v, i, j, c, x, d;
    scanf("%d%d", &n, &q);
    for(i=0;i<n-1;i++) {
        scanf("%d%d", &u, &v);
    	adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(i=1;i<=n;i++) vis[i]=0;
    dfs(1);
    tam[0] = n;
    for(i=0;i<=b;i++) {
        tree[i].resize(tam[i]+1);
        for(j=0;j<=tam[i];j++) tree[i][j] = 0;
    }
    while(q--) {
        scanf("%d", &c);
        if(!c) {
            scanf("%d%d%d", &v, &x, &d);
            add(v, x, d);       
        }
        else {
            scanf("%d", &v);
            cout << value(v) << endl;
        }
    }
    return 0;
}
