#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int N=1e5;

struct Expression {
	int root;
	int sign;
	int offset;
	Expression(int root=0, int sign=0, int offset=0) : root(root), sign(sign), offset(offset) {}
};

//Expression to calculate the value for element v: val[v] = val[e[v].root] * e[v].sign + e[v].offset
Expression e[N];

int n, hasval[N], val[N];
map<int, int> id;

void updateExpression(int x) {
	int par = e[x].root;
	if(e[par].root != par) {
		updateExpression(par);
		e[x] = Expression (
			e[par].root,
			e[par].sign * e[x].sign,
			e[par].offset * e[x].sign + e[x].offset
		);
	}
}

void add(int x, int y, int a) {
	int par = e[x].root;
	if(x == y) {
		hasval[par] = 1;
		val[par] = (a - e[x].offset) * e[x].sign;
	}
	else if(e[x].root == e[y].root && e[x].sign == e[y].sign) {
		hasval[par] = 1;
		val[par] = (a - e[x].offset - e[y].offset) * e[x].sign / 2; 
	}
	else if(e[x].root != e[y].root) {

		if(hasval[e[y].root]) swap(x, y);
		
		e[e[y].root] = Expression (
			e[x].root, 
			- e[x].sign * e[y].sign, 
			(a - e[y].offset - e[x].offset) * e[y].sign
		);
	}
}

int getid(int x) {
	if(id.count(x)) return id[x];
	hasval[n]=0;
	e[n] = Expression(n, 1, 0);
	return id[x] = n++;
}

int main() {
	int m, q;
	while(scanf("%d%d", &m, &q)  && m) {
		n=0;
		id.clear();
		while(m--) {
			int x, y, a;
			scanf("%d%d%d", &x, &y, &a);
			x = getid(x);
			y = getid(y);
			updateExpression(x);
			updateExpression(y);
			add(x, y, a);
		}
		while(q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			if(!id.count(x) || !id.count(y)) {
				printf("*\n");
				continue;
			}
			x = id[x];
			y = id[y];
			updateExpression(x);
			updateExpression(y);
			int px = e[x].root;
			int py = e[y].root;
			if(hasval[px] && hasval[py]) {
				int vx = val[px] * e[x].sign + e[x].offset;
				int vy = val[py] * e[y].sign + e[y].offset;
				printf("%d\n", x == y ? vx : vx + vy);
			}
			else if(px == py && e[x].sign + e[y].sign == 0) {
				printf("%d\n", e[x].offset + e[y].offset);
			}
			else {
				printf("*\n");
			}
		}
		printf("-\n");
	}
	return 0;
}
