#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, vis[1<<20], v[20][1<<20], adj[20][20];

void dfs(int s) {
	vis[s] = 1;
	for(int i=0;i<n;i++) if((s & (1<<i)) && v[i][s] > 0) {
		int s2 = s - (1<<i);
		if(vis[s2]) continue;
		for(int j=0;j<n;j++) if(s2 & (1<<j)) v[j][s2] = v[j][s] + adj[i][j];
		dfs(s2);
	}
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=0;i<1<<n;i++) vis[i]=0;
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>adj[i][j];
		int ini = (1<<n)-1;
		for(int i=0;i<n;i++) {
			v[i][ini]=0;
			for(int j=0;j<n;j++) v[i][ini] += adj[i][j]; 
		}
		dfs(ini);
		vector<int> ans;
		for(int i=0;i<n;i++) if(vis[1<<i]) ans.push_back(i+1);
		if(ans.size() == 0) cout<<0<<endl;
		else {
			cout << ans[0];
			for(int i=1;i<ans.size();i++) cout << " " << ans[i];
			cout << endl;
		}
	}
	return 0;
}
