#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

map<pli, pli> vis;

pli go(ll n, int m) {
	pli state(n, m);
	if(vis.count(state)) return vis[state];
	ll ret=0;
	while(1) {
		ll p=1;
		while(n/p>=10) p *= 10;
		int d = n/p;
		int nm = max(m, d);
		pli aux = go(n%p, nm);
		ret += aux.first;
		n -= n%p;
		if(aux.second) n -= aux.second;
		else { n -= nm; ret++; }
		pli child(n, m);
		if(vis.count(child)) return vis[state] = pli(vis[child].first + ret, vis[child].second);
	}
}

int main() {
	ll n;
	cin>>n;
	for(int i=0;i<10;i++) vis[pli(0, i)] = pli(0, 0);
	for(int i=1;i<10;i++) for(int j=0;j<10;j++) vis[pli(i, j)] = pli(1, max(0, j-i));
	cout<<go(n, 0).first<<endl;
	return 0;
}
