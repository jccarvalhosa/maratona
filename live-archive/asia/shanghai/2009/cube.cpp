#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair

vector<pii> edge;
map<vector<bool>, int> vis;

void bfs(vector<bool> v) {
	queue<pair<vector<bool>, int> > q;
	q.push(mp(v, 0));
	vis[v] = 0;
	while(!q.empty()) {
		int d = q.front().second;
		v = q.front().first;
		q.pop();
		if(d==3) continue;
		for(int i=0;i<edge.size();i++) {
			int a = edge[i].first - 1;
			int b = edge[i].second - 1;
			if(v[a] == v[b]) continue;
			vector<bool> u = v;
			u[a] = 1 - u[a];
			u[b] = 1 - u[b];
			if(!vis.count(u)) {
				vis[u] = d+1;
				q.push(mp(u, d+1));
			}
		}
	}
}

void init_edges() {
	edge.pb(pii(1, 2));
	edge.pb(pii(1, 3));
	edge.pb(pii(1, 5));
	edge.pb(pii(1, 9));
	edge.pb(pii(2, 4));
	edge.pb(pii(2, 6));
	edge.pb(pii(2, 10));
	edge.pb(pii(3, 4));
	edge.pb(pii(3, 7));
	edge.pb(pii(3, 11));
	edge.pb(pii(4, 8));
	edge.pb(pii(4, 12));
	edge.pb(pii(5, 6));
	edge.pb(pii(5, 7));
	edge.pb(pii(5, 13));
	edge.pb(pii(6, 8));
	edge.pb(pii(6, 14));
	edge.pb(pii(7, 8));
	edge.pb(pii(7, 15));
	edge.pb(pii(8, 16));
	edge.pb(pii(9, 10));
	edge.pb(pii(9, 11));
	edge.pb(pii(9, 13));
	edge.pb(pii(10, 12));
	edge.pb(pii(10, 14));
	edge.pb(pii(11, 12));
	edge.pb(pii(11, 15));
	edge.pb(pii(12, 16));
	edge.pb(pii(13, 14));
	edge.pb(pii(13, 15));
	edge.pb(pii(14, 16));
	edge.pb(pii(15, 16));
}

int main() {
	init_edges();
	vector<bool> v(16, true);
	for(int i=0;i<8;i++) v[i]=false;
	bfs(v);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		for(int i=0;i<16;i++) {
			int x;
			cin>>x;
			v[i] = x;
		}
		printf("Case #%d: ", t);
		if(!vis.count(v)) cout<<"more"<<endl;
		else cout<<vis[v]<<endl;
	}
	return 0;
}
