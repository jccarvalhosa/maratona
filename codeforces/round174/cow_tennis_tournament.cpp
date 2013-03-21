#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;	
typedef long long ll;

struct inter {
	int zero, one, w;
	inter(int zero=1, int one=0, int w=0): zero(zero), one(one), w(w) {}
};

struct inter M[500000];

void sync(int n) {
	M[n].one = M[2*n].one + M[2*n+1].one;
	M[n].zero = M[2*n].zero + M[2*n+1].zero;
}

void propagate(int n, int b, int e) {
	M[2*n].w += M[n].w;
	M[2*n+1].w += M[n].w;
}

void fix(int n, int b, int e) {
	M[n].w %= 2;
	if(M[n].w) swap(M[n].one, M[n].zero);
	if(b != e) propagate(n, b, e);
	M[n].w = 0;
}

inter query(int n, int b, int e, int i, int j) {
	fix(n, b, e);
	if(j<b || i>e) return inter(-1);
	if(i<=b && j>=e) return M[n];
	inter p1 = query(2*n, b, (b+e)/2, i, j);
	inter p2 = query(2*n+1, (b+e)/2+1, e, i, j);
	if(p1.zero == -1) return p2;
	if(p2.zero == -1) return p1;
	return inter(p1.zero+p2.zero, p1.one+p2.one);
}

void update(int n, int b, int e, int i, int j) {
	if(i<=b && j>=e) {
		M[n].w++;
		fix(n, b, e);
	}
	else if(j<b || i>e) fix(n, b, e);
	else {
		propagate(n, b, e);
		update(2*n, b, (b+e)/2, i, j);
		update(2*n+1, (b+e)/2+1, e, i, j);
		M[n].w=0;
		sync(n);
	}
}

void init(int n, int b, int e) {
	if(b==e) M[n] = inter();
	else {
		init(2*n, b, (b+e)/2);
		init(2*n+1, (b+e)/2+1, e);
		M[n].w=0;
		sync(n);
	}
}

int n, s[100001];
vector<int> vr[100001], vl[100001];

int main() {
	int i, j, k, deg, a, b;
	inter left, right;
	cin >> n >> k;
	for(i=1;i<=n;i++) cin >> s[i];
	sort(s+1, s+n+1);
	for(i=0;i<k;i++) {
		cin >> a >> b;
		a = lower_bound(s+1, s+n+1, a) - s;
		b = upper_bound(s+1, s+n+1, b) - s - 1;
		vr[a].push_back(b);
		vl[b].push_back(a);
	}
	ll unbalanced = 0;
	init(1, 0, n+1);
	for(i=1;i<=n;i++) {
		for(j=0;j<vr[i].size();j++) update(1, 0, n+1, i, vr[i][j]);
		for(j=0;j<vl[i-1].size();j++) update(1, 0, n+1, vl[i-1][j], i-1);
		left = query(1, 0, n+1, 0, i-1);
		right = query(1, 0, n+1, i+1, n+1);
		deg = left.zero + right.one - 1;
		unbalanced += 1ll*deg*(deg-1)/2;
	}
	cout << 1ll*n*(n-1)*(n-2)/6 - unbalanced << endl;
	return 0;
}
