#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N=1e6+1;
int a[N];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	sort(a, a+n);
	long long ans=0, sum=0;
	for(int i=0;i<n;i++) sum += a[i];
	ans += sum;
	for(int i=0;i<n-1;i++) {
		ans += sum;
		sum -= a[i];
	}
	cout << ans << endl;
	return 0;
}
