#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const int N=200001;
int p[N], pp[N], pp10[N];

int main() {
	ifstream in("shuffle.in");
	ofstream out("shuffle.out");
	int n, m, q;
	in>>n>>m>>q;
	for(int i=1;i<=m;i++) {
		in>>p[i];
		pp[p[i]]=i;
	}
	for(int i=m+1;i<=N;i++) pp[i]=i;
	for(int i=1;i<=n;i++) {
		int ii=i;
		for(int j=1;j<=10;j++) ii = pp[ii+1];
		pp10[i] = ii;
	}
	while(q--) {
		int i=1, t;
		in>>t;
		if(t>=m) i = pp[1];
		else {
			i = pp[m-t+1];
			t=m;
		}
		int k = n-t;
		while(k >= 10) {
			k -= 10;
			i = pp10[i];
		}
		while(k--) i=pp[i+1];
		out<<i<<endl;
	}
	return 0;
}
