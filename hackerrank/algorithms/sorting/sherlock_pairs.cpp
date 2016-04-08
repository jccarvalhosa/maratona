#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6+1;

int c[N];

int main() {
	int T, n;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		for (int i = 0; i < N; i++) {
			c[i] = 0;
		}
		scanf("%d", &n);
		for (int i = 0; i < n ; i++) {
			int v;
			scanf("%d", &v);
			c[v]++;
		}
		long long ans = 0;
		for (int i = 0; i < N; i++) {
			ans += 1ll * c[i] * (c[i] - 1);
		}
		cout << ans << endl;
	}
	return 0;
}

