#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

ll v[(int)1e5];

int main() {
	int n, m;
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		int a;
		for(int j=0;j<n/2;j++) {
			cin>>a;
			v[a] += 1ll<<i;
		}
		for(int j=0;j<n/2;j++) {
			cin>>a;
		}
	}
	int good=1;
	set<ll> s;
	for(int i=1;i<=n;i++) {
		if(s.count(v[i])) good=0;
		else s.insert(v[i]);
	}
	cout << (good ? "TAK" : "NIE") << endl;
	return 0;
}
