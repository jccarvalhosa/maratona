#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N=1e5+10;

struct edge { int a, b, d, ia, ib; };
edge e[N];

struct inode { 
	int pos, side; ll val; 
	bool operator <(const inode &i)const { return val > i.val; }
};
inode ino[2*N];

int T[5*N];

void init(int n, int b, int e) {
	T[n] = e-b+1;
	if(b!=e) {
		int m = (b+e)/2;
		init(2*n, b, m);
		init(2*n+1, m+1, e);
	}
}

int query(int n, int b, int e, int i, int j) {
	if(T[n] == 0) return 0;
	if(e < i || b > j) return 0;
	if(b >= i && e <= j) return T[n];
	int m = (b+e)/2;
	return query(2*n, b, m, i, j) + query(2*n+1, m+1, e, i, j);
}

void update(int n, int b, int e, int i, int j) {
	if(T[n] == 0) return;
	if(e < i || b > j) return;
	if(b >= i && e <= j) T[n]=0;
	else {
		int m = (b+e)/2;
		update(2*n, b, m, i, j);
		update(2*n+1, m+1, e, i, j);
		T[n] = T[2*n] + T[2*n+1];
	}
}

int n, c;
vector<int> adj[N];
vector<pii> child[N];
pii range[N];
int crit[N], id[N];

int nchild(int v, int i) {
	if(child[v][i].first != -1) return child[v][i].second - child[v][i].first + 1;
	return n - (range[v].second - range[v].first + 1);
}

void dfs(int v, int p) {
	id[v] = ++c;
	int l = id[v], r = id[v];
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(u == p) {
			child[v].push_back(pii(-1, -1));
		} else {
			dfs(u, v);
			child[v].push_back(range[u]);
			l = min(l, range[u].first);
			r = max(r, range[u].second);
		}
	}
	range[v] = pii(l, r);
}

int main() {
	cin>>n;
	init(1, 1, n);
	for(int i=0;i<n-1;i++) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		e[i].a = a;
		e[i].b = b;
		e[i].d = d;
		e[i].ia = adj[a].size();
		e[i].ib = adj[b].size();
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1);
	for(int i=0;i<n-1;i++) {
		ino[2*i].pos = i;
		ino[2*i].side = 0;
		ino[2*i].val = 1ll * e[i].d * nchild(e[i].a, e[i].ia);
		ino[2*i+1].pos = i;
		ino[2*i+1].side = 1;
		ino[2*i+1].val = 1ll * e[i].d * nchild(e[i].b, e[i].ib);
	}
	sort(ino, ino+2*n-2);
	ll old = 0;
	queue<pii> pend;
	for(int i=0;i<2*n-2;i++) {
		if(ino[i].val != old) {
			while(!pend.empty()) {
				update(1, 1, n, pend.front().first, pend.front().second);
				pend.pop();
			}
			old = ino[i].val;
		}
		int v, ii;
		if(ino[i].side == 0) v=e[ino[i].pos].b, ii=e[ino[i].pos].ib;
		else v=e[ino[i].pos].a, ii=e[ino[i].pos].ia;
		if(child[v][ii].first == -1) {
			if(range[v].first != 1) {
				crit[ino[i].pos] += query(1, 1, n, 1, range[v].first - 1);
				pend.push(pii(1, range[v].first-1));
			}
			if(range[v].second != n) {
				crit[ino[i].pos] += query(1, 1, n, range[v].second + 1, n);
				pend.push(pii(range[v].second+1, n));
			}
		}
		else {
			crit[ino[i].pos] += query(1, 1, n, child[v][ii].first, child[v][ii].second);
			pend.push(pii(child[v][ii].first, child[v][ii].second));
		}
	}
	cout << *max_element(crit, crit+n-1) << endl;
	return 0;
}
