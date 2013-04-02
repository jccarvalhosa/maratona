#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int mod(int a) { return a>0?a:-a;}

int v[100*100];

int main() {
	int N, n, m, d, i;
	long long ans=0;
	cin>>n>>m>>d;
	N = n*m;
	for(i=0;i<N;i++) cin>>v[i];
	for(i=1;i<N;i++) if((v[i] % d) != (v[i-1] % d)) break;
	if(i != N) cout<<-1<<endl;
	else {
		sort(v, v+N);
		m = v[N/2];
		for(i=0;i<N;i++) ans += mod(v[i]-m) / d;
		cout<<ans<<endl;
	}
	return 0;
}
