#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii v[111111];

int main() {
	int n;
	cin>>n;
	set<pii> s;
	for(int i=0;i<n;i++) {
		cin>>v[i].first>>v[i].second;
		if(v[i].first < v[i].second) swap(v[i].first, v[i].second);
		if(s.count(v[i])) {
			swap(v[i].first, v[i].second);
			if(s.count(v[i])) {
				cout << "Chaos" << endl; 
				return 0;
			}
		}
		s.insert(v[i]);
	}
	sort(v, v+n);
	reverse(v, v+n);
	for(int i=0;i<n;i++) cout << v[i].first << " " << v[i].second << endl; 
	return 0;
}
