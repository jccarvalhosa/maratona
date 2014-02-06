#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, a, b;
	while(scanf("%d%d%d", &n, &a, &b) && n) printf("%lld\n", n/b + n/a - n/(1ll*a/__gcd(a, b)*b));
	return 0;
}
