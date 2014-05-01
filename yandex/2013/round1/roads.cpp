#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
typedef unsigned long long ull;

const int N=2e6+10;
ull v[N];
int a[N], b[N];
ull x[N];

int main() {
	int n, q;
	srand(time(NULL));
	scanf("%d%d", &n, &q);
	int i=1;
	while(q--) {
		int t;
		scanf("%d", &t);
		if(t==1) {
			scanf("%d%d", &a[i], &b[i]);
			ull v1 = rand() & ((1<<16)-1);
			ull v2 = rand() & ((1<<16)-1);
			ull v3 = rand() & ((1<<16)-1);
			ull v4 = rand() & ((1<<16)-1);
			x[i] = v1 + (v2<<16) + (v3<<32) + (v4<<48);
			v[a[i]] ^= x[i];
			v[b[i]] ^= x[i];
			i++;
		}
		if(t == 2) {
			int pos;
			scanf("%d", &pos);
			v[a[pos]] ^= x[pos];
			v[b[pos]] ^= x[pos];
		}
		if(t == 3) {
			int k;
			scanf("%d", &k);
			ull prod=0;
			for(int j=0;j<k;j++) {
				int pos;
				scanf("%d", &pos);
				prod ^= v[pos];
			}
			if(prod == 0) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
