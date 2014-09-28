#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;
typedef unsigned long long ll;

const int N=200001;
char a[N], b[N];
const int L=64;
ll na[L][N/L], nb[L][N/L];
int cnt[111111];

int main() {
	scanf("%s", a);
	scanf("%s", b);
	int A = strlen(a);
	int B = strlen(b);
	for(int i=0;i<A;i++) {
		int f = min(i+L-1, A-1);
		for(int k=i;k<=f;k++) if(a[k]=='1') na[i%L][i/L] += 1ull<<(k-i);
	}
	for(int i=0;i<B;i++) {
		int f = min(i+L-1, B-1);
		for(int k=i;k<=f;k++) if(b[k]=='1') nb[i%L][i/L] += 1ull<<(k-i);
	}
	for(int i=0;i<1<<16;i++) cnt[i] = __builtin_popcount(i);
	int q;
	cin>>q;
	while(q--) {
		int pa, pb, l;
		scanf("%d%d%d", &pa, &pb, &l);
		int ans=0;
		int p = (1<<16)-1;
		int ia = pa % L;
		int ib = pb % L;
		pa /= L;
		pb /= L;
		while(l >= L) {
			ll x = na[ia][pa] ^ nb[ib][pb];
			ans += cnt[x&p] + cnt[(x>>16)&p] + cnt[(x>>32)&p] + cnt[x>>48];
			l -= L;
			pa++;
			pb++;
		}
		ll x = (na[ia][pa] ^ nb[ib][pb]) & ((1ull<<l)-1);
		ans += cnt[x&p] + cnt[(x>>16)&p] + cnt[(x>>32)&p] + cnt[x>>48];
		printf("%d\n", ans);
	}
	return 0;
}
