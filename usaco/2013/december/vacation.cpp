#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>
#include <vector>
#define INF (ll)1e16
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int M=10001;
const int N=201;
vector<pii> g[N];
ll d[N][N];
int vis[N];

int main() {
	ifstream in("vacation.in");
	ofstream out("vacation.out");
	int n, m, k, q;
	in>>n>>m>>k>>q;
	for(int i=0;i<m;i++) {
		int u, v, d;
		in>>u>>v>>d;
		g[u].push_back(pii(v, d));
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			d[i][j] = INF;
			vis[j]=0;
		}
		d[i][i]=0;
		priority_queue<pii> q;
		q.push(pii(0, i));
		while(!q.empty()) {
			int v = q.top().second;
			q.pop();
			if(vis[v]) continue;
			vis[v]=1;
			for(int j=0;j<g[v].size();j++) {
				int u = g[v][j].first;
				int dist = g[v][j].second;
				if(d[i][u] > d[i][v] + dist) {
					d[i][u] = d[i][v] + dist;
					q.push(pii(-d[i][u], u));
				}
			}
		}
	}
	ll sum=0;
	int ans=0;
	for(int i=0;i<q;i++) {
		ll best=INF;
		int a, b;
		in>>a>>b;
		for(int j=1;j<=k;j++) best = min(best, d[a][j] + d[j][b]);
		if(best != INF) {
			ans++;
			sum += best;
		}
	}
	out<<ans<<endl<<sum<<endl;
	return 0;
}
