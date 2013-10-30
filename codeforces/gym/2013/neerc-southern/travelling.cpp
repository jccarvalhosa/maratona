#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int y = 10;
int v[333333];

int main() {
	int n, m, r;
	while(cin>>m>>n>>r && !cin.eof()) {
		r *= 10;
		int c;
		for(int i=0;i<m;i++) {
			int a, b;
			scanf("%d.%d", &a, &b);
			if(i==0) c = 10*a+b;
			v[i] = (10*a+b);
		}
		sort(v, v+m);
		c = lower_bound(v, v+m, c) - v;
		long long d=0;
		for(int i=0;i<n;i++) {
			int a, b;
			scanf("%d.%d", &a, &b);
			int x = 10*a+b;
			int delta = sqrt(r*r - y*y)+1e-9;
			a = lower_bound(v, v+m, x-delta)-v;
			b = upper_bound(v, v+m, x+delta)-v-1;
			if(c < a) {
				d += v[a]-v[c];
				c=a;
			}
			if(c > b) {
				d += v[c]-v[b];
				c=b;
			}
		}
		cout << d/10 << "." << d%10 << endl;
	}
	return 0;
}
