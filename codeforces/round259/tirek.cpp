#include <algorithm>
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N=1e5+1;

int n, q;
ll tr[N], tm[N];
ll ans[N];

void add(ll* t, int p, ll v) { for(;p<=n;p+=p&-p) t[p] += v; }
ll sum(ll* t, int p) { ll ret=0; for(;p;p-=p&-p) ret += t[p]; return ret; }
ll sum(ll* t, int a, int b) { return sum(t, b) - sum(t, a-1); }

struct Interval {
	int l, r, last;
	Interval(int l=0, int r=0, int last=-1) : l(l), r(r), last(last) {}
	bool operator <(const Interval &x)const { return l < x.l; }
};

struct Query {
	Interval i;
	ll t;
	int pos;
	Query(Interval i, ll t, int pos) : i(i), t(t), pos(pos) {}

	ll elapsed() const { return t - i.last; }
	bool operator <(const Query &q)const { return this->elapsed() < q.elapsed(); }
};

struct Poney { 
	int s, m, r, pos, g;
	Poney(int s=0, int m=0, int r=0, int pos=0) : s(s), m(m), r(r), pos(pos) {
		g = r == 0 ? 1e9 : (m + r - 1) / r;
	}
	bool operator <(const Poney &p)const { return g < p.g; }
};

Poney p[N];

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		int s, m, r;
		scanf("%d%d%d", &s, &m, &r);
		p[i] = Poney(s, m, r, i);
	}
	
	set<Interval> s;
	s.insert(Interval(1, n));
	
	vector<Query> pend;

	cin>>q;	
	for(int pos=0;pos<q;pos++) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		
		vector<Interval> add;
		add.push_back(Interval(l, r, t));
		set<Interval>::iterator it = --s.upper_bound(Interval(l));
		while(1) {
			if(it->r > r) add.push_back(Interval(r+1, it->r, it->last));
			if(it->l < l) add.push_back(Interval(it->l, l-1, it->last));

			if(it->last == -1) {
				for(int x=max(l, it->l); x<=min(r, it->r); x++) ans[pos] += min(1ll*p[x].m, p[x].s + 1ll*t * p[x].r);
			}
			else {
				pend.push_back(Query(Interval(max(l, it->l), min(r, it->r), it->last), t, pos));
			}
			s.erase(it++);

			if(it == s.end() || it->l > r) break;
		}
		for(int i=0;i<add.size();i++) s.insert(add[i]);
	}

	sort(pend.begin(), pend.end());
	sort(p+1, p+n+1);

	for(int i=1;i<=n;i++) add(tr, p[i].pos, p[i].r);
	int ip = 1;
	for(int i=0;i<pend.size();i++) {
		while(ip <= n && pend[i].elapsed() * p[ip].r >= p[ip].m) {
			add(tr, p[ip].pos, -p[ip].r);
			add(tm, p[ip].pos,  p[ip].m);
			ip++;
		}
		ans[pend[i].pos] += sum(tm, pend[i].i.l, pend[i].i.r);
		ans[pend[i].pos] += sum(tr, pend[i].i.l, pend[i].i.r) * pend[i].elapsed();
	}
	for(int i=0;i<q;i++) cout << ans[i] << endl;
	return 0;
}
