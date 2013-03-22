#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int mod(int a) { return a > 0 ? a : -a; }

int a[300000];

int main() {
	int n, i;
	long long ans=0;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	sort(a, a+n);
	for(i=0;i<n;i++) ans += mod(a[i]-(i+1));
	cout << ans << endl;
	return 0;
}
