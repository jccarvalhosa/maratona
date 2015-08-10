#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
using namespace std;

int main() {
	double a, b, c, d, e, f;
	cin>>a>>b>>c>>d>>e>>f;
	double s = 0;
	s += (a*b + c*d + e*f)*sqrt(3)/4;
	double l1, l2, l3;
	l1 = sqrt(a*a + b*b + a*b);
	l2 = sqrt(c*c + d*d + c*d);
	l3 = sqrt(e*e + f*f + e*f);
	double p = (l1+l2+l3)/2;
	s += sqrt(p*(p-l1)*(p-l2)*(p-l3));
	int n = s*4/sqrt(3);
	cout << n << endl;
	return 0;
}
