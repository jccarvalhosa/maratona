#include <iostream>
#include <algorithm>
using namespace std;

int a[2000000];
long long sum[100000];

int main() {
	int n, N, i, j, pot;
	cin>>N;
	for(i=0;i<N;i++) cin>>a[i];
	sort(a, a+N, greater<int>());
	for(n=0, pot=1;pot!=N;n++, pot*=4);
	sum[0]=a[0];
	j=1;
	for(i=1;i<=n;i++) {
		sum[i]=sum[i-1];
		while(j<1<<(2*i)) sum[i] += a[j++];
	}
	long long ans=0;
	for(i=0;i<=n;i++) ans += sum[i];
	cout<<ans<<endl;
	return 0;
}
