#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=111111;
ll v[N], vs[N], t1[N], tp[N], tt[N];

ll sum(ll *t, int x){ll ret=0;for(;x;x-=x&-x)ret+=t[x];return ret;}
ll update(ll *t, int x, ll v) {v -= sum(t, x) - sum(t, x-1);for(;x<N;x+=x&-x) t[x]+=v;}

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n;i++) vs[i] = v[i];
	sort(vs, vs+n);
	int ns = unique(vs, vs+n)-vs;
	ll ans=0;
	for(int i=0;i<n;i++) {
		int x = 1+lower_bound(vs, vs+ns, v[i])-vs;
		update(t1, x, 1);
		update(tp, x, sum(t1, x-1));
		update(tt, x, sum(tp, x-1));
	}
	cout<<sum(tt, ns)<<endl;
	return 0;
}
