#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

const ll C=12345;
const ll M=1e9+7;
const int N=1e4+1;
const int INF=1e9;
set<ll> vis[51];
ll pot[N];
int dp[N][51], dpmin[N];

ll myhash(string &s, int i, int j) {
	ll h=0;
	for(int k=i;k<=j;k++) h = (h+pot[k-i]*s[k])%M;
	return h;
}

int main() {
	int n, d;
	cin>>n>>d;
	pot[0]=1;
	for(int i=1;i<N;i++) pot[i]=pot[i-1]*C%M;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		for(int i=0;i<d;i++) for(int j=i;j<d;j++) vis[i].insert(myhash(s, i, j));
	}
	string w;
	cin>>w;
	int W = w.size();
	for(int i=W-1;i>=0;i--) {
		dpmin[i] = INF;
		for(int k=0;k<d;k++) dp[i][k]=INF;
		for(int j=i;j<=min(i+d-1, W-1);j++) {
			ll h = myhash(w, i, j);
			for(int k=0;k<d;k++) {
				int f = i-k+d-1;
				if(i-k >= 0 && f < W && f >= j && vis[k].count(h)) {
					if(f == j) {
						if(j==W-1) dp[i][k]=1;
						else dp[i][k] = min(dp[i][k], 1+dpmin[j+1]);
					}
					else {
						dp[i][k] = min(dp[i][k], 1+dp[j+1][0]);
					}
				}
				dpmin[i] = min(dpmin[i], dp[i][k]);
			}
		}
	}
	if(dp[0][0]==INF) cout<<"NO"<<endl;
	else cout<<dp[0][0]<<endl;
	return 0;
}
