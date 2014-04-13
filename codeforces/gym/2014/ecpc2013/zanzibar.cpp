#include <bits/stdc++.h>
using namespace std;

set <int> s;
const long long M = 360360;
long long vis[M+10], l[M+10], r[M+10];

long long mod(long long a) { return a > 0 ? a : -a; }

void precalc() {
	for(int i=2;i<=13;i++) {
		for(int j=1;j<i;j++) {
			s.insert((M/i)*j);
		}
	}
	vis[0] = 1;
	for(int i=0;i<M;i++) {
		if(vis[i]) {
			for(set<int>::iterator it=s.begin();it!=s.end();it++) {
				if(i+(*it) <= M) vis[i+(*it)] = 1;
			}
		}
	}
	int last = 0;
	for(int i=0;i<M;i++) {
		if(vis[i] == 1) last = i;
		l[i] = last;
	}
	last = M;
	for(int i=M;i>=0;i--) {
		if(vis[i] == 1) last = i;
		r[i] = last;
	}
}

int main()
{
	int t=1, T;
	long long x, y;
	freopen("zanzibar.in", "r", stdin);
	scanf("%d", &T);
	precalc();
	while(T--)
	{
		cin >> x >> y;
		long long den = (M*y);
		x *= M;
		long long k = x/y, num = 1e15;
		for(int i=0;i<2;i++) {
			num = min(num,mod(x-l[k+i]*y));
			num = min(num,mod(r[k+i]*y-x));
		}
		long long gcd = __gcd(num,den);
		printf("Case %d: ", t++);
		cout <<  num/gcd << "/" <<  den/gcd << endl;
	}
	return 0;
}
