#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, v[111111];
ll sum[111111];

int valid() {
	sort(v, v+n, greater<int>());
	sum[0]=v[0];
	for(int i=1;i<n;i++) sum[i] = sum[i-1] + v[i];
	if(sum[n-1] % 2 == 1) return 0;
	int pk;
	for(ll k=1;k<=n;k++) {
		int pk = lower_bound(v, v+n, k, greater<int>()) - v;
		if(pk<k) pk=k;
		if(sum[k-1] > k*(pk-1) + sum[n-1] - sum[pk-1]) return 0;
	}
	return 1;
}

int main() {
	while(scanf("%d", &n) != EOF) {
		for(int i=0;i<n;i++) cin>>v[i];
		if(valid()) cout<<"possivel"<<endl;
		else cout<<"impossivel"<<endl;
	}
	return 0;
}
