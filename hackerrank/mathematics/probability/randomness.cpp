#include <algorithm>
#include <string>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

const int T=9;
const int C=1e9+7;
const int M=1e6+3;
const int N=1e5;
const int Q = N * T * T / 2;
int cont[Q], f[Q], p[Q], ii=0;
ll t[Q];
char s[N];

ll mod(ll h) { return h > 0 ? h : -h; }

int getpos(ll h) {
	int hh = mod(h) % M;
	int q = f[hh];
	while (q) {
		if (t[q] == h) return q;
		q = p[q];
	}
	++ii;
	t[ii] = h;
	p[ii] = f[hh];
	f[hh] = ii;
	return ii;
}

int main() {
	int n, q;
	ll stable=0, variable=0;
	cin>>n>>q;
	scanf("%s", s);
	for(int i=0;i<n;i++) {
		stable += max(0, n-i-T);
		ll h=0;
		for(int j=0;j<T && i+j<n;j++) {
			h = h*C + s[i+j];
			if(cont[getpos(h)]++ == 0) variable++;
		}
	}
	while(q--) {
		int x;
		char c;
		scanf("%d %c", &x, &c); x--;
		if(s[x] != c) {   
			for(int i=max(0, x-T+1);i<=x;i++) {
				ll h=0;
				for(int j=0;j<T && i+j<n;j++) {
					h = h*C + s[i+j];
					if(i+j<x) continue;
					if(--cont[getpos(h)] == 0) variable--;
				}
			}
			s[x] = c;
			for(int i=max(0, x-T+1);i<=x;i++) {
				ll h=0;
				for(int j=0;j<T && i+j<n;j++) {
					h = h*C + s[i+j];
					if(i+j<x) continue;
					if(cont[getpos(h)]++ == 0) variable++;
				}
			}
		}
		cout << stable + variable << endl;
	}
	return 0;
}
