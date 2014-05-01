#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;
ll v[N], ac[N];

ll solve(int a, int b) {
	if(a==b) return v[a];
	int m = (a+b)/2;
	ac[m] = v[m];
	vector<int> l, r;
	for(int i=m-1;i>=a;i--) {
		ac[i] = __gcd(ac[i+1], v[i]);
		if(ac[i] < ac[i+1]) l.push_back(i+1);
	}
	l.push_back(a);
	ac[m+1] = v[m+1];
	for(int i=m+2;i<=b;i++) {
		ac[i] = __gcd(ac[i-1], v[i]);
		if(ac[i] < ac[i-1]) r.push_back(i-1);
	}
	r.push_back(b);
	ll ans=0;
	for(int i=0;i<l.size();i++) for(int j=0;j<r.size();j++) {
		ans = max(ans, __gcd(ac[l[i]], ac[r[j]]) * (r[j] - l[i] + 1));
	}
	return max(ans, max(solve(a, m), solve(m+1, b)));
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		for(int i=0;i<n;i++) scanf("%lld", &v[i]);
		cout<<solve(0, n-1)<<endl;
	}
	return 0;
}
