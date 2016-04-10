#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		printf("Case #%d:", t);
		int k, c, s;
		cin>>k>>c>>s;
		int n = (k+c-1)/c;
		if (n > s) {
			cout << " IMPOSSIBLE" << endl;
			continue;
		}
		for (int i=0;i<n;i++) {
			long long pos = 0;
			for (int j=0;j < c && (c*i+j) < k;j++) {
				pos = pos * k + (c*i+j);
			}
			cout << " " << pos+1;
		}
		cout << endl;
	}
	return 0;
}
