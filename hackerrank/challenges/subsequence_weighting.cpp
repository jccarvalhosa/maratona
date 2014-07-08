#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=2e5;
int na, a[N], v[N], aa[N];
ll t[N];

ll query(int p) { ll ret=0; for(;p;p-=p&-p) ret = max(ret, t[p]); return ret;}
void update(int p, ll val) { for(;p<=na;p+=p&-p) t[p] = max(t[p], val); }

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		for(int i=0;i<n;i++) {
			scanf("%d", &a[i]);
			aa[i] = a[i];
		}
		sort(aa, aa+n);
		na = unique(aa, aa+n)-aa;
		for(int i=0;i<=na;i++) t[i]=0;
		for(int i=0;i<n;i++) scanf("%d", &v[i]);
		ll ans=0;
		for(int i=0;i<n;i++) {
			int id = lower_bound(aa, aa+na, a[i]) - aa + 1;
			ll best = v[i] + query(id-1);
			ans = max(ans, best);
			update(id, best);
		}
		cout << ans << endl;
	}
	return 0;
}
