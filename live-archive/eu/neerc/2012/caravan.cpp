#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
#define a first
#define b second

int n;
pii p[111111];

bool valid(double m) {
	double s=p[0].a;
	for(int i=0;i<n;i++) {
		if(p[i].b - s < m-1e-12) return 0;
		s = max(s+m, 1.0*p[i+1].a);
	}
	return 1;
}

double bin_search(double i, double f) {
	double m;
	while(f-i>1e-10) {
		m = (f+i)/2;
		if(valid(m)) i=m;
		else f=m;
	}
	return m;
}

int main() {
	while(cin>>n && !cin.eof()) {
		for(int i=0;i<n;i++) cin>>p[i].a>>p[i].b;
		int M=0;
		for(int i=0;i<n;i++) M=max(M, p[i].b-p[i].a);
		sort(p, p+n);
		double m = bin_search(0, M+1);
		double diff = 1e7;
		int pp, qq;
		for(int q=1;q<=n;q++) {
			double prod = m*q;
			int p = prod+0.5;
			double d = fabs((prod-p)/q);
			if(d < diff) {
				diff = d;
				pp = p / __gcd(p, q);
				qq = q / __gcd(p, q);
			}
		}
		cout << pp << "/" << qq << endl;
	}
	return 0;
}
