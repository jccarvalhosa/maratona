#include <algorithm>
#include <queue>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

const int N=1111;
string tab[N][11];
int diff[N][N];
int n, m, k, w;

int pi[N], d[N], vis[N];

int getdiff(int a, int b) {
	int d=0;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(tab[a][i][j] != tab[b][i][j]) d++;
	return d;
}

int main() {
	cin>>n>>m>>k>>w;
	for(int i=0;i<k;i++) for(int j=0;j<n;j++) cin>>tab[i][j];
	for(int i=0;i<k;i++) for(int j=i+1;j<k;j++) {
		int d = getdiff(i, j);
		diff[i][j] = diff[j][i] = d;
	}
	vector<int> ord;
	priority_queue<pii> q;
	for(int i=0;i<k;i++) {
		d[i] = n*m;
		pi[i] = -1;
		q.push(pii(-d[i], i));
	}
	while(!q.empty()) {
		int v = q.top().second;
		q.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		ord.push_back(v);
		for(int u=0;u<k;u++) if(u != v && !vis[u]) {
			if(d[u] > w*diff[v][u]) {
				d[u] = w*diff[v][u];
				pi[u] = v;
				q.push(pii(-d[u], u));
			}
		}
	}
	int ans=0;
	for(int i=0;i<k;i++) ans += d[i];
	cout << ans << endl;
	for(int i=0;i<k;i++) cout << ord[i]+1 << " " << pi[ord[i]]+1 << endl; 
	return 0;
}
