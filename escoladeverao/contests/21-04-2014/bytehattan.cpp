#include <iostream>
#include <cstdio>
#include <vector>
#define ff first
#define ss second

using namespace std;

typedef pair<int,int> pii;
int n;

pii face_edge(int a, int b, char c) {
	if(c == 'E') {
		int l = ((b == 1) ? 0 : (a-1)*(n-1)+b-1);
		int r = ((b == n) ? 0 : (a-1)*(n-1)+b);
		return pii(l,r);
	}
	else {
		int u = ((a == 1) ? 0 : (a-2)*(n-1)+b);
		int d = ((a == n) ? 0 : (a-1)*(n-1)+b);
		return pii(u,d);
	}
}

int pai[3333333], ran[3333333];

void init(int p) {
	for(int i=0;i<p;i++) {
		pai[i] = i;
		ran[i] = 0;
	}
}

int find(int x) {
	if(x != pai[x]) pai[x] = find(pai[x]);
	return pai[x];
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if(x==y) return;
	if(ran[x] < ran[y]) {
		pai[x] = y;
	}
	else if(ran[y] < ran[x]){
		pai[y] = x;
	}
	else {
		pai[y] = x;
		ran[x]++;
	}
}

int main() {
	int k, l=0;
	scanf("%d%d", &n, &k);
	init(n*n);
	for(int i=0;i<k;i++) {
		int a, b, d, e;
		char c, f;
		scanf("%d %d %c %d %d %c", &a, &b, &c, &d, &e, &f);
		pii g;
		if(!l) g = face_edge(a,b,c);
		else g = face_edge(d,e,f);
		l = 0;
		if(find(g.ff) == find(g.ss)) l = 1;
		merge(g.ff,g.ss);
		printf("%s\n", l ? "NIE" : "TAK");
	}
	return 0;
}
