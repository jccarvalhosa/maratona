#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

typedef pair<int, int> pii;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n, a, b;
		map<int, int> convert;
		for (int i=1; i <= 100; i++)
			convert[i] = i;
		for (int j=0; j < 2; j++) {
			cin>>n;
			for (int i=0; i < n; i++) {
				cin >> a >> b;
				convert[a] = b;
			}
		}
		vector<int> adj[101];
		for(int i=1; i <= 100; i++) 
			for(int d=1; d <= 6; d++)
				if (i + d <= 100)
					adj[i].push_back(convert[i+d]);
		vector<int> d(101, 1e9), vis(101, 0);
		d[1] = 0;
		priority_queue<pii> q;
		q.push(pii(0, 1));
		while(!q.empty()) {
			a = q.top().second;
			q.pop();
			if(vis[a])
				continue;
			vis[a] = 1;

			for (int i=0; i < adj[a].size(); i++) {
				b = adj[a][i];
				if (d[b] > d[a] + 1) {
					d[b] = d[a] + 1;
					q.push(pii(-d[b], b));
				}
			}
		}
		if (d[100] == 1e9)
			d[100] = -1;
		cout << d[100] << endl;
	}

	return 0;
}
