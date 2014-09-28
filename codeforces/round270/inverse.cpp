#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pp;

const int N=2e3+1;
vector<pp> v;
vector<pii> adj[N];
int n, dist[N][N], sum[N], g[N];
const int INF = 1e9+1;

int getGroup(int a) {
	return g[a] = g[g[a]] == g[a] ? g[a] : getGroup(g[a]);
}

void dfs(int v, int p, int s) {
	sum[v]=s;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i].first;
		int d = adj[v][i].second;
		if(u != p) {
			dfs(u, v, s+d);
		}
	}
}

int solve() {
	for(int i=0;i<n;i++) if(dist[i][i] != 0) return 0;
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
		if(dist[i][j] != dist[j][i]) return 0;
		if(dist[i][j] == 0) return 0;
		v.push_back(pp(dist[i][j], pii(i, j)));
	}
	for(int i=0;i<n;i++) g[i]=i;
	sort(v.begin(), v.end());
	int cnt=0;
	for(int ii=0;ii<v.size();ii++) {
		int d = v[ii].first;
		int i = v[ii].second.first;
		int j = v[ii].second.second;
		int gi = getGroup(i);
		int gj = getGroup(j);
		if(gi == gj) continue;
		g[gj] = gi;
		adj[i].push_back(pii(j, d));
		adj[j].push_back(pii(i, d));
		cnt++;
		if(cnt >= n) return 0;
	}
	if(cnt != n-1) return 0;
	for(int i=0;i<n;i++) {
		dfs(i, i, 0);
		for(int j=0;j<n;j++) if(sum[j] != dist[i][j]) return 0;
	}
	return 1;
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
		int d;
		scanf("%d", &d);
		dist[i][j]=d;
	}
	if(solve()) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
