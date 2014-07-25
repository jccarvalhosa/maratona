#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pii;

const int N=1e5+1;
vector<int> adj[N];
set<pii> black[N];
int c=1, color[N], chain[N], dep[N], head[N], pi[N], heavy[N];

int pos(int v) { return dep[v] - dep[head[v]] + 1; }

int hld(int v, int p) {
    int m=-1, sum=0, smax=0;
    for(int i=0;i<adj[v].size();i++) {
        int u = adj[v][i];
        if(u==p) continue;
        int s = hld(u, v);
        sum += s;
        if(s > smax) smax = s, m = u;
    }
    if(m != -1) heavy[m] = 1;
    return sum+1;
}

void dfs(int v, int p, int d, int h, int ch) {
    pi[v] = p;
    chain[v] = ch;
    dep[v] = d;
    head[v] = h;
    for(int i=0;i<adj[v].size();i++) {
        int u = adj[v][i];
        if(u==p) continue;
        if(heavy[u]) dfs(u, v, d+1, h, ch);
        else dfs(u, v, d+1, u, ++c);
    }
}

int change(int v) {
    color[v] ^= 1;
    if(color[v]) {
        black[chain[v]].insert(pii(pos(v), v));
    }
    else {
        black[chain[v]].erase(pii(pos(v), v));
    }
}

int query(int v) {
    int ret = -1;
    while(1) {
        if(!black[chain[v]].empty()) {
            pii b = *black[chain[v]].begin();
            if(b.first <= pos(v)) ret = b.second;
        }
        if(v == 1) break;
        v = pi[head[v]];
    }
    return ret;
}

int main() {
    int n, q;
    cin>>n>>q;
    for(int i=1;i<n;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    hld(1, 1);
    dfs(1, 1, 1, 1, 1);
    while(q--) {
        int t, v;
        scanf("%d%d", &t, &v);
        if(t==1) printf("%d\n", query(v));
        else change(v);
    }
    return 0;
}
