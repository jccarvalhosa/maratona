#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAX 100000

struct line {
    ll m, y0;
    line(ll y0=0, ll m=0): y0(y0), m(m) {}
};

bool check(line a, line b, line c){
	double x = (double)(a.y0 - b.y0) / (b.m - a.m);
	double y = (double)(a.y0 - c.y0) / (c.m - a.m);
    return x<y;
}

int nh, pos;
line H[MAX];

void update(line l) {
    while(nh >= 2 && !check(H[nh-2], H[nh-1], l)) if(pos == --nh) --pos;
    H[nh++] = l;
}

ll eval(int id, int x) {
    return H[id].y0 + H[id].m*x;
}

ll query(int x){
    while(pos + 1 < nh && eval(pos,x) > eval(pos + 1,x)) ++pos;
    return eval(pos, x);
}

ll t[MAX], v[MAX], dp[MAX], a[MAX], b[MAX], c[MAX], d[MAX];

//generico: dp[i] = a[i] + min(0<=j<i){ dp[j] + b[j] + c[i]*d[j] }
//problema: dp[i] = v[i] + min(0<=j<i) { dp[j] + (-v[j]) + t[i]*v[j] }


int main() {
	int n, i;
	cin>>n;
	for(i=0;i<n;i++) cin>>t[i]; 
	for(i=0;i<n;i++) cin>>v[i];
	for(i=0;i<n;i++) {
		a[i] = v[i];
		b[i] = -v[i];
		c[i] = t[i];
		d[i] = v[i];
	}
	dp[0] = v[0];
	for(i=1;i<n;i++) {
		update(line(dp[i-1] + b[i-1], d[i-1]));
		dp[i] = a[i] + query(c[i]);
	}
	cout<<dp[n-1]<<endl;
	return 0;
}
