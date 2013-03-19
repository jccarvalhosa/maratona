#include <cstdio>
#include <algorithm>
#define INF 1000000000
using namespace std;

int main() {
	int n, k, i, f, t, joy, ans=-INF;
	scanf("%d%d", &n, &k);
	for(i=0;i<n;i++) {
		scanf("%d%d", &f, &t);
		joy = f;
		if(t > k) joy -= (t-k); 
		ans = max(ans, joy);
	}
	printf("%d\n", ans);
	return 0;
}
