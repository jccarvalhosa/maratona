#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N=2e5+10;

pii op[N];
int cont[N], sum[N];

int main() {
	int n, k;
	cin>>n>>k;k--;
	for(int i=0;i<n;i++) cin>>op[i].first>>op[i].second;
	sort(op, op+n);
	for(int i=0;i<n;i++) cont[op[i].first]++;
	sum[0] = cont[0];
	for(int i=1;i<N;i++) sum[i] = sum[i-1] + cont[i]; 
	if(k==n) cout<<0<<endl;
	else {
		ll ans=1e18;
		for(int pts=1;pts<=n;pts++) {
			int lost = n - sum[pts];
			if(lost > k) continue; 
			priority_queue<int> q1, q2;
			for(int i=0;i<n;i++) {
				if(op[i].first >= pts-1 && op[i].first <= pts) q1.push(-op[i].second);
				else q2.push(-op[i].second);
			}
			int extra = max(0, lost + cont[pts] + cont[pts-1] - k);
			if(extra > pts) continue;
			ll val=0;
			for(int i=0;i<extra;i++) {
				val -= q1.top();
				q1.pop();
			}
			while(!q1.empty()) {
				q2.push(q1.top());
				q1.pop();
			}
			for(int i=0;i<pts-extra;i++) {
				val -= q2.top();
				q2.pop();
			}
			ans = min(ans, val);
		}
		if(ans == 1e18) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
