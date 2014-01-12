#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

const int N=7777;
int n;

struct T {
	ll l, r, x;
	T() {}
	T(ll l, ll r, ll x) : l(l), r(r), x(x) {}
};

vector<T> adds[N];

int cont(ll x) {
	int ret=0;
	for(int i=0;(1ll<<i)<=x;i++) ret++;
	return ret;
}

int inter(ll l, ll r, ll L, ll R) {
	if(r < L) return 0;
	if(l > R) return 0;
	return 1;
}

int main() {
	int m;
	cin>>n>>m;
	while(m--) {
		int type;
		cin>>type;
		if(type==1) {
			ll t, l, r, x;
			cin>>t>>l>>r>>x;
			adds[t].push_back(T(l, r, x));
		}
		if(type==2) {
			ll t, v;
			cin>>t>>v;
			ll l=v, r=v;
			set<ll> s;
			while(t<=n) {
				for(int i=0;i<adds[t].size();i++) {
					T a = adds[t][i];
					if(inter(a.l, a.r, l, r)) s.insert(a.x);
				}
				l = l+cont(l-1);
				r = r+cont(r);
				t++;
			}
			cout<<s.size()<<endl;
		}
	}
	return 0;
}
