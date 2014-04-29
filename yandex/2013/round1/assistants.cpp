#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N=5e5+10;
int n, a[N], b[N], my[N];
ll t[N];
char c[N];
vector<pii> v;

int valid(ll m) {
	priority_queue<pii> q;
	for(int i=0;i<v.size();i++) {
		ll step = m - v[i].first;
		int pos = v[i].second;
		my[pos]=0;
		if(step <= 0) my[pos]=1;
		else {
			q.push(pii(-b[pos], pos));
			while(q.size() > step) {
				my[q.top().second]=1;
				q.pop();
			}
		}
	}
	int cont=0;
	for(int i=0;i<v.size();i++) {
		int pos = v[i].second;
		if(!my[pos]) {
			t[pos] = ++cont;
			c[pos] = 'A';
		}
	}
	ll mytime = cont;
	for(int pos=0;pos<n;pos++) if(my[pos]) {
		t[pos] = mytime+1;
		c[pos] = 'B';
		mytime += b[pos];
	}
	return mytime <= m;
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++) scanf("%d%d", &b[i], &a[i]);
	v.clear();
	for(int i=0;i<n;i++) v.push_back(pii(a[i], i));
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	ll i=0, f=1e15;
	while(i<f-1) {
		ll m = (i+f)/2;
		if(valid(m)) f=m;
		else i=m;
	}
	valid(f);
	printf("%lld\n", f);
	for(int i=0;i<n;i++) printf("%c %lld\n", c[i], t[i]);
	return 0;
}
