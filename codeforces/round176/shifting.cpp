#include <cstdio>
#include <algorithm>
using namespace std;

int v[2000000];

int main() {
	int n, i, f, d, p, x;
	scanf("%d", &n);
	for(i=0;i<n;i++) v[i]=i+1;
	for(d=2;d<=n;d++) {
		i = d-2;
		f = n+i-1;
		x = v[i];
		for(p=i+d;p<=f;p+=d) swap(v[p], x);
		v[f+1] = x;
	}
	for(p=i+1;p<=f+1;p++) printf("%d%c", v[p], p!=f+1?' ':'\n');
	return 0;
}
