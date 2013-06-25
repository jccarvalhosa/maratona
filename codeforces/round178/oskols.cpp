#include <cstdio>
#include <iostream>
using namespace std;

int a[110];

int main() {
	int n, m, i;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	int x, y;
	while(m--) {
		cin>>x>>y;
		a[x-1] += y-1;
		a[x+1] += a[x]-y;
		a[x]=0;
	}
	for(i=1;i<=n;i++) cout<<a[i]<<endl;
	return 0;
}
