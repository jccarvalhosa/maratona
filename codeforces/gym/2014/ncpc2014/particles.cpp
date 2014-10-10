#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> edge;

const int N=501;
vector<pii> elem[N*N];
vector<edge> edges;
int x[N], y[N], g[N*N], ans[N][N], dist[N][N];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i!=j) {
		dist[i][j] = (x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]);
		elem[n*i+j].push_back(pii(i, j));
		g[n*i+j] = n*i+j;
	}
	int m;
	cin>>m;
	while(m--) {
		int a, b;
		cin>>a>>b;a--;b--;
		for(int i=0;i<n;i++) if(b != i && a != i) {
			edges.push_back(edge(min(dist[a][i], dist[b][i]), pii(a*n+i, b*n+i)));
			edges.push_back(edge(min(dist[a][i], dist[b][i]), pii(i*n+a, i*n+b)));
		}
	}
	sort(edges.begin(), edges.end());
	reverse(edges.begin(), edges.end());
	for(int ii=0;ii<edges.size();ii++) {
		int d = edges[ii].first;
		int ga = g[edges[ii].second.first];
		int gb = g[edges[ii].second.second];
		if(ga == gb) continue;
		if(elem[ga].size() < elem[gb].size()) swap(ga, gb);
		for(int j=0;j<elem[gb].size();j++) {
			pii p = elem[gb][j];
			elem[ga].push_back(p);
			int a = p.first;
			int b = p.second;
			g[a*n+b] = ga;
			if(g[b*n+a] == ga && !ans[a][b]) ans[a][b] = ans[b][a] = d; 
		}
	}
	int q;
	cin>>q;
	while(q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%.12lf\n", sqrt(ans[a-1][b-1]));
	}
	return 0;
}
