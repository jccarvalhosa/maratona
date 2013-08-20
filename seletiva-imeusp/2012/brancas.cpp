#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

pii fib[11111];

int fibo(string s, int mod) {
	int n = s.size();
	fib[0] = pii(0, 1);
	for(int i=1;i<=n;i++) {
		pii p = fib[i-1];
		ll a = p.first;
		ll b = p.second;
		int c = (((2*a*b - a*a) % mod) + mod)%mod;
		int d = (a*a + b*b) % mod;
		if(s[i-1] == '0') fib[i] = pii(c, d);
		else fib[i] = pii(d, (c+d)%mod);
	}
	return fib[n].first;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		string s;
		cin>>s;
		printf("%03d\n", fibo(s, 1000));
	}
	return 0;
}
