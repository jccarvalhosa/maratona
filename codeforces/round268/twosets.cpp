#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

const int N=1e5+10;
int p[N], ans[N];
int n, a, b;
map<int, int> id;
vector<pii> adj[N];

int solve() {
	queue<pii> q;
	for(int i=0;i<n;i++) {
		if(id.count(a - p[i])) {
			adj[i].push_back(pii(id[a - p[i]], 1));
		}
		if(id.count(b - p[i])) {
			adj[i].push_back(pii(id[b - p[i]], 2));
		}
		if(adj[i].size() == 0) return 0;
		if(adj[i].size() == 1) q.push(pii(i, adj[i][0].second));
	}
	while(!q.empty()) {
		int i = q.front().first;
		int c = q.front().second;
		q.pop();
		if(ans[i] == c) continue;
		if(ans[i] != 0 && ans[i] != c) return 0;
		ans[i] = c;
		for(int pi=0;pi<adj[i].size();pi++) {
			int j = adj[i][pi].first;
			q.push(pii(j, c));
		}
	}
	for(int i=0;i<n;i++) if(!ans[i]) ans[i]=1;
	for(int i=0;i<n;i++) {
		if(ans[i] == 1 && (!id.count(a-p[i]) || ans[id[a - p[i]]] != 1)) return 0;
		if(ans[i] == 2 && (!id.count(b-p[i]) || ans[id[b - p[i]]] != 2)) return 0;
	}
	return 1;
}

int main() {
	cin>>n>>a>>b;
	for(int i=0;i<n;i++) {
		scanf("%d", &p[i]);
		id[p[i]] = i;
	}
	if(solve()) {
		printf("YES\n");
		for(int i=0;i<n;i++) printf("%d ", ans[i]-1);
		printf("\n");
	} else {
		printf("NO\n");
	}
	return 0;
}
