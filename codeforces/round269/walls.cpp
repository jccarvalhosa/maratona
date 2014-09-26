#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

const ll C=1234567, M=1e9+7;

const int N=2e5+7;
int a[N], b[N];
ll pot[N];

int main() {
	int n, w;
	cin>>n>>w;
	if(w > n) {
		cout << 0 << endl;
		return 0;
	}
	pot[0]=1;
	for(int i=1;i<w;i++) pot[i]=C*pot[i-1]%M;
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	ll H=0, delta=0;
	for(int i=0;i<w;i++) {
		scanf("%d", &b[i]);
		H += pot[w-i-1]*b[i];
		H %= M;
		delta += pot[i];
		delta %= M;
	}
	ll h=0;
	for(int i=0;i<w;i++) {
		h += pot[w-i-1]*a[i];
		h %= M;
	}
	int ans=0;
	if(((h + delta * (b[0]-a[0]))%M + M) % M == H) ans++;
	for(int i=1;;i++) {
		int j = i+w-1;
		if(j >= n) break;
		h = (h - a[i-1] * pot[w-1]) % M;
		h = (h*C + a[j]) % M;
		if(((h + delta * (b[0]-a[i]))%M + M) % M == H) ans++;
	}
	cout << ans << endl;
	return 0;
}
