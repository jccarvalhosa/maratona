#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

typedef pair<string, int> psi;

const int N=2e5+1;
psi p[N];
int ord[N];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		string a, b;
		cin>>a>>b;
		p[2*i] = psi(a, i+1);
		p[2*i+1] = psi(b, i+1);
	}
	for(int i=0;i<n;i++) cin>>ord[i];
	sort(p, p+2*n);
	int pos=0;
	for(int i=0;i<2*n;i++) {
		if(p[i].second == ord[pos]) {
			pos++;	
			if(pos == n) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
