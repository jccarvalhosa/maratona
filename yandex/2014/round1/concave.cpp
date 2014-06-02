#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int v[N];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v, v+n);
	reverse(v, v+n);
	for(int i=3;i<n;i++) {
		if(v[i] != v[i-3] && v[i-3] < v[i-2] + v[i-1] + v[i]) {
			cout << v[i] + v[i-1] + v[i-2] + v[i-3] << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
