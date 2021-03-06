#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;

pii s[100000];
int a[100000], b[100000], as[100000], bs[100000];

int main() {
	int n, i, x;
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>x;
		s[i] = pii(x, i);
	}
	sort(s, s+n);
	for(i=0;i<n/3;i++) {
		a[i]=i;
		b[i]=s[i].first-a[i];
	}
	for(;i<(2*n)/3;i++) {
		b[i]=i;
		a[i]=s[i].first-b[i];
	}
	for(;i<n;i++) {
		b[i]=n-i-1;
		a[i]=s[i].first-b[i];
	}
	printf("YES\n");
	for(i=0;i<n;i++) {
		as[s[i].second] = a[i];
		bs[s[i].second] = b[i];
	}
	for(i=0;i<n;i++) printf("%d%c", as[i], i==n-1?'\n':' ');
	for(i=0;i<n;i++) printf("%d%c", bs[i], i==n-1?'\n':' ');
	return 0;
}
