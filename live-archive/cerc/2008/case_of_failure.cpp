#include <vector>
#include <complex>
#include <algorithm>
#include <limits>
#include <iostream>
#include <cstdio>
#include <sstream>
#define INF numeric_limits<ll>::max()
using namespace std;
typedef long long ll;
typedef complex<ll> pt;
#define x real()
#define y imag()

bool compareX(const pt &u, const pt &v) { return u.x < v.x; }
bool compareY(const pt &u, const pt &v) { return u.y < v.y; }

struct KdTree {
	pt vertex;
	KdTree *left;
	KdTree *right;
	KdTree(const pt &p) : vertex(p), left(0), right(0) {}
	~KdTree() {
		if (left) delete left;
		if (right) delete right;
	}

	typedef vector<pt>::iterator MyIter;
	static KdTree * build(MyIter first, int n, bool odd = false) {
		bool even = not odd;
		if(n == 0) return 0;
		if(n == 1) return new KdTree(*first);
		nth_element(first, first + n/2, first + n, (odd ? compareY : compareX));
		KdTree *node = new KdTree(*(first + n/2));
		node->left = build(first, n/2, even);
		node->right = build(first + n/2 + 1, n - n/2 - 1, even);
		return node;
	}

	void find(const pt &target, pt &best, ll &radius, bool odd = false) {
		if(target != vertex && norm(target - vertex) < radius) {
			best = vertex;
			radius = norm(target - vertex);
		}
		ll dist = odd ? imag(target - vertex) : real(target - vertex);
		ll d2 = dist*dist;
		bool even = not odd;
		if(dist < 0) {
			if(left) left->find(target, best, radius, even);
			if(right && d2 <= radius) right->find(target, best, radius, even);
		} else {
			if(right) right->find(target, best, radius, even);
			if(left && d2 <= radius) left->find(target, best, radius, even);
		}
	}
	
	// Find nearest neighbor
	ll nearest(const pt &target) {
		pt best;
		ll radius = INF;
		find(target, best, radius);
		return radius;
	}
};

int main() {
	int t, n, i;
	for(cin >> t; t; --t) {
		cin >> n;
		vector<pt> p(n);
		for(i=0;i<n;i++) cin >> p[i].x >> p[i].y;
		vector<pt> tmp = p;
		KdTree *tree = KdTree::build(tmp.begin(), n, false);
		stringstream ss;
		for(i=0;i<n;i++) ss << tree->nearest(p[i]) << '\n';
		cout << ss.str();
		if(tree) delete tree;
	}
	return 0;
}
