#include <iostream>
using namespace std;

int main() {
	int good, bad=0, n, ans=0;
	cin>>good>>n;
	while(1) {
		ans += good;
		bad += good;
		good=0;
		if(bad < n) break;
		good += bad/n;
		bad %= n;
	}
	cout<<ans<<endl;
	return 0;
}
