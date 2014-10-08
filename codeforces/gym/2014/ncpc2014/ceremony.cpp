#include <bits/stdc++.h>
using namespace std;

int v[111111];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v, v+n);
	int ans=n;
	int pos=0;
	for(int h=1;h<=1000000;h++) {
		while(pos < n && v[pos] <= h) pos++;
		ans = min(ans, h + n-pos);
	}
	cout << ans << endl;
	return 0;
}
