#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
typedef long long ll;

const int N=1001, M=10001;
const ll INF=(ll)1e17;
pair<int, string> v[N];
ll dp[2][M], c[N];

int main() {
	ifstream in("addict.in");
	ofstream out("addict.out");
	int n, k;
	while(in>>n>>k && !in.eof()) {
		for(int i=0;i<n;i++) in>>v[i].second>>v[i].first;
		sort(v, v+n);
		for(int i=1;i<M;i++) dp[0][i]=INF;
		c[0] = INF;
		if(v[0].first <= k) dp[0][v[0].first] = c[0] = 1;
		for(int i=1;i<n;i++) {
			if(v[i].first <= k) c[i]=1;
			else {
				c[i]=INF;
				for(int j=k;j>=0;j--) c[i] = min(c[i], dp[(i+1)%2][v[i].first-j]+1);
			}
			for(int j=M-1;j>=0;j--) {
				if(j<v[i].first) dp[i%2][j]=dp[(i+1)%2][j];
				else dp[i%2][j] = min(dp[(i+1)%2][j], dp[(i+1)%2][j-v[i].first] + c[i]);
			}
		}
		int t=0;
		ll sum=0;
		for(int i=0;i<n && c[i] != INF;i++) {
			sum += c[i];
			t++;
		}
		out << t << " " << sum << endl;
		vector<string> ans;
		for(int i=0;i<t;i++) ans.push_back(v[i].second);
		sort(ans.begin(), ans.end());
		for(int i=0;i<t;i++) out << ans[i] << endl;
	}
	return 0;
}
