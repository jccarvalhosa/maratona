#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int valid(vector<ll> v, int n) {
	while(1) {
		if(n<=2) return 1;
		if(n%2==1) return 0;
		vector<ll> u;
		int c=1, i;
		ll k=0;
		for(i=1;i<n;i++) {
			if(v[i]==v[i-1]) {
				c++;
				if(c==n/2) k=v[i];
			}
			else c=1;
		}
		if(k==0) return 0;
		c = n/2;
		for(i=0;i<n;i++) {
			if(c==0 || v[i] != k) u.push_back(v[i]);
			else c--;
		}
		n /= 2;
		v = u;
	}
}

int main() {
	int n, i;
	cin>>n;
	vector<ll> v(n);
	for(i=0;i<n;i++) cin>>v[i];
	sort(v.begin(), v.end());
	cout<<(valid(v, n)?"YES":"NO")<<endl;
	return 0;
}
