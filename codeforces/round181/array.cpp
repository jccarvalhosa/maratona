#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int num[100], g[100];

int main() {
	int n, i, c=0, flag1=0, flag2=0;
	cin>>n;
	for(i=0;i<n;i++) cin>>num[i];
	for(i=0;i<n;i++) g[i] = 3;
	for(i=0;i<n;i++) if(num[i] > 0) {
		g[i] = 2;
		c = 1;
		break;
	}
	if(i == n) {
		for(i=0;i<n;i++) {
			if(num[i] < 0) {
				g[i] = 2;
				c++;
				if(c == 2) break;
			}
		}
	}
	for(i=0;i<n;i++) if(num[i] < 0 && g[i] == 3) {
		g[i] = 1;
		break;
	}
	cout << 1;
	for(i=0;i<n;i++) if(g[i] == 1) cout << " " << num[i];
	cout<<endl;
	cout << c;
	for(i=0;i<n;i++) if(g[i] == 2) cout << " " << num[i];
	cout<<endl;
	cout << n-c-1;
	for(i=0;i<n;i++) if(g[i] == 3) cout << " " << num[i];
	cout<<endl;
	return 0;
}
