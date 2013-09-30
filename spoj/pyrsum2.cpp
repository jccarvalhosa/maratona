#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define N 1000001

ll m[N], mt1[N], mtx[N];

ll tx(ll c, ll i, ll f) { return c*(f*(f+1)/2 - i*(i-1)/2); }
ll t1(ll c, ll i, ll f) { return c*(f-i+1); }

ll sum(int r) {
	if(r <= 0) return 0;
	ll ans=0;
	for(int i=r;i;i-=i&-i) {
		int s = i - (i&-i) + 1;
		ans += tx(mtx[i], s, i) + t1(mt1[i], s, i) + m[i];
	}
	for(int i=r+(r&-r);i<N;i+=i&-i) {
		int s = i - (i&-i) + 1;
		ans += tx(mtx[i], s, r) + t1(mt1[i], s, r);
	}
	return ans;
}

ll sum(int l, int r) { return sum(r) - sum(l-1); }

void add(int r, ll v1, ll vx) {
	if(r <= 0) return;
	for(int i=r;i;i-=i&-i) {
		mt1[i] += v1;
		mtx[i] += vx;
	}
	for(int i=r+(r&-r);i<N;i+=i&-i) {
		int s = i - (i&-i) + 1;
		m[i] += t1(v1, s, r) + tx(vx, s, r);
	}
}

void add(int l, int r, ll v1, ll vx=0) { add(r, v1, vx), add(l-1, -v1, -vx); }

int main() {
	int Q;
	cin>>Q;
	while(Q--) {
		string s;
		cin>>s;
		if(s=="build") {
			int c, w;
			cin>>c>>w;
			add(c-w/2, c-1, 1-c+w/2, 1);
			add(c+1, c+w/2, 1+c+w/2, -1);
			add(c, c, 1+w/2, 0);
		}
		if(s=="count") {
			int a, b;
			cin>>a>>b;
			cout<<sum(a, b)<<endl;
		}
	}
	return 0;
}
