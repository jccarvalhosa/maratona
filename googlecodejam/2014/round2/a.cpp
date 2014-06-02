#include <bits/stdc++.h>
using namespace std;

int v[111111];

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		int n, c;
		cin>>n>>c;
		for(int i=0;i<n;i++) cin>>v[i];
		sort(v, v+n);
		int i=0, j=n-1, ans=0;
		while(1) {
			if(j==i) {
				ans++;
				break;
			}
			else {
				if(v[j] + v[i] <= c) {
					ans++;
					if(j==i+1) break;
					j--;
					i++;
				}
				else {
					j--;
					ans++;
				}
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
