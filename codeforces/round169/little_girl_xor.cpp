#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned long long ull;

int main() {
	ull a, b, ans=0;
	int i, flag=0;
	cin >> a;
	cin >> b;
	for(i=63;i>=0;i--) {
		int na = ((a & (1ull<<i)) != 0ull);
		int nb = ((b & (1ull<<i)) != 0ull);
		if((nb == 1 && na == 0) || flag == 1) {
			flag=1;
			ans += 1ull<<i;
		}
	}
	cout << ans << endl;
	return 0;
}
