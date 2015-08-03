#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const int N=1e5+1;
int v[N];

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		for(int i=0;i<n;i++) scanf("%d", &v[i]);
		sort(v, v+n);
		long long sum=0;
		for(int i=0;i<n;i++) {
			if(v[i] > sum+1) break;
			sum += v[i];
		}
		printf("%lld\n", sum+1);
	}
	return 0;
}
