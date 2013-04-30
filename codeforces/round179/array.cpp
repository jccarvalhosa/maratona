#include <cstdio>
#include <iostream>
#include <cstring>
#define M 100001
using namespace std;
typedef long long ll;

int n, m, k, op[M][3];
ll a[M], num[M], sum[M];

void updateq(int x, ll v) {
	for(; x ; x -= x&-x) num[x] += v;
}

void update(int x, ll v) {
	for(; x ; x -= x&-x) sum[x] += v;
}

ll queryq(int x) {
	ll ret=0;
	for(; x<=m;x += x&-x) ret += num[x];
	return ret;
}

ll query(int x) {
	ll ret=0;
	for(; x<=n;x += x&-x) ret += sum[x];
	return ret;
}

int main() {
	int i, x;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>op[i][0]>>op[i][1]>>op[i][2];
	memset(num, 0, sizeof(num));
	memset(sum, 0, sizeof(sum));
	for(i=1;i<=k;i++) {
		cin>>x;
		updateq(x-1, -1);
		cin>>x;
		updateq(x, 1);
	}
	for(i=1;i<=m;i++) {
		ll v = queryq(i) * op[i][2];
		update(op[i][0]-1, -v);
		update(op[i][1], v);
	}
	for(i=1;i<=n;i++) {
		ll v = query(i) + a[i];
		cout<<v<<(i==n?'\n':' ');
	}
	return 0;
}
