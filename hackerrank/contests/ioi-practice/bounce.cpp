#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	n++;
	int ans=0;
	for(int i=1;i<=n;i++) if(__gcd(i, n) == 1) ans++;
	cout << ans << endl;
	return 0;
}
