#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int l, b;
		cin>>l>>b;
		int m = __gcd(l, b);
		cout << m << " " << (1ll*l*b)/(1ll*m*m)<<endl;
	}
	return 0;
}
