#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N=2222;
int up[N], l[N], r[N];

int main() {
	int n, m, k;
	cin>>n>>m>>k;
	char c;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
		scanf(" %c ", &c);
		if(c == '.' || c == 'D') continue;
		if(c == 'U') {
			if(i&1) continue;
			up[j]++;
		}
		if(c == 'L') {
			if(j-i >= 0) l[j-i]++;
		}
		if(c == 'R') {
			if(j+i < m) r[j+i]++;
		}
	}
	cout << l[0] + r[0] + up[0];
	for(int i=1;i<m;i++) cout << " " << l[i] + r[i] + up[i]; cout << endl;
	return 0;
}
