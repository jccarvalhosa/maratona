#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define M 1000000007
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

ll exp(ll a, int e) {
	if(e==0) return 1;
	if(e%2 == 1) return (a*(exp(a, e-1)))%M;
	return exp((a*a)%M, e/2);
}

ll inv(ll a) { return exp(a, M-2); }

int main() {
	string s;
	int n, i, j, k, q, ans=0;
	cin>>s>>k;
	n = s.size();
	for(i=0;i<n;i++) {
		if(s[i] != '0' && s[i] != '5') continue;
		q = exp(2, n);
		ll aux = ((exp(q, k)-1) * inv(q-1))%M;
		aux *= exp(2, i);
		ans = (ans + aux%M)%M;
	}
	cout<<ans<<endl;
	return 0;
}
