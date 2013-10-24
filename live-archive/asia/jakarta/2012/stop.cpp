#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cout << "Case #" << t << ": ";
		int a, b, c, d, e, m;
		cin>>a>>b>>c>>d>>e>>m;
		int sum = a+b+c+d+e;
		if(sum <= 0) {
			if(sum >= m) cout << 0 << endl;
			else cout << -1 << endl;
		}
		else {
			int ans;
			for(ans=0;sum<m;ans++) sum *= 2;
			cout << ans << endl;
		}
	}
	return 0;
}
