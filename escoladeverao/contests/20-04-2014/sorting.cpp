#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int v[1111111];

int main() {
	int n, k;
	set <int> s;
	int sorted=0;
	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> v[i];
	for(int i=0;i<k;i++) s.insert(v[i]);
	if(*s.begin() < v[0]) {
		sort(v,v+k);
		sorted=1;
	}
	else {
		for(int i=k;i<n;i++) {
			s.erase(v[i-k]);
			s.insert(v[i]);
			if(*s.begin() < v[i-k+1]) {
				sort(v+i-k+1, v+i+1);
				sorted=1;
				break;
			}
		}
	}
	if(!sorted) sort(v+n-k, v+n);
	cout << v[0];
	for(int i=1;i<n;i++) cout << " " << v[i];
	cout << endl;
	return 0;
}
