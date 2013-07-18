#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#define INF 10000000000000000ll
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

ll dp[300001];
int v[300001], vis[300001];

map<int, int> m, M;

int main() {
	int n, i, j, k, a, b;
	ll ans=-INF;
	cin>>n;
	for(i=1;i<=n;i++) {
		cin>>v[i];
		dp[i] = dp[i-1];
		if(v[i]>0) dp[i] += v[i];
		if(m.count(v[i])) m[v[i]] = min(m[v[i]], i);
		else m[v[i]] = i;
		if(M.count(v[i])) M[v[i]] = max(M[v[i]], i);
		else M[v[i]] = i;
	}
	for(i=1;i<=n;i++) {
		int x, y;
		ll sum;
		x = m[v[i]];
		y = M[v[i]];
		if(x==y) continue;
		sum = dp[y] - dp[x-1];
		if(v[i]<0) sum += 2*v[i];
		if(ans<sum) {
			a=x;
			b=y;
			ans = sum;
		}
	}
	k=0;
	for(i=1;i<=n;i++) {
		if(i<a||i>b|| (i != a && i != b && v[i]<0)) {
			vis[i]=1;
			k++;
		}
	}
	cout<<ans<<" "<<k<<endl;
	for(i=1;i<=n;i++) if(vis[i]) cout<<i<<" ";
	cout<<endl;
	return 0;
}
