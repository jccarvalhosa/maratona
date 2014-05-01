#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

const int N=26;
int ci, cf, cyc, adj[N][N], vis[N], pi[N], dep[N], d[N];
vector<int> ord;

void dfs(int v, int p) {
	vis[v]=1;
	pi[v] = p;
	if(p == -1) dep[v]=1;
	else dep[v] = dep[p]+1;
	for(int u=0;u<N;u++) if(adj[v][u]) {
		if(vis[u] == 1) {
			ci = u;
			cf = v;
			cyc = 1;
		}
		if(vis[u] == 0) dfs(u, v);
	}
	vis[v] = 2;
}

void go(int u)
{
	int i, v;
	vis[u]=1;
	for(i=0; i<N; i++) if(adj[u][i] && !vis[i]) go(i);
	ord.push_back(u);
}

void solve() {
	for(int i=0;i<N;i++) vis[i]=0;
	for(int i=0;i<N;i++) if(!vis[i]) {
		cyc=0;
		dfs(i, -1);
		if(!cyc) continue;
		vector<int> path;
		while(cf != ci) {
			path.push_back(cf);
			cf = pi[cf];
		}
		path.push_back(ci);
		reverse(path.begin(), path.end());
		for(int j=0;j<20;j++) {
			for(int k=0;k<20;k++) {
				printf("%c",path[(k+j)%((int)path.size())]+'a');
			}
			printf("\n");
		}
		return;
	}
	ord.clear();
	vector<int> ans;
	for(int i=0; i<N; i++) vis[i]=0;
	for(int i=0; i<N; i++) if(!vis[i]) go(i);
	reverse(ord.begin(), ord.end());
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++) d[j]=-INF;
		d[i]=1;
		pi[i]=-1;
		int best=-INF, id;
		for(int j=0; j<N; j++)
		{
			int u=ord[j];
			for(int k=0; k<N; k++) if(adj[u][k] && d[k]<d[u]+1)
			{
				d[k]=d[u]+1;
				pi[k]=u;
			}
		}
		for(int k=0; k<N; k++) if(best<d[k]) best=d[k], id=k;
		if(best>ans.size())
		{
			ans.clear();
			int x = id;
			while(x != i) {
				ans.push_back(x);
				x = pi[x];
			}
			ans.push_back(i);
			reverse(ans.begin(), ans.end());
		}
	}
	int sz = ans.size();
	sz = (sz+1)/2;
	for(int j=0;j<sz;j++) {
		for(int k=0;k<sz;k++) {
			printf("%c",ans[(k+j)%((int)ans.size())]+'a');
		}
		printf("\n");
	}
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) adj[i][j]=1;
		int m;
		cin>>m;
		while(m--) {
			string s;
			cin>>s;
			adj[s[0]-'a'][s[1]-'a']=0;
		}
		solve();
	}
	return 0;
}
