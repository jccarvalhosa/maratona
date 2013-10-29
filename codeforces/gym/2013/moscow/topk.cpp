#include <iostream>
#include <algorithm>
#include <cstdio>
#define M (1ll<<31)
using namespace std;

const int K = 2000000;
int v[K];

int main() {
	int N, k;
	cin>>N>>k;
	long long a, b, c;
	int x[2];
	cin>>x[0]>>x[1]>>a>>b>>c;
	v[0] = x[0] = (a*x[0] + b*x[1] + c)%M;
	int n=1;
	for(int i=1;i<N;i++) {
		v[n++] = x[i%2] = (a*x[i%2] + b*x[1-i%2] + c)%M;
		if(n==K) {
			nth_element(v, v+k, v+n, greater<int>());
			n=k;
		}
	}
	nth_element(v, v+k, v+n, greater<int>());
	n=k;
	sort(v, v+k, greater<int>());
	printf("%d", v[0]);
	for(int i=1;i<k;i++) printf(" %d", v[i]); printf("\n");
	return 0;
}
