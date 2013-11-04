#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int T, n, m;
	cin>>T;
	while(T--) {
		cin>>n>>m;
		vector<int> v(n, 0);
		vector<vector<int> > adj(n);
		for(int i=0;i<n;i++) {
			int k;
			cin>>k;
			for(int j=0;j<k;j++) {
				int x; cin>>x;
				adj[i].push_back(x-1);
			}
			cin>>v[i];
		}
		vector<int> c(m);
		for(int i=0;i<m;i++) cin>>c[i];
		long long ans=0;
		for(int i=0;i<n;i++) {
			int t=(1<<30);
			for(int j=0;j<adj[i].size();j++) t = min(t, c[adj[i][j]]);
			ans += 1ll*t*v[i];
		}
		cout << ans << endl;
	}
	return 0;
}
