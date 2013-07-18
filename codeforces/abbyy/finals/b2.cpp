#include <iostream>
#include <algorithm>
#define MAX 333333
using namespace std;

int n, a[MAX], pos[MAX], bit[MAX], v[MAX];

int query(int x) {
	int ret=0;
	for(;x;x-=x&-x) ret += bit[x];
	return ret;
}

int update(int x, int y) {
	int delta = y-v[x];
	v[x]=y;
	for(;x<=n;x+=x&-x) bit[x] += delta;
}

int main() {
	int q, i, t, j;
	cin>>n;
	for(i=1;i<=n;i++) {
		cin>>a[i];
		pos[a[i]] = i;
	}
	for(i=1;i<=n;i++) update(a[i], i<pos[a[i]-1]);
	cin>>q;
	while(q--) {
		cin>>t>>i>>j;
		if(t==1) cout<<1+query(j)-query(i)<<endl;
		if(t==2) {
			swap(a[i], a[j]);
			pos[a[i]] = i;
			pos[a[j]] = j;
			update(a[i], pos[a[i]]<pos[a[i]-1]);
			if(a[i]!=n) update(a[i]+1, pos[a[i]+1]<pos[a[i]]);
			update(a[j], pos[a[j]]<pos[a[j]-1]);
			if(a[j]!=n) update(a[j]+1, pos[a[j]+1]<pos[a[j]]);
		}
	}
	return 0;
}
