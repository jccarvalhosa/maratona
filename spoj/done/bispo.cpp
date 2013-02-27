#include <cstdio>
#include <algorithm>
using namespace std;	
typedef long long ll;

struct euclides {
	ll m, x, y;
	euclides(ll m=0, ll x=0, ll y=0): m(m), x(x), y(y) {}
};

int mod(int a, int m) { return (a%m + m) % m; }

struct euclides emdc(int a, int b) {
	ll x=0, y=1, u=1, v=0, m, n;
	while(a != 0) {
		int q=b/a, r=b%a;
		m = x-u*q; n = y-v*q;
		b=a; a=r; x=u; y=v; u=m; v=n;
	}
	return euclides(b, x, y);
}

struct euclides e;

int a, b, c1, c2;
ll sol[4], inv, MAX=-1;

int find(int x, int y) {
	int i, j, n=0, nx=1, ny=1, v, px[2], py[2];
	ll k1, k2;
	if(a == b) {
		if(x==y) sol[0]=x-1; 
		return (x==y);
	}
	px[0] = x-1;
	if(x != 1 && x != a) px[nx++] = 2*a-x-1;
	py[0] = y-1;
	if(y != 1 && y != b) py[ny++] = 2*b-y-1;
	for(i=0;i<nx;i++) for(j=0;j<ny;j++) {
		x = px[i]; y = py[j];
		if((y-x) % e.m != 0) continue;
		v = (y-x) / e.m;
		if(c2 == 1) k1 = -v/c1;
		else k1 = (inv * mod(v, c2)) % c2;
		sol[n] = k1*(2*a-2) + x;
		if(MAX==-1 || (sol[n] >= 0 && sol[n] <= MAX)) n++;
	}
	sort(sol, sol+n);
	return n;
}

int main() {
	int q, n, x, y, i;
	scanf("%d%d%d", &a, &b, &q);
	e = emdc(2*a-2, 2*b-2);
	c1 = (2*a-2) / e.m;
	c2 = (2*b-2) / e.m;
	if(c2 != 1) inv = mod(emdc(c1, c2).x, c2);
	if(find(1, b)) MAX = sol[0];
	else if(find(a, 1)) MAX = sol[0];
	else if(find(a, b)) MAX = sol[0];
	while(q--) {
		scanf("%d%d", &x, &y);
		n = find(x, y);
		printf("%d", n);
		for(i=0;i<n;i++) printf(" %lld", sol[i]+1);
		printf("\n");
	}
	return 0;
}
