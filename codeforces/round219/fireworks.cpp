#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll mod(ll a) { return a>0?a:-a; }

const int N=333333;
ll dp[N], best[N], t[N];

int main() {
	int n, m, dd;
	cin>>n>>m>>dd;
	for(int i=1;i<=m;i++) {
		ll a, b;
		cin>>a>>b>>t[i];
		ll d = (t[i]-t[i-1])*dd;
		if(d>n) d=n;
		deque<pii> window;
		for(int j=1;j<=n;j++) {
			while(!window.empty() && window.back().first <= dp[j]) window.pop_back();
			window.push_back(pii(dp[j], j));
			while(window.front().second < j-2*d) window.pop_front();
			best[j] = window.front().first;
		}
		for(int j=n+1;j<=n+d;j++) {
			while(window.front().second < j-2*d) window.pop_front();
			best[j] = window.front().first;
		}
		for(int i=1;i<=n;i++) dp[i] = best[i+d] + b - mod(a-i);
	}
	cout << *max_element(dp+1, dp+n+1) << endl;
	return 0;
}
