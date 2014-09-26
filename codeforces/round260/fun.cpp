#include <iostream>
#include <deque>
#include <cmath>
#include <cstdio>
using namespace std;

const int N=1e5+1;
int cont[400][N];
deque<int> a[400];

int main() {
	int n, B;
	cin>>n;
	B = sqrt(n);
	if(B*B < n) B++;
	for(int i=1;i<=n;i++) {
		int x;
		scanf("%d", &x);
		int b = (i-1)/B;
		a[b].push_back(x);
		cont[b][x]++;
	}
	int q;
	cin>>q;
	int lastans=0;
	while(q--) {
		int t, l, r, k;
		scanf("%d", &t);
		if(t==1) {
			scanf("%d%d", &l, &r);
			l = ((l + lastans - 1) % n) + 1;
			r = ((r + lastans - 1) % n) + 1;
			if(l > r) swap(l, r);

			int br = (r-1) / B;
			int pr = r-1 - br*B;
			k = a[br][pr];
			a[br].erase(a[br].begin() + pr);
			cont[br][k]--;
			
			int bl = (l-1) / B;
			int pl = l-1 - bl*B;
			a[bl].insert(a[bl].begin() + pl, k);
			cont[bl][k]++;

			for(int b=bl;b<br;b++) {
				k = a[b].back();
				cont[b][k]--;
				cont[b+1][k]++;
				a[b].pop_back();
				a[b+1].push_front(k);
			}
		}
		else {
			scanf("%d%d%d", &l, &r, &k);
			l = ((l + lastans - 1) % n) + 1;
			r = ((r + lastans - 1) % n) + 1;
			if(l > r) swap(l, r);
			k = ((k + lastans - 1) % n) + 1;
			
			int br = (r-1) / B;
			int pr = r-1 - br*B;
			
			int bl = (l-1) / B;
			int pl = l-1 - bl*B;

			lastans = 0;
			if(bl == br) {
				for(int i=pl;i<=pr;i++) if(a[bl][i] == k) lastans++;
			}
			else {
				for(int i=pl;i<a[bl].size();i++) if(a[bl][i] == k) lastans++;
				for(int b=bl+1;b<br;b++) lastans += cont[b][k];
				for(int i=0;i<=pr;i++) if(a[br][i] == k) lastans++;
			}
			printf("%d\n", lastans);
		}
	}
	return 0;
}
