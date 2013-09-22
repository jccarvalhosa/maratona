#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int mod(int a) { return a>0 ? a : -a; }

int c[1111], vb[1111];
ll sb[1111];
pii va[1111];

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
		int nb=0;
		for(int i=0;i<n;i++) if(b[i]=='1') vb[nb++] = c[i];
		sort(vb, vb+nb);
		sb[0] = vb[0];
		for(int i=1;i<nb;i++) sb[i] = sb[i-1] + vb[i];
		ll best = 1ll<<62;
		for(int t=0;t<=nb;t++) {
			a=aux;
			int k=0;
			ll sum=0;
			ll ans=0;
			for(int i=0;i<n;i++) if(a[i]=='1') sum += c[i];
			int diff=0;
			for(int i=0;i<n;i++) if(a[i] != b[i]) diff++;
			int pos=nb-1;
			int j;
			for(int j=na-1;j>=0;j--) {
				int v = va[j].first, i=va[j].second;
				while(pos != -1 && vb[pos] >= v) pos--;
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
			vector<int> v;
			for(int i=0;i<n;i++) if(b[i]=='1' && a[i]=='0') v.push_back(c[i]);
			sort(v.begin(), v.end());
			for(int i=0;i<v.size();i++) ans += sum+v[i], sum+=v[i];
			best = min(best, ans);
		}
		printf("Case %d: ", T++);
		cout<<best<<endl;
	}
}
