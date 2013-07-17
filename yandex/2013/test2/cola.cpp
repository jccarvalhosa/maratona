#include <iostream>
#include <algorithm>
#include <cmath>
#define EPS 1e-6
using namespace std;

double v[1000];

int main() {
	int n, i, f=0, t=0;
	double m=0;
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>v[i];
		m += v[i];
	}
	m /= n;
	sort(v, v+n);
	for(i=n-1;i>=f;i--) {
		if(v[i]-m<EPS) break;
		t++;
		double x = v[i]-m;
		while(f<i && x>EPS) {
			double y = min(m-v[f], x);
			v[f] += y;
			x -= y;
			if(fabs(v[f]-m)<EPS) f++;
		}
	}
	cout<<t<<endl;
	return 0;
}
