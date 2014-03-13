#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=111111;
ll X[N], cont[N], sum[N];

struct PackingBallsDiv1 {
	int minPacks(int K, int A, int B, int C, int D) {
		X[0] = A;
		for(int i=1;i<K;i++) X[i] = (X[i-1]*B+C) % D + 1;
		for(int i=0;i<K;i++) cont[X[i]%K]++;
		sum[0] = cont[0];
		for(int i=1;i<K;i++) sum[i] = sum[i-1] + cont[i];
		ll total=0;
		ll ans = 1e15;
		for(int i=0;i<K;i++) total += X[i]/K;
		for(int i=0;i<K;i++) ans = min(ans, i+total+sum[K-1]-sum[i]);
		return ans;
	}
};
