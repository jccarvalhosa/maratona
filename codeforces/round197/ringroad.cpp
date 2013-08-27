#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int v[111111];

int main() {
	int n, m;
	cin>>n>>m;
	v[0]=1;
	for(int i=1;i<=m;i++) cin>>v[i];
	long long ans=0;
	for(int i=1;i<=m;i++) {
		if(v[i] >= v[i-1]) ans += v[i]-v[i-1];
		else ans += n - v[i-1] + v[i];
	}
	cout<<ans<<endl;
	return 0;
}
