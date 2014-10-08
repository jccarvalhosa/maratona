#include <bits/stdc++.h>
using namespace std;

const int N=1e5+1;
vector<int> adj[N];
int vis[N];

int main() {
	int n, k;
	cin>>k>>n;
	for(int i=0;i<n;i++) {
		int k;
		scanf("%d", &k);
		while(k--) {
			int j;
			scanf("%d", &j); j--;
			adj[i].push_back(j);
		}
	}
	int T=500000;
	for(int t=1;t<=T;t++) {
		int used=0, rem=0;
		while(used != k && rem != n) {
			int pos = rand() % n;
			while(pos < n && vis[pos]==t) pos++;
			if(pos == n) {
				pos=0;
				while(pos < n && vis[pos]==t) pos++;
			}
			used++;
			rem++;
			vis[pos]=t;
			for(int i=0;i<adj[pos].size();i++) {
				int j = adj[pos][i];
				if(vis[j] != t) {
					vis[j]=t;
					rem++;
				}
			}
		}
		if(used == k) {
			cout << "possible" << endl;
			return 0;
		}
	}
	cout << "impossible" << endl;
	return 0;
}
