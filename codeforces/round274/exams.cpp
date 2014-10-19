#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> pp;

const int N=5005;
pp p[N];
pp v[2*N];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		int a, b;
		cin>>a>>b;
		p[i] = pp(pii(a, b), i);
		v[2*i] = pp(pii(a, b), i);
		v[2*i+1] = pp(pii(b, a), i);
	}
	sort(p, p+n);
	sort(v, v+2*n);
	int pos=0;
	for(int i=0;i<2*n;i++) {
		if(v[i].second == p[pos].second) pos++;
		if(pos == n) {
			cout << v[i].first.first << endl;
			return 0;
		}
	}
	return 0;
}
