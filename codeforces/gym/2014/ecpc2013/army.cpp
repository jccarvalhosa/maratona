#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll search_line(ll n) {
	int i=0, f=1500000;
	while(i < f-1) {
		int m = (i+f)/2;
		ll sum = 1ll*m*(m+1)*(2*m+1)/6;
		if(sum >= n) f = m;
		else i=m;
	}
	return i;
}

ll cont(ll m, ll n) {
	if(m <= n) {
		return (1+m)*m/2;
	}
	m -= n;
	return (1+n)*n/2 + (n-1 + n-m)*m/2;
}

ll search(ll sum, ll n) {
	int i=1, f=2*n;
	while(i < f-1) {
		int m = (i+f)/2;
		ll x = cont(m-1, n);
		if(x >= sum) f=m;
		else i=m;
	}
	return i;
}

int main()
{
	int t=1, T;
	freopen("army.in", "r", stdin);
	scanf("%d", &T);
	while(T--)
	{
		ll n;
		cin>>n;
		printf("Case %d: ", t++);
		ll l = search_line(n);
		ll sum = n - l*(l+1)*(2*l+1)/6;
		cout<< l*l + search(sum, l+1) << endl;
	}
	return 0;
}
