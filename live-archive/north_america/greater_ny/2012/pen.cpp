#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int p;
	cin>>p;
	while(p--) {
		int t, n;
		cin>>t>>n;

		int ans=0;

		if(n % 3 == 0) ans++;

		for(int i=1;i<n;i++) {
			if((n - i) % 2 != 0) continue;
			int j = (n-i) / 2;
			if(i > j) {
				if(i < 2*j) ans++;
			}
			else if(i != j) {
				ans++;
			}
		}
		
		for(int i=1;i<n;i++) {
			
			int diff = n - 3*i;

			if(diff <= 2) break;

			ans += 2 * ((diff - 1) / 2 - max(0, (diff - i) / 2));
		}

		printf("%d %d\n", t, ans);
	}
	return 0;
}
