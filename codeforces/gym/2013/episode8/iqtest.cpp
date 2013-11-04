#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

ll v[22];

ll n, d1, d2, d3;

ll det(ll m[3][3]) {
	return m[0][0]*m[1][1]*m[2][2] + m[0][1]*m[1][2]*m[2][0] + m[0][2]*m[2][1]*m[1][0] - m[2][0]*m[1][1]*m[0][2] - m[2][1]*m[1][2]*m[0][0] - m[2][2]*m[0][1]*m[1][0];
}

int test3() {
	for(int i=3;i<n-2;i++) {
		ll det0, det1, det2, det3;
		{ ll m[3][3] = {{v[i-1], v[i-2], v[i-3]}, {v[i], v[i-1], v[i-2]}, {v[i+1], v[i], v[i-1]}}; det0 = det(m); }
		if(det0 != 0) {
			{ ll m[3][3] = {{v[i], v[i-2], v[i-3]}, {v[i+1], v[i-1], v[i-2]}, {v[i+2], v[i], v[i-1]}}; det1 = det(m); }
			{ ll m[3][3] = {{v[i-1], v[i], v[i-3]}, {v[i], v[i+1], v[i-2]}, {v[i+1], v[i+2], v[i-1]}}; det2 = det(m); }
			{ ll m[3][3] = {{v[i-1], v[i-2], v[i]}, {v[i], v[i-1], v[i+1]}, {v[i+1], v[i], v[i+2]}}; det3 = det(m); }
			d1 = det1/det0;
			d2 = det2/det0;
			d3 = det3/det0;
			break;
		}
	}
	for(int i=3;i<n;i++) if(v[i] != d1*v[i-1] + d2*v[i-2] + d3*v[i-3]) return 0;
	return 1;
}

int test2() {
	int i;
	for(i=2;i<n-1;i++) {
		ll det = v[i-1]*v[i-1] - v[i]*v[i-2]; 
		if(det != 0) {
			d1 = (v[i]*v[i-1] - v[i+1]*v[i-2])/det;
			d2 = (v[i-1]*v[i+1] - v[i]*v[i])/det;
			break;
		}
	}
	for(int i=2;i<n;i++) if(v[i] != d1*v[i-1] + d2*v[i-2]) return 0;
	return 1;
}

int test1() {
	int i;
	for(i=1;i<n;i++) if(v[i-1] != 0) {
		d1 = v[i]/v[i-1];
		break;
	}
	for(i=1;i<n;i++) if(v[i] != v[i-1]*d1) return 0;
	return 1;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=0;i<n;i++) cin>>v[i];
		if(test1()) cout << v[n-1] * d1 << endl;
		else if (test2()) cout << v[n-1] * d1 + v[n-2] * d2 << endl;
		else if(test3()) cout << v[n-1]*d1 + v[n-2]*d2 + v[n-3]*d3 << endl;
		else while(1);
	}
	return 0;
}
