#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

struct var {
	ll d, m;
	var() {}
	var(ll d, ll m) : d(d), m(m) {}
};

ll lcm(ll a, ll b) { return a/__gcd(a, b)*b; }
var lcm(var a, var b) { return var(lcm(a.d, b.d), lcm(a.m, b.m)); }
var gcd(var a, var b) { return var(__gcd(a.d, b.d), __gcd(a.m, b.m)); }

char s[100];
ll n;

var parse() {
	scanf("%s", s);
	if(!strcmp(s, "NWD")) return gcd(parse(), parse());
	if(!strcmp(s, "NWW")) return lcm(parse(), parse());
	if(isdigit(s[0])) {
		ll x;
		sscanf(s, "%lld", &x);
		return var(x, x);
	}
	return var(1, n);
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		scanf("%lld", &n);
		var x = parse();
		if(x.d == x.m) printf("TAK\n");
		else printf("NIE\n");
	}
	return 0;
}
