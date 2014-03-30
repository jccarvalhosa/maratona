#include <bits/stdc++.h>
using namespace std;

int b, n;
const int N=555;
int c[N], w[N][5], vis[N], cc;

vector<int> g[N], ginv[N], ord;

void dfs(int u)
{
	int i, v;
	vis[u]=1;
	for(i=0; i<g[u].size(); i++)
	{
		v=g[u][i];
		if(!vis[v]) dfs(v);
	}
	ord.push_back(u);
}

void dfsinv(int u)
{
	int i, v;
	vis[u]=cc;
	for(i=0; i<ginv[u].size(); i++)
	{
		v=ginv[u][i];
		if(!vis[v]) dfsinv(v);
	}
}

int solve() {
	for(int i=0;i<n;i++) {
		if(c[i] == 1 || c[i] == 2) {
			for(int j=0;j<c[i];j++) {
				int x = w[i][j];
				int nx = x^1;
				g[nx].push_back(0);
				ginv[0].push_back(nx);
			}
		}
		else {
			for(int j=0;j<c[i];j++) for(int k=0;k<j;k++) {
				int a = w[i][j];
				int na = a^1;
				int b = w[i][k];
				int nb = b^1;
				g[na].push_back(b);
				ginv[b].push_back(na);
				g[nb].push_back(a);
				ginv[a].push_back(nb);
			}
		}
	}
	for(int i=0;i<2*b+2;i++) vis[i]=0;
	cc=1;
	dfsinv(0);
	for(int i=1;i<=b;i++) if(vis[2*i] && vis[2*i+1]) return 0;
	ord.clear();
	for(int i=0;i<2*b+2;i++) vis[i]=0;
	for(int i=0; i<2*b+2; i++) if(!vis[i]) dfs(i);
	reverse(ord.begin(), ord.end());
	for(int i=0;i<2*b+2;i++) vis[i]=0;
	for(int i=0; i<2*b+2; i++) if(!vis[ord[i]])
	{
		dfsinv(ord[i]);
		cc++;
	}
	for(int i=1;i<=b;i++) if(vis[2*i]==vis[2*i+1]) return 0;
	return 1;
}

int main() {
	int T=1;
	while(cin>>b>>n && b) {
		for(int i=0;i<n;i++) {
			cin>>c[i];
			for(int j=0;j<c[i];j++) {
				int x; char h;
				cin>>x>>h;
				if(h=='y') w[i][j]=2*x;
				else w[i][j]=2*x+1;
			}
		}
		printf("Case %d: ", T++);
		for(int i=0;i<2*b+2;i++) {
			g[i].clear();
			ginv[i].clear();
		}
		if(solve()) {
			for(int i=1;i<=b;i++) {
				for(int j=0;j<2*b+2;j++) {
					g[j].clear();
					ginv[j].clear();
				}
				g[2*i+1].push_back(0);
				ginv[0].push_back(2*i+1);
				int s1 = solve();
				for(int j=0;j<2*b+2;j++) {
					g[j].clear();
					ginv[j].clear();
				}
				g[2*i].push_back(0);
				ginv[0].push_back(2*i);
				int s2 = solve();
				if(s1 && s2) printf("?");
				else if(s1) printf("y");
				else printf("n");
			}
			printf("\n");
		}
		else {
			printf("impossible\n");
		}
	}
	return 0;
}
