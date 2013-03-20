#include <cstdio>
#include <algorithm>
using namespace std;
int d[100];

int main() {
	int n, i, a, b, ans1, ans2;
	scanf("%d", &n);
	for(i=0;i<n;i++) scanf("%d", d+i);
	scanf("%d%d", &a, &b);
	a--; b--;
	ans1 = 0;
	for(i=a;i!=b;i=(i+1)%n) ans1 += d[i];
	ans2 = 0;
	for(i=b;i!=a;i=(i+1)%n) ans2 += d[i];
	printf("%d\n", min(ans1, ans2));
	return 0;
}
