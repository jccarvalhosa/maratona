#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;

int v[51];

int main() {
	int n;
	ll m;
	cin>>n>>m;
	m--;
	int i=0, f=n-1;
	for(int pos=1;pos<=n;pos++) {
		if((m < 1ll<<(n-pos-1))) {
			v[i++] = pos;
		} else {
			v[f--] = pos;
			m -= 1ll<<(n-pos-1);
		}
	}
	for(int i=0;i<n;i++) {
		if(i) cout << " ";
		cout << v[i];
	}
	cout << endl;
	return 0;
}
