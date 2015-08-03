#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;

struct prob {
	int a, b, id;
	ll t;
}p[N];

int n, f;
vector<int> ans;

bool cmp(prob a, prob b) { return a.t<b.t; }

int valid(ll v, int flag) {
	ll t=0;
	for(int i=0, j; i<n; i=j) {
		t+=f;
		ll _max=-1ll<<60;
		for(j=i; j<n; j++) {
			_max=max(_max+p[j].a, t+p[j].a+p[j].b-p[j].t);
			if(_max>v) break;
			t+=p[j].a+p[j].b;
		}
		if(i==j) return 0;
		if(flag) {
			for(int k=i; k<j; k++) ans.push_back(-p[k].id);
			for(int k=i; k<j; k++) ans.push_back(p[k].id);
		}
	}
	return 1;
}

int main() {
	int ft, fc;
	scanf("%d %d %d", &n, &ft, &fc);
	f=ft+fc;
	for(int i=0; i<n; i++) {
		scanf("%d %d %I64d", &p[i].a, &p[i].b, &p[i].t);
		p[i].id=i+1;
	}
	sort(p, p+n, cmp);
	ll lo=0, mid, hi=1e12;
	while(lo<hi) {
		mid=(lo+hi)/2;
		if(valid(mid, 0)) hi=mid;
		else lo=mid+1;
	}
	printf("%I64d\n", lo);
	valid(lo, 1);
	for(int i=0; i<ans.size(); i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
