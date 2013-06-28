#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#define INF 1000000000
using namespace std;
typedef pair<int, int> pii;

int n, D, x[100], y[100], a[100], d[100], vis[100];
int mod(int a) {return a>0?a:-a;}

void dijkstra() {
	priority_queue<pii> q;
	int v, u, delta;
	for(v=0;v<n;v++) d[v]=INF;
	d[0]=0;
	q.push(pii(0, 0));
	while(!q.empty()) {
		v = q.top().second;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		for(u=0;u<n;u++) if(u!=v) {
			delta = D*(mod(x[u]-x[v])+mod(y[u]-y[v]))-a[v];
			if(d[u]>d[v]+delta) {
				d[u]=d[v]+delta;
				q.push(pii(-d[u], u));
			}
		}
	}
}


int main() {
	cin>>n>>D;
	for(int i=1;i<n-1;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
	dijkstra();
	cout<<d[n-1]<<endl;
	return 0;
}
