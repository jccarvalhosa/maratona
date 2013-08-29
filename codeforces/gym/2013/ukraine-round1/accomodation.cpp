#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int n, log[111111];

int dist(const pii a) {
	if(a.first==1 || a.second==n) return 1+(a.second-a.first);
	return 1+(a.second-a.first)/2;
}

int num(const pii a) {
	if(a.first==1 || a.second==n) return 1;
	if((a.second-a.first)%2 == 1) return 1;
	return 2;
}

int mid(const pii a) {
	if(a.second==n) return n;
	if(a.first==1) return 1;
	return (a.first + a.second+1)/2;
}

struct mycmp {
	bool operator() (const pii &a, const pii &b) {
		int da = dist(a);
		int db = dist(b);
		if(da != db) return da<db;
		int na = num(a);
		int nb = num(b);
		if(na != nb) return na>nb;
		return mid(a)<mid(b);
	}
};

priority_queue<pii, vector<pii>, mycmp> q;
set<pii> s;

void add(int a, int b) {
	if(b>=a) {
		q.push(pii(a, b));
		s.insert(pii(a, b));
	}
}

int enter() {
	while(1) {
		pii p = q.top();
		q.pop();
		if(!s.count(p)) continue;
		s.erase(p);
		int m = mid(p);
		add(p.first, m-1);
		add(m+1, p.second);
		return m;
	}
}

void leave(int m) {
	int a=m, b=m;
	set<pii>::iterator it = s.lower_bound(pii(m+1, 0));
	if(it == s.begin()) {
		if(it->first == m+1) {
			b = it->second;
			s.erase(it);
		}
	}
	else {
		if(it == s.end() || it->first != m+1) it--;
		else {
			b = it->second;
			s.erase(it--);
		}
		if(it->second == m-1) {
			a = it->first;
			s.erase(it);
		}
	}
	add(a, b);
}

int main() {
	int c, Q;
	cin>>n>>Q;
	add(1, n);
	for(int i=1;i<=Q;i++) {
		cin>>c;
		if(c==0) {
			int m = enter();
			cout<<m<<endl;
			log[i] = m;
		}
		if(c==1) {
			int pos;
			cin>>pos;
			int m = log[pos];
			leave(m);
		}
	}
	return 0;
}
