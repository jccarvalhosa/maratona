#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[3000];

int dp[3000][55];

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n, t;
		cin>>n>>t;
		vector<int> div;
		for(int i=1;i*i<=n;i++) {
			if(n % i == 0) {
				div.push_back(i);
				if(n/i != i) div.push_back(n/i);
			}
		}
		sort(div.begin(), div.end());
		int k = div.size();
		map<int, int> id;
		for(int i=0;i<k;i++) {
			id[div[i]]=i;
			int ii = sqrt(div[i]);
			dp[i][1] = ii*ii != div[i];
		}
		for(int i=0;i<k;i++) {
			adj[i].clear();
			for(int x=0;x<i;x++) if(div[i] % div[x] == 0) {
				int y = id[div[i]/div[x]];
				adj[i].push_back(pii(x, y));
			}
		}
		for(int j=2;j<=t;j++) {
			for(int i=0;i<k;i++) {
				dp[i][j]=0;
				for(int ii=0;ii<adj[i].size();ii++) {
					int x = adj[i][ii].first;
					int y = adj[i][ii].second;
					if(dp[x][1] && dp[y][j-1]) {
						dp[i][j]=1;
						break;
					}
				}
			}
		}
		printf("%s\n", dp[k-1][t] ? "YES" : "NO");
	}
	return 0;
}
