#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

const int M = 500005;
ll v[M], sum[M], best[M], t[M];
int m, n, x;

void update(ll x, ll y) { for(;x;x-=x&-x) t[x] = min(t[x], y); }
ll query(ll x) { ll ans = n+1; for(;x<=m;x+=x&-x) ans = min(ans, t[x]); return ans; }

int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>n>>x;
		for(int i=1;i<=n;i++) cin>>v[i];
		for(int i=1;i<=n;i++) sum[i] = sum[i-1] + v[i];
		vector<ll> v;
		for(int i=0;i<=n;i++) v.push_back(sum[i]);
		v.push_back((ll)1e18);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		m = v.size();
		for(int i=0;i<=m;i++) t[i]=n+1;
		int ans=n+1;
		for(int i=n;i>=1;i--) {
			ll xmin = x + sum[i-1];
			int pi = lower_bound(v.begin(), v.end(), sum[i]) - v.begin();
			update(pi+1, i);
			int pf = lower_bound(v.begin(), v.end(), xmin) - v.begin(); 
			int f = query(pf+1);
			if(f <= n) ans = min(ans, f-i+1);
		}
		if(ans > n) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
