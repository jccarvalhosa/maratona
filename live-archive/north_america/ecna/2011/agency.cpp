#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int c[1111];
pii va[1111], vc[1111];

int main() {
	int n, T=1;
	while(1) {
		cin>>n;
		if(n==0) return 0;
		string a, b;
		cin>>a>>b;
		string aux=a;
		for(int i=0;i<n;i++) cin>>c[i];
		int na=0;
		for(int i=0;i<n;i++) if(a[i]=='1') va[na++] = pii(c[i], i);
		sort(va, va+na);
		for(int i=0;i<n;i++) vc[i] = pii(c[i], i);
		sort(vc, vc+n);
		ll best = 1ll<<62;
		for(int t=0;t<=n;t++) {
			a=aux;
			int k=0;
			ll sum=0;
			ll ans=0;
			for(int i=0;i<n;i++) if(a[i]=='1') sum += c[i];
			int diff=0;
			for(int i=0;i<n;i++) if(a[i] != b[i]) diff++;
			int j;
			for(int j=na-1;j>=0;j--) {
				int v = va[j].first, i=va[j].second;
				if(b[i] == '0') {
					ans += sum-v;
					sum -= v;
					a[i]='0';
					diff--;
				} 
				else if(k!=t) {
					ans += sum-v;
					sum -= v;
					a[i]='0';
					diff++;
					k++;
				}
			}
			for(int j=0;j<n;j++) {
				int v=vc[j].first, p=vc[j].second;
				if(b[p]=='1' && a[p]=='0') {
					sum += v;
					ans += sum;
				}
			}
			best = min(best, ans);
			if(k != t) break;
		}
		printf("Case %d: ", T++);
		cout<<best<<endl;
	}
}
