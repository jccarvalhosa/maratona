#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const double EPS = 1e-6;
const double INF=1e9;

struct pt {
	double x, y;
	pt(double x=0, double y=0) : x(x), y(y) {}
	pt operator +(pt p) { return pt(x+p.x, y+p.y); }
	pt operator -(pt p) { return pt(x-p.x, y-p.y); }
	pt operator *(double c) { return pt(x*c, y*c); }
	pt operator /(double c) { return pt(x/c, y/c); }
	double operator %(pt p) { return x*p.y - y*p.x; }
};
pt p[77];

double abs(pt p, pt q) { return hypot(p.x-q.x, p.y-q.y); }
double area(pt a, pt b, pt c) { return fabs(b%c - a%c + a%b)/2; }
pt rotate(pt a, double teta, pt o=pt()) {
	a = a - o;
	pt cis(cos(teta), sin(teta));
	return o + pt(a.x*cis.x - a.y*cis.y, a.x*cis.y + a.y*cis.x);
}

pt line_intersect(pt p, pt q, pt r, pt s) {
	pt a=q-p, b=s-r, c(p%q, r%s);
	if(fabs(a % b) < EPS) return pt(INF, INF);
	return pt(pt(a.x, b.x) % c , pt(a.y, b.y) % c) / (a % b);
}

int main() {
	freopen("protect.in", "r", stdin);
	freopen("protect.out", "w", stdout);
	int n;
	cin>>n;
	double orig[3], l[3];
	int pos[3] = {0, 1, 2};
	cin>>orig[0]>>orig[1]>>orig[2];
	for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
	int ans=1;
	do {
		for(int i=0;i<3;i++) l[i] = orig[pos[i]];
		double P = (l[0]+l[1]+l[2])/2;
		double s = sqrt(P*(P-l[0])*(P-l[1])*(P-l[2]));
		double h = 2*s/l[0];
		s += EPS;
		double teta = asin(h/l[1]);
		pt a, b, c;
		for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
			double ang = atan2(p[j].y-p[i].y, p[j].x-p[i].x);
			double dist = abs(p[i], p[j]);
			for(int k=0;k<n;k++) {
				double fi = ang + M_PI - teta;
				pt a = line_intersect(p[i], p[j], p[k], p[k] + pt(cos(fi), sin(fi)));
				b = a + (p[j]-p[i])*l[0]/dist;
				for(int sign=-1;sign<=1;sign+=2) {
					c = rotate(a + (b-a)*l[1]/l[0], sign*teta, a);
					if(fabs(abs(b, c) - l[2]) >= EPS) c = rotate(a + (a-b)*l[1]/l[0], sign*teta, a);
					if(area(a, b, p[i]) + area(a, c, p[i]) + area(b, c, p[i]) >= s) continue;
					if(area(a, b, p[j]) + area(a, c, p[j]) + area(b, c, p[j]) >= s) continue;
					if(area(a, b, p[k]) + area(a, c, p[k]) + area(b, c, p[k]) >= s) continue;
					int aux=0;
					for(int ii=0;ii<n;ii++) 
						if(area(a, b, p[ii]) + area(a, c, p[ii]) + area(b, c, p[ii]) < s) 
							aux++;
					ans = max(ans, aux);
				}
			}
		}
	} while(next_permutation(pos, pos+3));
	cout << ans << endl;
	return 0;
}
