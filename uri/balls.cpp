#include <algorithm>
#include <iostream>
using namespace std;

int valid(int n, int v) {
	for(int i=1;i<=v;i++) {
		int d=0;
		for(int ii=i;ii>0;ii--) for(int j=0;j<ii;j++) {
			d += ii;
			if(d==n) return 1;
		}
	}
	return 0;
}

int main() {
	int n, v;
	while(cin>>n>>v && n) {
		if(valid(n, v)) cout<<"possivel\n";
		else cout<<"impossivel\n";
	}
	return 0;
}
