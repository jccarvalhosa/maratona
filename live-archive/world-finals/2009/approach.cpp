#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int n, a[11], b[11], ord[11];

int valid(double t) {
	double pos=a[ord[0]];
	for(int i=1;i<n;i++) {
		pos += t;
		if(pos > b[ord[i]]+1e-12) return 0;
		if(a[ord[i]] > pos) pos = a[ord[i]];
	}
	return 1;
}

int main() {
	int T=1;
	while(cin>>n && n) {
		for(int i=0;i<n;i++) cin>>a[i]>>b[i];
		for(int i=0;i<n;i++) ord[i]=i;
		double ans=0;
		do {
			double i=0, f=2000;
			for(int t=0;t<200;t++) {
				if(f < ans) break;
				double m=(i+f)/2;
				if(valid(m)) i=m;
				else f=m;
			}
			ans = max(ans, i);
		} while(next_permutation(ord, ord+n));
		int mm = ans;
		int ss = (ans-mm)*60 + 0.5;
		if(ss == 60) {
			ss=0;
			mm++;
		}
		printf("Case %d: %d:%.2d\n", T++, mm, ss);
	}
	return 0;
}
