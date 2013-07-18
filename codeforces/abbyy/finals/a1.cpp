#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define INF 10000000000000000ll
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

ll sum[300001];
int v[300001], vis[300001];

int main() {
	int n, i, j, k, a, b;
	ll ans=-INF;
	cin>>n;
	for(i=1;i<=n;i++) {
		cin>>v[i];
		sum[i] = sum[i-1] + v[i];
	}
	for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) if(v[i]==v[j]) {
		ll x=v[i]+v[j];
		for(k=i+1;k<j;k++) if(v[k]>0) x+=v[k];
		if(ans<x) {
			ans=x;
			a=i;
			b=j;
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
