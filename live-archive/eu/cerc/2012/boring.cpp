#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int v[222222], next[222222], last[222222];

int valid(int a, int b) {
	if(a>=b) return 1;
	for(int d=0;d<=(b-a+1);d++) {
		int m = d%2 ? a+d/2 : b-d/2;
		if(next[m] > b && last[m] < a) return valid(a, m-1) && valid(m+1, b);
	}
	return 0;
}

int main() {
	int n, t, a, f;
	scanf("%d", &t);
	while(t--) {
		map <int,int> m;
		scanf("%d", &n);
		for(int i=0;i<n;i++) last[i] = -1;
		for(int i=0;i<n;i++) next[i] = n;
		for(int i=0; i<n; i++)  {
			scanf("%d", &v[i]);
			if(m.count(v[i])) {
				next[m[v[i]]] = i;
				last[i] = m[v[i]];
			}
			m[v[i]]=i;
		}
		printf("%s\n", valid(0, n-1) ? "non-boring" : "boring");
	}
	return 0;
}
