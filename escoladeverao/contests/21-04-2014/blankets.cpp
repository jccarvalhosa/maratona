#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int N=2e5+10;
const int M=2e6+10;
pii v[N], o[N];

ld t1[M], tx[M], ty[M], txy[M];
ll a, b, x, y;
ld d, s1, sx, sy, sxy;
void add(ld *t, int x, ld v) {for(;x<M;x+=x&-x) t[x]+=v/d;}
ld sum(ld *t, int x) {ld ret=0;for(;x;x-=x&-x) ret+=t[x];return ret;}
ld sum(ld *t, int a, int b) { return sum(t, b)-sum(t, a-1);}

void remove(int pos) {
	ll x = v[pos].first;
	ll y = v[pos].second;
	add(t1, y, -1);
	add(tx, y, -x);
	add(ty, y, -y);
	add(txy, y, -x*y);
}

void insert(int pos) {
	ll x = v[pos].first;
	ll y = v[pos].second;
	add(t1, y, 1);
	add(tx, y, x);
	add(ty, y, y);
	add(txy, y, x*y);
}

int main() {
	int n;
	cin>>n>>a>>b;
	for(int i=0;i<n;i++) {
		cin>>x>>y;x++;y++;
		v[i] = pii(x, y);
		o[i] = pii(x, i);
	}
	sort(o, o+n);
	ld ans=0;
	d = 1ll*n*(n-1)/2;
	int j=n-1;
	for(int i=n-1;i>=0;i--) {
		while(j!=0 && o[j].first >= o[i].first+a) remove(o[j--].second);
		int pos = o[i].second;
		x = v[pos].first;
		y = v[pos].second;
		s1 = sum(t1, y, y+b);
		sx = sum(tx, y, y+b);
		sy = sum(ty, y, y+b);
		sxy = sum(txy, y, y+b);
		ans += s1*(x+a)*(y+b);
		ans -= sy*(x+a);
		ans -= sx*(y+b);
		ans += sxy;
		insert(o[i].second);
	}
	while(j>=0) remove(o[j--].second);
	j=0;
	for(int i=0;i<n;i++) {
		while(j!=n && o[j].first+a <= o[i].first) remove(o[j++].second);
		int pos = o[i].second;
		x = v[pos].first;
		y = v[pos].second;
		s1 = sum(t1, y+1, y+b);
		sx = sum(tx, y+1, y+b);
		sy = sum(ty, y+1, y+b);
		sxy = sum(txy, y+1, y+b);
		ans -= s1*(x-a)*(y+b);
		ans += sy*(x-a);
		ans += sx*(y+b);
		ans -= sxy;
		insert(o[i].second);
	}
	printf("%.5Lf\n", ans);
	return 0;
}
