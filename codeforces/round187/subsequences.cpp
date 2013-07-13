#include <iostream>
using namespace std;
#define MAX 1000001
#define MOD 1000000007
typedef long long ll;

int a[100000], t[MAX], v[MAX];

ll query(int i) {
	ll ans=0;
	for(;i;i-= i&-i) ans = (ans + t[i])%MOD; 
	return ans;
}

void update(int i, int x) {
	int d = (x - v[i] + MOD) % MOD;
	v[i] = x;
	for(;i<MAX;i+=i&-i) t[i] = (t[i] + d)%MOD;
}

int main() {
	int n, i;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++) update(a[i], (query(a[i])*a[i] + a[i])%MOD);
	cout<<query(MAX-1)<<endl;
	return 0;
}
