#include <cstdio>

int n, k, t[10000];

int busca(int a, int b) {
	int i, p=0, mid=(a+b)/2;
	if(a==b) return a; 
	for(i=0;i<k;i++) p += t[i]/mid;
	if(p < n) return busca(a, mid);
	else return busca(mid+1, b);
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i=0;i<k;i++) scanf("%d", &t[i]);
	printf("%d", busca(1, 10001)-1);
	return 0;
}
