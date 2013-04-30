#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, c, i, v[100];
	cin>>n;
	for(i=0;i<n;i++) cin>>v[i];
	sort(v, v+n);
	c=1;
	for(i=1;i<n;i++) {
		if(v[i] == v[i-1]) c++;
		else c=1;
		if(2*c-1 > n) break;
	}
	cout<<(i==n?"YES":"NO")<<endl;
	return 0;
}
