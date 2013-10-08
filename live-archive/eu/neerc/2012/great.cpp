#include <iostream>
#include <cstdio>
using namespace std;

int v[1111], n;
long long p[11111];

int main() {
	long long x;
	int b;
	while(scanf("%lld %d", &x, &b) != EOF) {
		n=0;
		while(1) {
			if(x<b) {
				v[n++] = x;
				break;
			}
			v[n++] = x%b;
			x /= b;
		}
		if(n==1) {
			cout << v[0]+1 << endl;
			continue;
		}
		p[0]=1;
		for(int i=1;i<=n;i++) p[i] = p[i-1]*b;
		long long ans=0;
		for(int i=1;i<n;i+=2) {
			if(i==1) ans += b;
			else ans += (b-1)*p[(i-1)/2];
		}
		if(n%2==1) {
			for(int i=n-1;i>=0;i--) {
				if(i % 2 == 0) {
					if(i==0) ans += v[i]+1;
					else if(i==n-1) ans += (v[i]-1)*p[i/2];
					else ans += v[i]*p[i/2];
				}
				else if(v[i]) {
					ans += p[(i+1)/2];
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
