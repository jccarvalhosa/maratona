#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int a[MAX], pos[MAX];

int query(int x, int y) {
	int i, ret=1;
	for(i=x+1;i<=y;i++) if(pos[i]<pos[i-1]) ret++;
	return ret;
}

int main() {
	int n, q, i, t, j;
	cin>>n;
	for(i=1;i<=n;i++) {
		cin>>a[i];
		pos[a[i]] = i;
	}
	cin>>q;
	while(q--) {
		cin>>t>>i>>j;
		if(t==1) cout<<query(i, j)<<endl;
		if(t==2) {
			swap(a[i], a[j]);
			pos[a[i]] = i;
			pos[a[j]] = j;
		}
	}
	return 0;
}
