#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ull um=1;

set<ull> s;
set<ull>::iterator it;
vector<ull> v;

int main() {
	ll id;
	int r, i, n;
	cin >> n >> r;
	for(i=0; i<r; i++) {
		cin >> id;
		while(id) {
			if(s.count(id)) break;
			s.insert(id);
			id/=2;
		}
	}
	for(it=s.begin(); it!=s.end(); it++) {
		if((*it)>=(um<<n)) continue;
		if(!s.count(2*(*it))) v.push_back(2*(*it));
		if(!s.count(2*(*it)+1)) v.push_back(2*(*it)+1);
	}
	cout << v[0];
	for(i=1; i<v.size(); i++) cout << " " << v[i];
	cout << endl;
}
