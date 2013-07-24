#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define EPS 1e-12
using namespace std;
typedef long long ll;
const double PI = 2*acos(0);

struct pt {
	double x, y, arg;
};

int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

bool counterclockwise(const pt &p, const pt &q) { return p.arg<q.arg; }

pt p[2222], v[2222];
double sx[2222], sy[2222];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
	double area=0;
	for(int i=0;i<n;i++) {
		int m=0;
		for(int j=0;j<n;j++) if(j!=i){
			v[m].x = p[j].x - p[i].x;
			v[m].y = p[j].y - p[i].y;
			double a = atan2(v[m].x, v[m].y);
			while(cmpD(a) < 0) a += 2*PI;
			while(cmpD(a, 2*PI) >= 0) a -= 2*PI;
			v[m].arg = a;
			m++;
		}
		sort(v, v+m, counterclockwise);
		sx[0] = v[0].x;
		sy[0] = v[0].y;
		for(int j=1;j<m;j++) {
			sx[j] = sx[j-1] + v[j].x;
			sy[j] = sy[j-1] + v[j].y;
		}
		int l=0;
		for(int j=0;j<m;j++) {
			while(l!=m && cmpD(v[j].x*v[l].y - v[j].y*v[l].x) <= 0) l++;
			double sumy = sy[m-1] - 2*sy[l-1] + sy[j];
			double sumx = sx[m-1] - 2*sx[l-1] + sx[j];
			area += sumy*v[j].x - sumx*v[j].y;
		}
	}
	printf("%.12lf\n", area/n/(n-1)/(n-2));
	return 0;
}
