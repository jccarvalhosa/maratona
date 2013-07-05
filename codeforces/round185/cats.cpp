#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;

struct line {
    ll m, y0;
    line(ll y0=0, ll m=0): y0(y0), m(m) {}
};

bool check(line a, line b, line c){
	//É bem mais rápido, mas cuidado com o overflow!
    return (a.y0 - b.y0) * (c.m - a.m) < (a.y0 - c.y0) * (b.m - a.m);
	/*
	double x = (double)(a.y0 - b.y0) / (b.m - a.m);
	double y = (double)(a.y0 - c.y0) / (c.m - a.m);
    return x<y;
	*/
}

int nh, pos;
line H[MAX];

void update(line l) {
    while(nh >= 2 && !check(H[nh-2], H[nh-1], l)) if(pos == --nh) --pos;
    H[nh++] = l;
}

inline ll eval(int id, int x) {
    return H[id].y0 + H[id].m*x;
}

ll query(int x) {
    while(pos + 1 < nh && eval(pos, x) > eval(pos+1, x)) ++pos;
    return eval(pos, x);
}

//dp[p][i] = min(0<=j<i){ dp[p-1][j] + (i-j)*t[i] - (s[i]-s[j]) }
//generico: dp[i] = a[i] + min(0<=j<i){ dp[j] + b[j] + c[i]*d[j] }

ll dp[101][MAX], D[MAX], t[MAX], s[MAX], a[MAX], b[MAX], c[MAX], d[MAX];

int main() {
	int n, m, p, i, j, x;
	cin>>n>>m>>p;
	for(i=2;i<=n;i++) {
		cin>>x;
		D[i] = D[i-1]+x;
	}
	for(i=1;i<=m;i++) {
		cin>>x>>t[i];
		t[i] -= D[x];
	}
	sort(t+1, t+m+1);
	for(i=1;i<=m;i++) {
		s[i] = s[i-1] + t[i];
		a[i] = dp[1][i] = t[i]*i - s[i];
		b[i] = s[i];
		c[i] = t[i];
		d[i] = -i;
	}
	for(i=2;i<=p;i++) {
		nh = pos = 0;
		for(j=1;j<=m;j++) {
			update(line(dp[i-1][j-1] + b[j-1], d[j-1]));
			dp[i][j] = a[j] + query(c[j]);
		}
	}
	cout<<dp[p][m]<<endl;
	return 0;
}
