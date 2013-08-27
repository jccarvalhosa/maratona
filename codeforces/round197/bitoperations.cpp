#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int n, v[11111111];

int conv(int i, int d) { return (1<<d) + i-1; }

void change(int p, int x) {
	int d = 0;
	while(d != n) {
		int q;
		if(p%2==1) q=p+1;
		else q=p-1;
		int pc = conv(p, n-d);
		int qc = conv(q, n-d);
		v[pc]=x;
		if(d%2==0) x |= v[qc];
		else x ^= v[qc];
		p = (p+1)/2;
		d++;
	}
	v[1]=x;
}

int main() {
	int m, x, p;
	cin>>n>>m;
	memset(v, 0, sizeof(v));
	for(int i=1;i<=1<<n;i++) {
		cin>>x;
		change(i, x);
	}
	for(int i=0;i<m;i++) {
		cin>>p>>x;
		change(p, x);
		cout<<v[1]<<endl;
	}
	return 0;
}
