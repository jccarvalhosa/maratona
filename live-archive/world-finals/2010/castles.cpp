#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N=1e3+1;
int n, m[N], r[N], dpm[N], dpr[N];
vector<int> adj[N];

bool cmp(int a, int b) { return r[a] > r[b]; }

void go(int v, int p) {
	dpm[v] = m[v];
	dpr[v] = r[v];
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(u == p) continue;
		go(u, v);
		if(dpr[v] >= dpm[u]) {
			dpr[v] -= dpm[u];
			dpr[v] += dpr[u];
		}
		else {
			dpm[v] += dpm[u] - dpr[v];
			dpr[v] = dpr[u];
		}
	}
}

int main() {
	int T=1;
	while(cin>>n && n) {
		for(int i=0;i<n;i++) {
			adj[i].clear();
			int a, b, c;
			cin>>a>>b>>c;
			a = max(a, b+c);
			m[i] = a;
			r[i] = a-b-c;
		}
		for(int i=0;i<n-1;i++) {
			int a, b;
			cin>>a>>b;
			adj[a-1].push_back(b-1);
			adj[b-1].push_back(a-1);
		}
		for(int i=0;i<n;i++) sort(adj[i].begin(), adj[i].end(), cmp);
		int ans=1<<30;
		for(int i=0;i<n;i++) {
			go(i, -1);
			ans = min(ans, dpm[i]);
		}
		cout << "Case " << T++ << ": " << ans << endl;
	}
	return 0;
}
