#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll sum[100000];
int val[100000], n;

ll func(int i, int f) { 
	if(i==0) return sum[f];
	if(f < n) return sum[f] - sum[i-1];
	return sum[n-1] - sum[i-1] + sum[f%n];
}

int upper_bound(int start, ll key) {
	int i=start, f = n, m;
	ll p;
	while(1) {
		m = (i+f)/2;
		p = func(start, m);
		if(p <= key) {
			i = m+1;
			if(i == n || func(start, i) > key) return i;
		}
		else {
			f = m;
			if(i == f) return i;
		}
	}
}

int main() {
	int i, f, start, ans=0;
	scanf("%d%d", &n, &f);
	for(i=0;i<n;i++) scanf("%d", &val[i]);
	sum[0] = val[0];
	for(i=1;i<n;i++) sum[i] = sum[i-1] + val[i];
	for(start=0;start<n;start++) ans = max(ans, upper_bound(start, f) - start);
	printf("%d\n", ans);
}
