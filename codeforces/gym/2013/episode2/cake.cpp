#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#define EPS 1e-9
#define INF 1e9

using namespace std;

struct pt {
	double x, y;
	pt(double x=0, double y=0): x(x), y(y) {}
	pt operator +(pt p) { return pt(x+p.x, y+p.y); }
	pt operator /(double c) { return pt(x/c, y/c); }
	double operator %(pt p) { return x*p.y - y*p.x; }
};

typedef vector<pt> polygon;

double poly_area(polygon T) {
	double s=0; int n=T.size(), i;
	for(i=0; i<n; i++) s+= T[i] % T[(i+1)%n];
	return s/2;
}

pt p[8];

int main()
{
	int t=1;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p[0].x, &p[0].y, &p[2].x, &p[2].y, &p[4].x, &p[4].y, &p[6].x, &p[6].y))
	{
		p[1]=(p[0]+p[2])/2;
		p[3]=(p[2]+p[4])/2;
		p[5]=(p[4]+p[6])/2;
		p[7]=(p[6]+p[0])/2;
		polygon P;
		for(int i=0; i<8; i++) P.push_back(p[i]);
		if(fabs(poly_area(P))<EPS) return 0;
		double s=poly_area(P), ans=INF, sans;
		for(int i=0; i<8; i++) for(int j=i+2; j<8; j++)
		{
			double s1, s2;
			polygon P;
			for(int k=i; k<=j; k++) P.push_back(p[k]);
			s1=poly_area(P);
			s2=s-s1;
			if(fabs(s2-s1)<ans)
			{
				ans=fabs(s2-s1);
				sans=s1;
			}
		}
		printf("Cake %d: %.3lf %.3lf\n", t++, min(s-sans, sans), max(sans, s-sans));
	}
	return 0;
}
