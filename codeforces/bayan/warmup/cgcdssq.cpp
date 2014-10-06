#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

map<int, ll> cnt;

int n;
const int N=1e5+7;
int a[N];

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	map<int, ll> old;
	for(int i=1;i<=n;i++) {
		map<int, ll> aux;
		aux[a[i]]=1;
		for(map<int, ll>::iterator it = old.begin(); it != old.end(); it++) {
			aux[__gcd((*it).first, a[i])] += (*it).second;
		}
		for(map<int, ll>::iterator it = aux.begin(); it != aux.end(); it++) {
			cnt[(*it).first] += (*it).second;
		}
		old = aux;
	}
	int q;
	cin>>q;
	while(q--) {
		int x;
		scanf("%d", &x);
		cout << cnt[x] << "\n";
	}
	return 0;
}
