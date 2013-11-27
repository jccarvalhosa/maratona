#include <iostream>
#include <algorithm>
using namespace std;

int v[222222];

int main() {
	int n, m;
	cin>>n>>m;
	int dummy;
	for(int i=0;i<m;i++) cin>>dummy>>v[i];
	sort(v, v+m, greater<int>());
	int x=0;
	while(x*(x/2) + x%2 <= n) x++;
	x = min(x-1, m);
	long long ans=0;
	for(int i=0;i<x;i++) ans += v[i];
	cout<<ans<<endl;
	return 0;
}
