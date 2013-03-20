#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;	
typedef long long ll;

struct interval {
	int zero, one, pending;
	interval(int zero=1, int one=0, int pending=0): zero(zero), one(one), pending(pending) {}
};

struct interval M[500000];

void get_children_values(int node) {
	M[node].one = M[2*node].one + M[2*node+1].one;
	M[node].zero = M[2*node].zero + M[2*node+1].zero;
}

void shift_values(int node) {
	if(M[node].pending) swap(M[node].one, M[node].zero);
}

void propagate_pending(int node, int b, int e) {
	M[2*node].pending += M[node].pending;
	M[2*node+1].pending += M[node].pending;
}

void fix_pending(int node, int b, int e) {
	M[node].pending %= 2;
	shift_values(node);
	if(b != e) propagate_pending(node, b, e);
	M[node].pending = 0;
}

interval join(interval i1, interval i2) {
	return interval(i1.zero+i2.zero, i1.one+i2.one);
}

interval query(int node, int b, int e, int i, int j) {
	interval p1, p2;
	fix_pending(node, b, e);
	if(j<b || i>e) {
		p1.one = -1;
		return p1;
	}
	if(i<=b && j>=e) return M[node];
	p1 = query(2*node, b, (b+e)/2, i, j);
	p2 = query(2*node+1, (b+e)/2+1, e, i, j);
	if(p1.one == -1) return p2;
	if(p2.one == -1) return p1;
	return join(p1, p2);
}

void update(int node, int b, int e, int i, int j) {
	if(i<=b && j>=e) {
		M[node].pending++;
		fix_pending(node, b, e);
	}
	else if(j<b || i>e) fix_pending(node, b, e);
	else {
		propagate_pending(node, b, e);
		M[node].pending=0;
		update(2*node, b, (b+e)/2, i, j);
		update(2*node+1, (b+e)/2+1, e, i, j);
		get_children_values(node);
	}
}

void initialize(int node, int b, int e) {
	if(b==e) M[node] = interval();
	else {
		M[node].pending=0;
		initialize(2*node, b, (b+e)/2);
		initialize(2*node+1, (b+e)/2+1, e);
		get_children_values(node);
	}
}

int n, s[100002];
pii p[100002];
vector<pii> vs, vf;

int main() {
	int i, j, k, deg;
	interval left, right;
	cin >> n >> k;
	for(i=1;i<=n;i++) cin >> s[i];
	sort(s+1, s+n+1);
	vs.resize(k+1);
	vf.resize(k+1);
	for(i=1;i<=k;i++) {
		cin >> p[i].first >> p[i].second;
		p[i].first = (lower_bound(s+1, s+n+1, p[i].first) - s);
		p[i].second = (upper_bound(s+1, s+n+1, p[i].second) - s) - 1;
		vs[i] = pii(p[i].first, i);
		vf[i] = pii(p[i].second, i);
	}
	sort(vs.begin(), vs.end());
	sort(vf.begin(), vf.end());
	ll unbalanced = 0;
	int ns=1, nf=1;
	initialize(1, 0, n+1);
	for(i=1;i<=n;i++) {
		while(ns <= k && vs[ns].first <= i) {
			j = vs[ns++].second;
			update(1, 0, n+1, p[j].first, p[j].second);
		}
		while(nf <= k && vf[nf].first < i) {
			j = vf[nf++].second;
			update(1, 0, n+1, p[j].first, p[j].second);
		}
		left = query(1, 0, n+1, 0, i-1);
		right = query(1, 0, n+1, i+1, n+1);
		deg = left.zero + right.one - 1;
		unbalanced += 1ll*deg*(deg-1)/2;
	}
	cout << 1ll*n*(n-1)*(n-2)/6 - unbalanced << endl;
	return 0;
}
