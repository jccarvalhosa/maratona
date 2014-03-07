#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

const int N=1e5+10;
int a[N];

set<int> z[20];
ll sum[20];

void one(int p, int v) {
	z[p].erase(v);
	set<int>::iterator low = z[p].lower_bound(v); low--;
	set<int>::iterator up = z[p].upper_bound(v);
	sum[p] += 1ll*(v - *low)*(*up - v);
}

void zero(int p, int v) {
	z[p].insert(v);
	set<int>::iterator low = z[p].lower_bound(v); low--;
	set<int>::iterator up = z[p].upper_bound(v);
	sum[p] -= 1ll*(v - *low)*(*up - v);
}

int main() {
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	for(int i=0;i<20;i++) for(int j=0;j<=n+1;j++) z[i].insert(j);
	for(int i=0;i<20;i++) for(int j=0;j<=n+1;j++) if(a[j]&(1<<i)) one(i, j);
	while(m--) {
		int p, v;
		scanf("%d%d", &p, &v);
		ll ans=0;
		for(int i=0;i<20;i++) {
			if(v & (1<<i)) {
				if(!z[i].count(p)) continue;
				one(i, p);
			}
			else {
				if(z[i].count(p)) continue;
				zero(i, p);
			}
		}
		for(int i=0;i<20;i++) ans += sum[i] * (1<<i);
		cout<<ans<<"\n";
	}
	return 0;
}
