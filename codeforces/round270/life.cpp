#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
using namespace std;

const int N=2001;
int cnt[N];

int main() {
	int n, k;
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		int f;
		cin>>f;
		cnt[f]++;
	}
	int ans=0;
	for(int i=2;i<=2000;i++) {
		int div = (n+k-1)/k;
		ans += (div-1)*2 + 1;
		n -= cnt[i];
		if(!n) {
			ans += i-1;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
