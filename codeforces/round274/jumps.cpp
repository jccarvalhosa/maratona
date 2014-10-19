#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

const int N=1e5+1;
int v[N];
set<int> s;

int main() {
	int n, l, x, y;
	cin>>n>>l>>x>>y;
	for(int i=0;i<n;i++) scanf("%d", &v[i]);
	int fx=0, fy=0;
	for(int i=0;i<n;i++) {
		if(binary_search(v, v+i+1, v[i]-x)) fx=1;
		if(binary_search(v, v+i+1, v[i]-y)) fy=1;
	}
	if(fx && fy) cout << 0 << endl;
	if(!fx && fy) cout << 1 << endl << x << endl;
	if(fx && !fy) cout << 1 << endl << y << endl;
	if(!fx && !fy) {
		s.insert(x);
		for(int i=0;i<n;i++) {
			if(v[i]>x) s.insert(v[i]-x);
			if(v[i]+x<l) s.insert(v[i]+x);
		}
		if(s.count(y)) {
			cout << 1 << endl << y << endl;
			return 0;
		}
		for(int i=0;i<n;i++) {
			if(s.count(v[i]-y)) {
				cout << 1 << endl << v[i]-y << endl;
				return 0;
			}
			if(s.count(v[i]+y)) {
				cout << 1 << endl << v[i]+y << endl;
				return 0;
			}
		}
		cout << 2 << endl << x << " " << y << endl;
	}
	return 0;
}
