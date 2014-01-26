#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int N=1e6+10;
vector<int> adj[N];
int g[N], c[N];
vector<int> v[N], ans;

int main() {
	int n, m;
	cin>>n>>m;
	for(int i=0;i<n-1;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1;i<=n;i++) g[i]=adj[i].size();
	for(int i=1;i<=n;i++) if(g[i]==1) v[0].push_back(i);
	int pos=0;
	while(m >= 2 && !v[pos].empty()) {
		for(int i=0;i<v[pos].size();i++) {
			int a = v[pos][i];
			ans.push_back(a);
			c[a]=1;
		}
		for(int i=0;i<v[pos].size();i++) {
			int a = v[pos][i];
			for(int j=0;j<adj[a].size();j++) {
				int b = adj[a][j];
				g[b]--;
				if(g[b]==1) v[pos+1].push_back(b);
			}
		}
		m -= 2;
		pos++;
	}
	if(m==1) for(int i=1;i<=n;i++) if(!c[i]) { ans.push_back(i); break; }
	cout << ans.size() << endl;
	cout << ans[0]; for(int i=1;i<ans.size();i++) printf(" %d", ans[i]); cout<<endl;
	return 0;
}
