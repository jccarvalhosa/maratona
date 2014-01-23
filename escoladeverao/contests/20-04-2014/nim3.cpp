#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
const int N=1e6+10;
const int M=63;
ll a[N], sum[M];

int solve() {
	for(int i=0;i<M;i++) {
		sum[i]=0;
		for(int j=0;j<n;j++) if(a[j] & (1ll<<i)) sum[i]++;
	}
	int loser=1;
	for(int i=0;i<M;i++) if(sum[i] % 3) loser=0;
	if(loser) return 0;
	for(int i=0;i<n;i++) {
		int j;
		ll x = a[i];
		for(j=0;j<M;j++) {
			if(sum[j] % 3 == 2) {
				if(x & (1ll<<j)) break;
				x += 1ll<<j;
			}
			if(sum[j] % 3 == 1) {
				if(x & (1ll<<j)) x -= 1ll<<j;
				else break;
			}
		}
		if(j==M && x<=a[i]) return 1;
	}
	return 2;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i=0;i<n;i++) scanf("%lld", &a[i]);
		int x = solve();
		printf("%c\n", x==1 ? 'A' : x==2 ? 'B' : 'C');
	}
	return 0;
}
