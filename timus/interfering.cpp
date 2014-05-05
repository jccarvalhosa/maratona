#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

struct pt {
	int x, y;
	pt(int x=0, int y=0) :x(x), y(y){}
	int operator % (pt p) { return x*p.y - y*p.x; }
	pt operator - (pt p) { return pt(x-p.x, y-p.y); }
	pt operator + (pt p) { return pt(x+p.x, y+p.y); }
	pt operator * (int c) { return pt(x*c, y*c); }
	pt operator / (int c) { return pt(x/c, y/c); }
	int cmp(pt p) const {
		if(x < p.x) return -1;
		if(x > p.x) return 1;
		if(y < p.y) return -1;
		if(y > p.y) return 1;
		return 0;
	}
	bool operator < (const pt &p) const { return cmp(p) < 0; }
	bool operator <= (const pt &p) const { return cmp(p) <= 0; }
	bool operator > (const pt &p) const { return cmp(p) > 0; }
	bool operator >= (const pt &p) const { return cmp(p) >= 0; }
	bool operator == (const pt &p) const { return cmp(p) == 0; }
	int prod(pt p, pt q) { return (*this-p) % (q-p); }
	bool between(pt p, pt q) { return prod(p, q) == 0 && min(p, q) <= *this && *this <= max(p, q); }
	bool left(pt p, pt q) { return prod(p, q) < 0; }
}; 

struct ptlong {
	ll x, y;
	ptlong(ll x=0, ll y=0) :x(x), y(y){}
	ll operator % (ptlong p) { return x*p.y - y*p.x; }
	ptlong operator - (ptlong p) { return ptlong(x-p.x, y-p.y); }
	ptlong operator + (ptlong p) { return ptlong(x+p.x, y+p.y); }
	ptlong operator * (ll c) { return ptlong(x*c, y*c); }
	ptlong operator / (ll c) { return ptlong(x/c, y/c); }
	int cmp(ptlong p) const {
		if(x < p.x) return -1;
		if(x > p.x) return 1;
		if(y < p.y) return -1;
		if(y > p.y) return 1;
		return 0;
	}
	bool operator < (const ptlong &p) const { return cmp(p) < 0; }
	bool operator <= (const ptlong &p) const { return cmp(p) <= 0; }
	bool operator > (const ptlong &p) const { return cmp(p) > 0; }
	bool operator >= (const ptlong &p) const { return cmp(p) >= 0; }
	bool operator == (const ptlong &p) const { return cmp(p) == 0; }
	ll prod(ptlong p, ptlong q) { return (*this-p) % (q-p); }
	bool between(ptlong p, ptlong q) { return prod(p, q) == 0 && min(p, q) <= *this && *this <= max(p, q); }
	bool left(ptlong p, ptlong q) { return prod(p, q) < 0; }
}; 

int mod(int a) { return a > 0 ? a : -a; }
int area(pt a, pt b, pt c) { return mod(b%c + a%b - a%c); }

inline bool in(pt p, pt a, pt b, pt c) {
	int s1 = area(p, a, b);
	int s2 = area(p, a, c);
	int s3 = area(p, b, c);
	int s = area(a, b, c);
	if(s1 == 0 || s2 == 0 || s3 == 0) return 0;
	return s1 + s2 == s - s3;
}

pt p[1111];
ptlong plong[1111];

int direction(pt pi, pt pj, pt pk)
{
	return ((pk.x-pi.x)*(pj.y-pi.y)-(pj.x-pi.x)*(pk.y-pi.y));
}

int on_segment(pt pi, pt pj, pt pk)
{
	if((pk.x>=min(pi.x, pj.x) && pk.x<=max(pi.x, pj.x)) && (pk.y>=min(pi.y, pj.y) && pk.y<=max(pi.y, pj.y)))
		return 1;
	return 0;
}

int segments_intersect(pt p1, pt p2, pt p3, pt p4)
{
	int d1, d2, d3, d4;
	d1=direction(p3, p4, p1);
	d2=direction(p3, p4, p2);
	d3=direction(p1, p2, p3);
	d4=direction(p1, p2, p4);
	if(((d1>0 && d2<0) || (d1<0 && d2>0)) && ((d3>0 && d4<0) || (d3<0 && d4>0))) return 1;
	else if(d1==0 && on_segment(p3, p4, p1)) return 1;
	else if(d2==0 && on_segment(p3, p4, p2)) return 1;
	else if(d3==0 && on_segment(p1, p2, p3)) return 1;
	else if(d4==0 && on_segment(p1, p2, p4)) return 1;
	return 0;
}
	
int n;

bool cart(ptlong a, ptlong b, ptlong c, ptlong d) { return d.left(a, c) != d.left(b, c) && c.left(a, b) != d.left(a, b); }

bool in_poly(ptlong a) {
	for(int i=1;i<=n;i++) if(a.between(plong[i], plong[i+1 > n ? 1 : i+1])) return -1;
	int c=0;
	ptlong ref(100002, 100002);
	for(int i=1;i<=n;i++) c += cart(plong[i], plong[i+1 > n ? 1 : i+1], a, ref);;
	return c&1;
}

bool ok(int i, int j, int k) {
	for(int ii=1;ii<=n;ii++) {
		int jj = ii+1 > n ? 1 : ii+1;
		if(ii!=i && ii!=j && jj!=i && jj!=j && segments_intersect(p[ii], p[jj], p[i], p[j])) return 0;
		if(ii!=i && ii!=k && jj!=i && jj!=k && segments_intersect(p[ii], p[jj], p[i], p[k])) return 0;
		if(ii!=k && ii!=j && jj!=k && jj!=j && segments_intersect(p[ii], p[jj], p[j], p[k])) return 0;
	}
	if(!in_poly((plong[i]+plong[j])/2)) return 0;
	if(!in_poly((plong[i]+plong[k])/2)) return 0;
	if(!in_poly((plong[j]+plong[k])/2)) return 0;
	if(!in_poly((plong[i]+plong[j]+plong[k])/3)) return 0;
	return 1;
}

void get(pt &p) {
	scanf("%d%d", &p.x, &p.y);
}

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) get(p[i]);
	for(int i=1;i<=n;i++) {
		plong[i].x = p[i].x*6;
		plong[i].y = p[i].y*6;
	}
	pt a, b;
	get(a);
	get(b);
	int valid=0;
	for(int i=n;i>=1;i--) for(int j=i-1;j>=1;j--) for(int k=j-1;k>=1;k--) {
		if(in(a, p[i], p[j], p[k]) && in(b, p[i], p[j], p[k])) {
			if(ok(i, j, k)) {
				valid=1;
				printf("%d %d %d\n", i, j, k);
				goto end;
			}
		}
	}
	end:
	if(!valid) cout<<"Impossible\n";
	return 0;
}
