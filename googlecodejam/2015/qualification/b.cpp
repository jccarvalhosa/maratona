#include <iostream>
#include <algorithm>
using namespace std;

int v[1111];
int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		int n, ans=1e9;
		cin>>n;
		for(int i=0;i<n;i++) cin>>v[i];
		sort(v, v+n);
		for(int m=v[n-1];m>=1;m--) {
			int w=0;
			for(int j=0;j<n;j++) {
				w += (v[j]-1) / m;
			}
			ans = min(ans, w + m);
		}
		cout << "Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}
