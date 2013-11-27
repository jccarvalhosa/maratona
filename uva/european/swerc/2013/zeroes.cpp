#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, pii> pp; 

ll p5[333];

map<pp, ll> vis;

ll go(ll n, int par, int dep) {
	if(n<0) return 0;
	if(n==0) return par == 0;
	pp state(n, pii(par, dep));
	if(vis.count(state)) return vis[state];
	ll ret=0;
	for(int i=0;i<5;i++) {
		int npar = ((par + i*p5[dep] - i)%8 + 8) % 8;
		if(i <= n%5) ret += go(n/5, npar, dep+1);
		else ret += go(n/5-1, npar, dep+1);
	}
	return vis[state]=ret;
}

int main() {
	p5[0]=1;
	for(int i=1;i<333;i++) p5[i] = p5[i-1]*5;
	ll x;
	while(cin>>x && x!=-1) cout<<go(x, 0, 0)<<endl;
	return 0;
}
