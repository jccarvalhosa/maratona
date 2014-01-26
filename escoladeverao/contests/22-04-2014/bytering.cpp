#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N=5e5 + 10;
int d[2*N], a[2*N];
long long sum[2*N];
int n, bestc=0;

int valid(int x) {
	if(2*x > sum[n+1]) return 0;
	int a=1, b=1;
	priority_queue<pii> q;
	for(int i=1;i<=n;i++) {
		while(b <= 2*n && sum[b] <= sum[i] + sum[n+1] - x) {
			q.push(pii(d[b], b));
			b++;
		}
		while(a <= 2*n && sum[a] < x + sum[i]) a++;
		while(!q.empty()) {
			pii p = q.top();
			if(p.second < a) {
				q.pop();
			}
			else {
				if(p.first + d[i] >= x) return 1;
				else break;
			}
		}
	}
	return 0;
}

vector<pii> adj[N];

int vis[N];
long long dist[N];

void dijkstra() {
	for(int i=0;i<=n;i++) dist[i]=(long long)1e15;
	priority_queue<pll> q;
	q.push(pll(0, 0));
	dist[0]=0;
	while(!q.empty()) {
		int v = q.top().second;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		for(int i=0;i<adj[v].size();i++) {
			int u = adj[v][i].first;
			int d = adj[v][i].second;
			if(dist[u] > dist[v] + d) {
				dist[u] = dist[v] + d;
				q.push(pll(-dist[u], u));
			}
		}
	}
	for(int i=1;i<=n;i++) {
		d[i] = dist[i];
		if(bestc < d[i]) bestc = d[i];
	}
}

int main() {
	cin>>n;n--;
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		int j = (i+1);
		if(i==n) j=1;
		adj[i].push_back(pii(j, a[i]));
		adj[j].push_back(pii(i, a[i]));
	}
	for(int i=1;i<=n;i++) {
		scanf("%d", &d[i]);
		adj[0].push_back(pii(i, d[i]));
		adj[i].push_back(pii(0, d[i]));
	}
	dijkstra();
	for(int i=1;i<=n;i++) d[n+i] = d[i];
	for(int i=1;i<=n;i++) a[n+i] = a[i];
	for(int i=2;i<=2*n;i++) sum[i] = sum[i-1] + a[i-1];
	if(!valid(bestc+1)) cout << bestc << endl;
	else {
		int i=bestc+1, f=(int)1e9+1;
		while(i<f-1) {
			int mid = (f+i)/2;
			if(valid(mid)) i=mid;
			else f=mid;
		}
		cout << i << endl;
	}
	return 0;
}
