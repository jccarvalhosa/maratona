#include <iostream>
#include <cstdio>
using namespace std;

const int N=1e5+10;
int sum[N];

int main() {
	int n, q;
	cin>>n>>q;
	int b=0, e=n, flip=0;
	for(int i=0;i<=n;i++) sum[i]=i;
	while(q--) {
		int t;
		scanf("%d", &t);
		int tam = e-b;
		if(t==1) {
			int p;
			scanf("%d", &p);
			int dir = flip;
			if(2*p > tam) {
				dir ^= 1;
				flip ^= 1;
				p = tam - p;
			}
			if(dir == 0) {
				for(int i=b+2*p;i>=b+p;i--) sum[i] -= sum[2*b+2*p-i];
				b += p;
			}
			else {
				for(int i=e-2*p;i<=e-p;i++) sum[i] += n - sum[2*e-2*p-i];
				e -= p;
			}
		}
		else {
			int l, r;
			scanf("%d%d", &l, &r);
			if(!flip) {
				l = b + l;
				r = b + r;
			}
			else {
				int auxl = l;
				l = b + (tam-r);
				r = b + (tam-auxl);
			}
			printf("%d\n", sum[r] - sum[l]);
		}
	}
	return 0;
}
