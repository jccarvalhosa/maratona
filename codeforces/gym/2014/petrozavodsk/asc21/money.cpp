#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	long long x;
	cin>>x;
	if(x&1) cout << 2 << " " << x+2 << endl;
	else cout << 0 << " " << 0 << endl;
	return 0;
}
