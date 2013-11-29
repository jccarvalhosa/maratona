#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll c = (ll)1e9 + 7;
const int M = 222222;
ll a[M], b[M];

ll exp(ll a, ll e) {
	if(!e) return 1;
	if(e%2) return a*exp(a, e-1);
	return exp(a*a, e/2);
}

int main() {
	int n, m, p;
	cin>>n>>m>>p;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	ll H=0;
	for(int i=0;i<m;i++) H += exp(c, b[i]);
	vector<ll> ans;
	for(int i=0;i<p;i++) {
		int jj=0;
		ll h=0;
		for(int j=0;i+j*p<n;j++) {
			h += exp(c, a[i+j*p]);
			if(j >= m) h -= exp(c, a[i+(j-m)*p]);
			if(h==H) ans.push_back(i+(j-m+1)*p+1);
		}
	}
	sort(ans.begin(), ans.end());
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
