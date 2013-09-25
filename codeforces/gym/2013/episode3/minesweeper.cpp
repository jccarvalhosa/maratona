#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string t[11], m[11], r[11];
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,0,1,-1,0,1,-1};

int main() {
	int n, f=0;
	cin >> n;
	for(int i=0;i<n;i++) cin >> t[i];
	for(int i=0;i<n;i++) cin >> m[i];
	for(int i=0;i<n;i++) r[i] = "";
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(m[i][j] == 'x') {
				if(t[i][j] == '*') f = 1;
				int c = 0;
				for(int k=0;k<8;k++) if(i+dx[k] < n && i+dx[k] >= 0 && j+dy[k] < n && j+dy[k] >= 0 && t[i+dx[k]][j+dy[k]] == '*') c++;
				r[i] += '0'+c;
			}
			else r[i] += '.';
		}
	}
	if(f) for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(t[i][j] == '*') r[i][j] = '*';
	for(int i=0;i<n;i++) cout << r[i] << endl;
	return 0;
}
