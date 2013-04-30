#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;
int pos[100];

bool pal(ll n) {
	if(n < 10) return 1;
	int c=0, i;
	while(n) {
		pos[c++] = n % 10;
		n /= 10;
	}
	for(i=0;2*i<=c;i++) if(pos[i] != pos[c-1-i]) return 0;
	return 1;
}

int main() {
	int T, t, j;
	ll ans, i, a, b;
	cin>>T;
	for(i=1;i<10000000;i++) if(pal(i) && pal(i*i)) v.push_back(i*i);
	for(t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		cin>>a>>b;
		ans= upper_bound(v.begin(), v.end(), b) - upper_bound(v.begin(), v.end(), a-1);
		cout<<ans<<endl;
	}
	return 0;
}
