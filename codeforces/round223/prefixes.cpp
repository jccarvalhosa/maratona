#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int v[111111];
const ll N = (ll)1e5;

int main() {
	int m;
	ll n=0;
	cin>>m;
	map<pii, int> mp;
	map<ll, ll> mv;
	while(m--) {
		int t;
		scanf("%d", &t);
		if(t==1) {
			int x;
			scanf("%d", &x);
			mv[n]=x;
			if(n < N) v[n] = x;
			n++;
		}
		if(t==2) {
			int l, c;
			scanf("%d%d", &l, &c);
			ll tam = 1ll*l*c;
			mp[pii(n, n+tam-1)] = l;
			if(n < N) {
				int pos=0;
				for(int i=n;i<min(N, n+tam);i++) {
					v[i] = v[pos++];
					if(pos == l) pos = 0;
				}
			}
			n = n+tam;
		}
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++) {
		ll x;
		cin>>x;x--;
		if(i) cout<<" ";
		if(mv.count(x)) cout<<mv[x];
		else {
			map<pii, int>::iterator it = mp.lower_bound(pii(x+1, 0));
			it--;
			ll l = it->first.first;
			int m = it->second;
			cout<<v[(x-l)%m];
		}
	}
	cout<<endl;
	return 0;
}
