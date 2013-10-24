#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int s[100010], v[100010];
int main(){
	int T, n, x, y, z;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n;
		for(int i=1;i<=n;i++) s[i]=v[i]=0;
		for(int i=1;i<n;i++) {
			cin>>x>>y>>z;
			s[x] += z;
			s[y] += z;
			v[x] = max(z, v[x]);
			v[y] = max(z, v[y]);
		}
		int ans = 0;
		for(int i=1;i<=n;i++) {
			if (2*v[i] > s[i]) ans += 2*v[i] - s[i];
			else if (s[i] & 1) ans++;
		}
		printf("Case #%d: %d\n", t, ans/2);
	}
	return 0;
}
