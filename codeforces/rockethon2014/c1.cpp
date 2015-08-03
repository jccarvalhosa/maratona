#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N=2e5+10;

pii op[N];

int main() {
	int n, k;
	cin>>n>>k; k--;
	for(int i=0;i<n;i++) cin>>op[i].first>>op[i].second;
	ll ans=1e18;
	for(int vis=0;vis<1<<n;vis++) {
		int pts=0, pos=0;
		ll cost=0;
		for(int i=0;i<n;i++) if(vis & (1<<i)) {
			pts++;
			cost += op[i].second;
		}
		for(int i=0;i<n;i++) {
			if(vis & (1<<i)) {
				if(pts < op[i].first) pos++;
			}
			else {
				if(pts <= op[i].first+1) pos++;
			}
		}
		if(pos <= k) ans = min(ans, cost);
	}
	if(ans == 1e18) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
