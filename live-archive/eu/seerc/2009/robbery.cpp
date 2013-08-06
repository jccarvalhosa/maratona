#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, m, pos[15];
ll best, c[15], w[15];

bool mycmp(int a, int b) {
	if(c[a]*w[b] > c[b]*w[a]) return 1;
	return 0;
}

ll maxc(int i, ll tw) {
	double ret=0;
	for(int j=i;j<n;j++) {
		if(tw - (pos[j]+1) * w[pos[j]] >= 0) {
			tw -= (pos[j]+1) * w[pos[j]];
			ret += (pos[j]+1) * c[pos[j]];
		} else {
			ret += (double)(tw) * c[pos[j]] / w[pos[j]];
			break;
		}
	}
	return ret;
}

void go(int i, ll tw, ll tc) {
	if(tw>m) return;
	best = max(best, tc);
	if(i==n || best >= tc + maxc(i, m-tw)) return;
	for(int j=pos[i]+1;j>=0;j--) go(i+1, tw+j*w[pos[i]], tc+j*c[pos[i]]);
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>n>>m;
		for(int i=0;i<n;i++) cin>>w[i];
		for(int i=0;i<n;i++) cin>>c[i];
		best=0;
		for(int i=0;i<n;i++) pos[i]=i;
		sort(pos, pos+n, mycmp);
		go(0, 0, 0);
		cout<<best<<endl;
	}
	return 0;
}
