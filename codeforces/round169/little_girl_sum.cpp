#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int a[200000], delta[200000];

int main() {
	int i, j, n, q;
	scanf("%d%d", &n, &q);
	for(i=0;i<n;i++) scanf("%d", a+i);
	sort(a, a+n);
	memset(delta, 0, sizeof(delta));
	while(q--) {
		scanf("%d%d", &i, &j);
		delta[j-1]++;
		if(i != 1) delta[i-2]--;
	}
	for(i=n-2;i>=0;i--) delta[i] += delta[i+1];
	sort(delta, delta+n);
	ll ans=0;
	for(i=0;i<n;i++) ans += 1ll * a[i] * delta[i];
	cout << ans << endl;
	return 0;
}
