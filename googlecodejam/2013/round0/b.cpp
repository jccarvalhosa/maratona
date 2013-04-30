#include <cstdio>
#include <iostream>
using namespace std;

int n, m, h[100][100][2];

int main() {
	int T, t, i, j, x, ans, p;
	cin>>T;
	for(t=1;t<=T;t++) {
		cin>>n>>m;
		p=0;
		for(i=0;i<n;i++) for(j=0;j<m;j++) cin>>h[i][j][0];
		for(x=1;x<100;x++) {
			for(i=0;i<n;i++) for(j=0;j<m;j++) h[i][j][1-p] = h[i][j][p];
			for(i=0;i<n;i++) {
				for(j=0;j<m;j++) if(h[i][j][p] != x) break;
				if(j == m) for(j=0;j<m;j++) h[i][j][1-p] = x+1;
			}
			for(j=0;j<m;j++) {
				for(i=0;i<n;i++) if(h[i][j][p] != x) break;
				if(i == n) for(i=0;i<n;i++) h[i][j][1-p] = x+1;
			}
			p = 1-p;
		}
		ans=1;
		for(i=0;i<n;i++) for(j=0;j<m;j++) if(h[i][j][p] != 100) ans=0;
		printf("Case #%d: ", t);
		cout<<(ans?"YES":"NO")<<endl;
	}
	return 0;
}
