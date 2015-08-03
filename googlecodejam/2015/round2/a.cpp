#include <iostream>
#include <algorithm>
using namespace std;

int v[1111];
char g[111][111];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int conv(char c) {
	if(c == 'v') return 0;
	if(c == '^') return 1;
	if(c == '>') return 2;
	if(c == '<') return 3;
	return -1;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		int r, c;
		cin>>r>>c;
		for(int i=0;i<r;i++) for(int j=0;j<c;j++) scanf(" %c ", &g[i][j]);
		int valid=1;
		int ans=0;
		for(int i=0;i<r;i++) for(int j=0;j<c;j++) {
			if(g[i][j] != '.') {
				int ok[4]={0};
				int any = 0;
				for(int d=0;d<4;d++) for(int k=1;;k++) {
					int ii = i + dx[d] * k;
					int jj = j + dy[d] * k;
					if(ii < 0 || ii >= r || jj < 0 || jj >= c) break;
					if(g[ii][jj] != '.') {
						ok[d]=1;
						any=1;
						break;
					}
				}
				if(!ok[conv(g[i][j])]) {
					if(any) {
						ans++;
					}
					else {
						valid=0;
					}
				}
			}
		}
		if(!valid) {
			cout << "Case #"<<t<<": IMPOSSIBLE"<<endl; 
		} else {
			cout << "Case #"<<t<<": "<<ans<<endl; 
		}
	}
	return 0;
}
