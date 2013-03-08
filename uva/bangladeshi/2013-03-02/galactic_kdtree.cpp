#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define D 10000001
#define MAX 500002
using namespace std;
typedef long long ll;

const ll INF=numeric_limits<ll>::max();

struct pt {
	ll x, y;
};

bool compareX(const pt &a, const pt &b) { return a.x < b.x; }
bool compareY(const pt &a, const pt &b) { return a.y < b.y; }

int counter;

struct KdTree {
	// Elements
	pt vertex;
	KdTree *left;
	KdTree *right;
	int nchilds;
	ll minx, miny, maxx, maxy;
	// Constructors & Destructors
	KdTree(const pt &p) : vertex(p), left(0), right(0), nchilds(0) {
		minx = maxx = p.x;
		miny = maxy = p.y;
	}
	~KdTree() {
		if(left) delete left;
		if(right) delete right;
	}

	// Build a balanced tree, complexity O(n⋅log(n))
	static KdTree* build(vector<pt>::iterator first, int n, bool odd=false) {
		if(n == 0) return 0;
		if(n == 1) return new KdTree(*first);
		nth_element(first, first + n/2, first + n, odd ? compareY : compareX);
		KdTree *node = new KdTree(*(first + n/2));
		node->left = build(first, n/2, not odd);
		node->right = build(first + n/2 + 1, n - n/2 - 1, not odd);
		if(node->left) node->get_values(node->left);
		if(node->right) node->get_values(node->right);
		return node;
	}

	void get_values(KdTree* node) {
		minx = min(minx, node->minx);
		miny = min(miny, node->miny);
		maxx = max(maxx, node->maxx);
		maxy = max(maxy, node->maxy);
		nchilds += 1 + node->nchilds;
	}

	int range_count(ll a, ll b) {
		//counter++;
		if(minx >= a && miny >= b) return nchilds + 1;
		if(maxx < a || maxy < b) return 0;
		int ans = vertex.x >= a && vertex.y >= b;
		if(right) ans += right->range_count(a, b);
		if(left) ans += left->range_count(a, b);
		return ans; 
	}
};

int main() {
	int n, q, i, vx, vy, vz;
	ll x[2], y[2], z[2], a, b;
	scanf("%d", &n);
	n -= 2;
	for(i=0;i<2;i++) scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
	vector<pt> p(n);
	for(i=0;i<n;i++) {
		scanf("%d%d%d", &vx, &vy, &vz);
		p[i].x = (x[0]-vx)*(x[0]-vx) + (y[0]-vy)*(y[0]-vy) + (z[0]-vz)*(z[0]-vz);
		p[i].y = (x[1]-vx)*(x[1]-vx) + (y[1]-vy)*(y[1]-vy) + (z[1]-vz)*(z[1]-vz);
	}
	KdTree *tree = KdTree::build(p.begin(), n, false);
	scanf("%d", &q);
	stringstream ss;
	for(i=0;i<q;i++) {
		scanf("%lld%lld", &a, &b);
		counter=0;
		ss << n - tree->range_count(a*a+1, b*b+1) << '\n';
		//if(1ll * counter * counter > 16*n) printf("conter = %d\n", counter);
	}
	cout << ss.str();
	if(tree) delete tree;
	return 0;
}
