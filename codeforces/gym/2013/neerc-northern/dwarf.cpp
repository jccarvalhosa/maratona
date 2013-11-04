#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;    

const int N = 11111;
vector<pii> adj[N];
int n, m, vis[N];
ll c[N];

int main() {
	ifstream in("dwarf.in");
	ofstream out("dwarf.out");
	while(in>>n>>m && !in.eof()) {
		priority_queue<pii> q;
		for(int i=0;i<n;i++) in>>c[i];
		for(int i=0;i<n;i++) {
			vis[i]=0;
			adj[i].clear();
		}
		for(int i=0;i<n;i++) q.push(pii(-c[i], i));
		for(int i=0;i<m;i++) {
			int x, a, b;
			in>>x>>a>>b; x--; a--; b--;
			adj[a].push_back(pii(b, x));
			adj[b].push_back(pii(a, x));
		}
		while(!q.empty()) {
			int v = q.top().second;
			q.pop();
			if(vis[v]) continue;
			vis[v]=1;
			for(int i=0;i<adj[v].size();i++) {
				int u = adj[v][i].first;
				int x = adj[v][i].second;
				if(c[x] > c[v] + c[u]) {
					c[x] = c[v] + c[u];
					q.push(pii(-c[x], x));
				}
			}
		}
		out << c[0] << endl;
	}
	return 0;
}
