#include <cstdio>
#include <iostream>
using namespace std;

int p[3];

int main() {
	int n, i, t, l, d;
	cin>>n>>l;
	for(i=0;i<n;i++) {
		cin>>t>>d;
		if(d==-1) p[t] += 1;
		else if(d<=l) p[t] += 2;
		else p[t] += 3;
	}
	cout<<p[1]<<":"<<p[2]<<endl;
	return 0;
}
