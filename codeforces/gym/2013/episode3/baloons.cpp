#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int diffa[55555], diffb[55555];

int main() {
	while(1) {
		int n, a, b;
		cin>>n>>a>>b;
		if(n==0) return 0;
		int va=0, vb=0;
		ll ans=0;
		for(int i=0;i<n;i++) {
			int x, da, db;
			cin>>x>>da>>db;
			for(int j=0;j<x;j++) {
				ans += min(da, db);
				if(da > db) diffb[vb++] = da - db;
				else diffa[va++] = db - da;
			}
		}
		if(va > a) {
			sort(diffa, diffa+va);
			for(int i=0;i<va-a;i++) ans += diffa[i];
		}
		if(vb > b) {
			sort(diffb, diffb+vb);
			for(int i=0;i<vb-b;i++) ans += diffb[i];
		}
		cout<<ans<<endl;
	}
}
