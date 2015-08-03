#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		int m;
		cin>>m;
		int ans=0, sum=0;
		for(int i=0;i<=m;i++) {
			char c;
			scanf(" %c ", &c);
			int n = c-'0';
			if(i > sum) {
				ans += i-sum;
				sum += i-sum;
			}
			sum += n;
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
