#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

ll m[111111], mt[111111];
int N;

ll sum(int r) {
	if(r <= 0) return 0;
	ll ans=0;
	for(int i=r;i;i-=i&-i) ans += mt[i]*(i&-i) + m[i];
	for(int i=r+(r&-r);i<=N;i+=i&-i) ans += mt[i]*(r-i+(i&-i));
	return ans;
}

ll sum(int l, int r) { return sum(r) - sum(l-1); }

void add(int r, ll v) {
	if(r <= 0) return;
	for(int i=r;i;i-=i&-i) mt[i] += v;
	for(int i=r+(r&-r);i<=N;i+=i&-i) m[i] += v*(r-i+(i&-i));
}

void add(int l, int r, ll v) { add(r, v), add(l-1, -v); }

int main() {
	int Q;
	cin>>N>>Q;
	for(int i=1;i<=N;i++) {
		ll v;
		cin>>v;
		add(i, i, v);
	}
	while(Q--) {
		char c;
		int a, b;
		cin>>c>>a>>b;
		if(c=='Q') cout<<sum(a, b)<<endl;
		if(c=='C') {
			ll v;
			cin>>v;
			add(a, b, v);
		}
	}
	return 0;
}
