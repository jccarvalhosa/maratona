#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll C=1e9+7;;

const int N=2e5+7;
int a[N], b[N];
ll pot[N];
set<ll> s;

int main() {
	int n;
	cin >> n;
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	for(int i=0;i<n;i++) scanf("%d", &b[i]);
	sort(a,a+n);
	sort(b,b+n);
	pot[0]=1;
	ll sum=pot[0];
	for(int i=1;i<n;i++) {
		pot[i]=pot[i-1]*C;
		sum = sum+pot[i];
	}
	ll h=0;
	for(int i=0;i<n;i++) h = h + a[i]*pot[n-i-1];
	s.insert(h - a[0]*sum);
	for(int i=1;i<n;i++) {
		h = h - a[i-1] * pot[n-1];
		h = h*C + a[i-1]+360000;
		s.insert(h - a[i]*sum);
	}
	h=0;
	for(int i=0;i<n;i++) h = h + b[i]*pot[n-i-1];
	if(s.count(h - b[0]*sum)) {
		cout << "possible" << endl;
		return 0;
	}
	for(int i=1;i<n;i++) {
		h = h - b[i-1] * pot[n-1];
		h = h*C + b[i-1]+360000;
		if(s.count(h - b[i]*sum)) {
			cout << "possible" << endl;
			return 0;
		}
	}
	cout << "impossible" << endl;
	return 0;
}
