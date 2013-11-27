#include <iostream>
using namespace std;
typedef long long ll;

const int M = 500005;

ll s0[M], s1[M], s2[M], s3[M];

int main() {
	for(ll i=1;i<M;i++) {
		s0[i] = s0[i-1];
		s1[i] = s1[i-1];
		s2[i] = s2[i-1];
		s3[i] = s3[i-1];
		if(i&1) {
			s0[i] += 1;
			s1[i] += i;
			s2[i] += i*i;
			s3[i] += i*i*i;
		}
	}
	ll n, m;
	while(cin>>n>>m && n) {
		ll t = min(n, m);
		cout <<  s3[t] - s2[t]*(n+m+2) + s1[t]*(n+1)*(m+1) << endl;
	}
	return 0;
}
