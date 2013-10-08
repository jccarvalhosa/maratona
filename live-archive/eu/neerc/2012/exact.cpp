#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
	ll x;
	int n;
	while(cin>>x>>n && !cin.eof()) {
		vector<pair<ll, int> > v[19];
		unsigned long long p10[20];
		p10[0]=1;
		for(int i=1;i<=19;i++) p10[i] = 10*p10[i-1];
		for(int i=0;i<n;i++) {
			int k;
			ll q;
			cin>>k>>q;
			v[k].push_back(make_pair(q*p10[k], i+1));
		}
		ll sum=0;
		vector<int> ans;
		priority_queue<pair<ll, int> > q;
		for(int i=0;i<=18;i++) {
			ll num = x % p10[i+1];
			for(int j=0;j<v[i].size();j++) q.push(v[i][j]);
			while(sum < num && !q.empty()) {
				sum += q.top().first;
				ans.push_back(q.top().second);
				q.pop();
			}
			if(sum < num) break;
		}
		if(sum < x) cout << -1 << endl;
		else {
			cout << ans.size() << endl;
			cout<<ans[0];
			for(int i=1;i<ans.size();i++) cout << " " << ans[i]; cout << endl;
		}
	}
	return 0;
}
