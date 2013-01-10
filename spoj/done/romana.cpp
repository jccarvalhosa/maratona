#include <cstdio>
#include <queue>
#include <vector>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

int N, P, E, conv[101], vis[250];
vector<pii> adj[250];
priority_queue<pii> q;

int main() {
	int i, j, a, b, c, d, v, sum;
	scanf("%d%d%d", &N, &P, &E);
	conv[0]=1;
	for(i=1;i<=100;i++) conv[i]=0;
	for(i=0;i<P;i++) {
		scanf("%d", &c);
		for(j=c;j<=100;j++) conv[j] += conv[j-c];
	}
	for(i=0;i<E;i++) {
		scanf("%d%d%d", &a, &b, &d);
		if(!conv[d]) continue;
		adj[a-1].pb(mp(b-1, conv[d]));
		adj[b-1].pb(mp(a-1, conv[d]));
	}
	for(i=0;i<N;i++) vis[i]=0;
	q.push(mp(0, 0));
	sum=0;
	while(!q.empty()) {
		v = q.top().second;
		d = -q.top().first;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		sum += d;
		for(i=0;i<adj[v].size();i++) q.push(mp(-adj[v][i].second, adj[v][i].first));
	}
	for(i=0;i<N;i++) if(!vis[i]) break;
	if(i != N) printf("-1");
	else printf("%d", sum);
	return 0;
}
