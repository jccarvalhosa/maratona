#include <iostream>
#include <algorithm>
using namespace std;

int a[100000], b[100000];

int main() {
	int n, m, k, i, j;
	cin>>n>>m>>k;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<m;i++) cin>>b[i];
	if(n > m) cout << "YES" << endl;
	else {
		sort(a, a+n);
		sort(b, b+m);
		j=n-1;
		for(i=m-1;i>=0 && j>=0;i--, j--) {
			if(b[i] < a[j]) {
				cout << "YES" << endl;
				return 0;
			}
		}
		cout << "NO" << endl;
	}
	return 0;
}
