#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int f[100011];

int main() {
	int n, m, i, c, t, v;
	cin>>n>>m;
	cin>>c>>t;
	f[0] = c*t;
	for(i=1;i<n;i++) {
		cin>>c>>t;
		f[i] = f[i-1] + c*t;
	}
	for(i=0;i<m;i++) {
		cin>>v;
		cout << 1+(lower_bound(f, f+n, v)-f) << endl;
	}
	return 0;
}
