#include <iostream>
#include <algorithm>
using namespace std;

int n, p, q, v[111];

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v, v+n);
	cin>>p>>q;
	int dist=0, ans;
	if(q - v[n-1] >= dist) {
		dist = q - v[n-1];
		ans = q;
	}
	for(int i=n-2;i>=0;i--) {
		int left = max(v[i], p);
		int right = min(v[i+1], q);
		if(left > right) continue;
		{
			int mid = (v[i] + v[i+1] + 1)/2;
			int pos = min(max(mid, left), right);
			int ndist = min(v[i+1] - pos, pos - v[i]);
			if(ndist >= dist) {
				dist = ndist;
				ans = pos;
			}
		}
		{
			int mid = (v[i] + v[i+1])/2;
			int pos = max(min(mid, right), left);
			int ndist = min(v[i+1] - pos, pos - v[i]);
			if(ndist >= dist) {
				dist = ndist;
				ans = pos;
			}
		}
	}
	if(v[0] - p >= dist) {
		dist = v[0] - p;
		ans = p;
	}
	cout << ans << endl;
	return 0;
}
