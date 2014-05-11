#include <iostream>
#include <algorithm>
using namespace std;

int n, c[25], pai[25], nchild[25];

int go(int v, int p) {
	if(v == n) {
		for(int i=0;i<n;i++) if(c[i] > 1 || nchild[i] == 1) return 0;
		return 1;
	}
	pai[v] = p;
	if(p != -1) {
		nchild[p]++;
		c[p] -= c[v];
	}
	for(int i=0;i<=v;i++) if(c[i] > c[v+1] && go(v+1, i)) return 1;
	if(p != -1) {
		nchild[p]--;
		c[p] += c[v];
	}
	return 0;
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++) cin>>c[i];
	sort(c, c+n);
	reverse(c, c+n);
	int ok=1;
	for(int i=0;i<n;i++) if(c[i]==2) ok=0;
	if(c[0] == n && ok && go(0, -1)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
