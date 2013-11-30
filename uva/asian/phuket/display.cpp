#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

vector<pii> ans;
int n, m, vis[555], d[555];
vector<int> adj[555];

void bfs(int v) {
	for(int i=0;i<n;i++) vis[i]=0;
	queue<int> q;
	d[v]=0;
	q.push(v);
	vis[v]=1;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int i=0;i<adj[v].size();i++) {
			int u = adj[v][i];
			if(!vis[u]) {
				d[u]=d[v]+1;
				vis[u]=1;
				q.push(u);
			}
		}
	}
}

void solve() {
	for(int i=0;i<n;i++) if(adj[i].size() > 3) return;
	bfs(0);
	for(int i=0;i<n;i++) if(!vis[i]) return;
	int n3=0, v3[5], n1=0, v1[5];
	for(int i=0;i<n;i++) {
		if(adj[i].size() == 3) v3[n3++] = i;
		if(adj[i].size() == 1) v1[n1++] = i;
		if(n3 > 2) return;
		if(n1 > 3) return;
	}
	if(n3==0) {
		if(n1==0 && n%6==0 && n>=6) ans.push_back(pii(0, n/6-1));
		if(n1==2) {
			if(n>=3 && (n-3)%2==0) ans.push_back(pii(1, (n-3)/2));
			if(n>=6 && (n-6)%5==0) ans.push_back(pii(2, (n-6)/5));
			if(n>=6 && (n-6)%5==0) ans.push_back(pii(5, (n-6)/5));
			if(n>=4 && (n-4)%3==0) ans.push_back(pii(7, (n-4)/3));
		}
	}
	if(n3==1) {
		bfs(v3[0]);
		if(n1==3) {
			int D[] = {d[v1[0]], d[v1[1]], d[v1[2]]};
			sort(D, D+3);
			if(D[1]>=2 && D[2]>=2 && D[1]%2==0 && D[2]%2==0 && D[0]-1 == (D[1]-2)/2 && D[1]==D[2]) ans.push_back(pii(3, D[0]-1));
			if(D[2]>=2 && D[2]%2==0 && D[0]==D[1] && D[0]-1 == (D[2]-2)/2) ans.push_back(pii(4, D[0]-1));
		}
		if(n1==1) {
			int D = d[v1[0]];
			if(D>=2 && n-D>=4 && (D-2)/2 == (n-D-4)/4) ans.push_back(pii(6, (D-2)/2));
			if(D>=2 && n-D>=4 && (D-2)/2 == (n-D-4)/4) ans.push_back(pii(9, (D-2)/2));
		}
	}
	if(n3==2) {
		bfs(v3[0]);
		if(n >= 6 && (n-6)%7==0 && d[v3[1]] - 1 == (n-6)/7) {
			adj[v3[1]].clear();
			bfs(v3[0]);
			for(int i=0;i<n;i++) if(!vis[i]) return;
			ans.push_back(pii(8, (n-6)/7));
		}
	}
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n>>m;
		for(int i=0;i<n;i++) adj[i].clear();
		for(int i=0;i<m;i++) {
			int a, b;
			cin>>a>>b;
			adj[a-1].push_back(b-1);
			adj[b-1].push_back(a-1);
		}
		ans.clear();
		solve();
		if(t!=1) cout<<endl;
		cout<<"Case "<<t<<": "<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}
