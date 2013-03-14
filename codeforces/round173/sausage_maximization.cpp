#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define MAX 100002
typedef long long ll;

ll v[MAX], vleft[MAX], vright[MAX], ans;

struct trie {
	map<int, trie> child;
	ll val;
	void insert(ll a, int pos) {
		if(pos != -1) {
			if(a & (1ll << pos)) child[1].insert(a, pos-1);
			else child[0].insert(a, pos-1);
		}
		else val = a;
	}

	ll query(ll a, int pos) {
		if(pos==-1) return val;
		if(!child.count(0)) return child[1].query(a, pos-1);
		if(!child.count(1)) return child[0].query(a, pos-1);
		if(a & (1ll << pos)) return child[0].query(a, pos-1);
		return child[1].query(a, pos-1);
	}
};

trie t;

int main() {
	int i, j, n;
	cin >> n;
	v[0] = v[n+1] = 0;
	for(i=1;i<=n;i++) cin >> v[i];
	vleft[0] = 0;
	for(i=1;i<=n+1;i++) vleft[i] = vleft[i-1] ^ v[i];
	vright[n+1] = 0;
	for(i=n;i>=0;i--) vright[i] = vright[i+1] ^ v[i];
	ans = 0;
	for(i=0;i<=n;i++) {
		t.insert(vleft[i], 42);
		ans = max(ans, vright[i+1] ^ t.query(vright[i+1], 42));
	}
	cout << ans << endl;
	return 0;
}
