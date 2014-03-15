#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

const int N=2e3+10;
const int INF=1e9;
int x[N], y[N], vis[N], adj[N][N], d[N];

int main() {
	freopen("irrigation.in", "r", stdin);
	freopen("irrigation.out", "w", stdout);
	int n, c;
	cin>>n>>c;
	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
	for(int i=0;i<n;i++) d[i]=INF;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) adj[i][j] = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
	priority_queue<pii> q;
	q.push(pii(0, 0));
	d[0]=0;
	long long sum=0;
	while(!q.empty()) {
		int v = q.top().second;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		sum += d[v];
		for(int u=0;u<n;u++) if(adj[v][u] >= c && d[u] > adj[v][u]) {
			d[u] = adj[v][u];
			q.push(pii(-d[u], u));
		}
	}
	int i;
	for(i=0;i<n;i++) if(!vis[i]) break;
	if(i!=n) cout<<-1<<endl;
	else cout<<sum<<endl;
	return 0;
}
