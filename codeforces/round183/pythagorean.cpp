#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int ans=0, n, i, j, k2, k;
	cin>>n;
	for(i=1;i<n;i++) for(j=i;j<n;j++) {
		k2 = i*i + j*j;
		k = sqrt(k2);
		if(k*k == k2 && k <= n) ans++;
	}
	cout << ans << endl;
	return 0;
}
