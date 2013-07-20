#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <complex>
using namespace std;

string G[111];

int main() {
	int n, i, j;
	cin>>n;
	for(i=0;i<n;i++) cin>>G[i];
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) if(G[i][j]=='.') break;
		if(j==n) break;
	}
	if(i==n) {
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) if(G[i][j]=='.') {
				cout<<i+1<<" "<<j+1<<endl;
				break;
			}
		}
	}
	else {
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) if(G[j][i]=='.') break;
			if(j==n) break;
		}
		if(i==n) {
			for(i=0;i<n;i++) {
				for(j=0;j<n;j++) if(G[j][i]=='.') {
					cout<<j+1<<" "<<i+1<<endl;
					break;
				}
			}
		}
		else cout<<-1<<endl;
	}
	return 0;
}
