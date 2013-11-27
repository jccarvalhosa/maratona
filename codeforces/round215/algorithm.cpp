#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int M = 100001;
int x[M], y[M], z[M];

int main() {
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++) {
		x[i+1] = x[i] + (s[i]=='x');
		y[i+1] = y[i] + (s[i]=='y');
		z[i+1] = z[i] + (s[i]=='z');
	}
	int q;
	cin>>q;
	while(q--) {
		int i, j;
		cin>>i>>j;
		if(j-i+1 < 3) cout<<"YES"<<endl;
		else {
			int nx = x[j]-x[i-1];
			int ny = y[j]-y[i-1];
			int nz = z[j]-z[i-1];
			int t = min(nx, min(ny, nz));
			int dx = nx - t;
			int dy = ny - t;
			int dz = nz - t;
			cout<<(dx < 2 && dy < 2 && dz < 2 && dx+dy+dz <= 2 ? "YES" : "NO")<<endl;
		}
	}
	return 0;
}
