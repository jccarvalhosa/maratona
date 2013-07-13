#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int N, K, a, pos, out=0, i;
	long long sum=0, d;
	cin>>N>>K;
	cin>>a;
	pos=2;
	for(i=2;i<=N;i++) {
		cin>>a;
		d = sum - 1ll*(N-out-pos)*a*(pos-1);
		if(d < K) {
			cout<<i<<endl;
			out++;
		} else {
			sum += a * (pos-1);
			pos++;
		}
	}
	return 0;
}
