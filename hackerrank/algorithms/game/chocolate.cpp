#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int N = 1e5+1;
int v[N], diff[N], accum[N];

int main() {
	int n;
	cin>>n;
	int q = sqrt(n)/4;
	q = max(q, 1) * 2;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);

		if (i > 0)
			diff[i] = v[i] - v[i-1];
		else
			diff[i] = 0;

		if (i < 2)
			accum[i] = diff[i];
		else
			accum[i] = accum[i-2] ^ diff[i];
	}

	long long bad = 0;
	for (int qi=0; qi*q < n; qi++) {
		int imax = min(n, (qi+1)*q);

		for (int i=qi*q; i < imax; i++) {
			int last = i > 0 ? v[i-1] : 0;
			int x = 0;
			for (int j = i+1; j < imax; j += 2) {
				x ^= diff[j];
				if (x == 0) bad++;
				else if (x == last) bad++;
			}
		}

		map<int, int> m[2];
		for (int j=qi*q; j < imax; j++) {
			int mod = j & 1;
			m[mod][accum[j] ^ accum[qi*q + mod] ^ diff[qi*q + mod]]++;
		}

		for (int i=0; i < qi*q; i++) {
			int x1 = 0, x2 = i > 0 ? v[i-1] : 0;
			int mod = (i+1) & 1;
			int j = qi*q + mod;
			if (j >= imax)
				continue;
			int totalXor = accum[i+1] ^ accum[j] ^ diff[i+1] ^ diff[j];
			x1 ^= totalXor;
			x2 ^= totalXor;

			if (m[mod].count(x1))
				bad += m[mod][x1];

			if (x2 != x1 && m[mod].count(x2))
				bad += m[mod][x2];
		}
	}

	cout << 1ll * n * (n-1) / 2 - bad << endl;
	return 0;
}
