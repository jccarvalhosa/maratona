#include <iostream>
#include <algorithm>
using namespace std;

int t, n, k, p[1000000], v[1000000];

int valid(int d) {
	int i, r, x=0;
	for(i=0;i<t-1;i++) {
		if(p[i+1]-p[i]<=d) v[x++] = ++i;
		if(x == n) break;
	}
	if(x != n) return 0;
	for(i=n-1;i>=0;i--) {
		r = t-v[i]-1 - 2*k*(n-1-i);
		if(r<2*k-2) return 0;
	}
	return 1;
}

int best(int i, int f) {
	while(1) {
		int m=(i+f)/2;
		if(valid(m)) {
			if(!valid(m-1)) return m;
			f = m-1;
		} else {
			if(valid(m+1)) return m+1;
			i = m+1;
		}
	}
}

int main() {
	cin>>n>>k;
	t=2*n*k;
	for(int i=0;i<t;i++) cin>>p[i];
	sort(p, p+t);
	cout<<best(-1, p[t-1]-p[0])<<endl;
	return 0;
}
