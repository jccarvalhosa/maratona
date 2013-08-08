#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, best;

int go(int x, int s) {
	if(x==0) return s%n?s:-1;
	for(int i=min(x, k);i;i--) if(i%n) {
		for(int j=x/i;j;j--) {
			int ret1 = go(x-i*j, s+j);
			int ret2 = (j==1 || (i-1)%n==0) ?-1:go(x-i*j+1, s+j);
			if(ret1==-1 && ret2==-1) continue;
			if(ret1 == -1) return ret2;
			if(ret2 == -1) return ret1;
			return min(ret1, ret2);
		}
	}
	return -1;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		int m;
		cin>>n>>m>>k;
		if(n==1 || (n==2 && m%2==0) || (k==1 && m%n==0)) cout<<-1<<endl;
		else cout<<go(m, 0)<<endl;
	}
	return 0;
}
