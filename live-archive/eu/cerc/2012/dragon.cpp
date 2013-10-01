#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int l, x[55555], y[55555];
ll a[111], b[111], c[111];

bool cmp(int k) { return a[l]*x[k] + b[l]*y[k] + c[l] > 0; }

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n, m;
		cin>>n>>m;
		for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
		int p=0;
		for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(a[i]*b[j] != a[j]*b[i]) p++;
		for(int i=0;i<m;i++) cin>>x[i]>>y[i];
		vi v(m);
		for(int i=0;i<m;i++) v[i]=i;
		vector<vi> reg(1, v);
		for(l=0;l<n;l++) for(int j=reg.size()-1;j>=0;j--) {
			int d = partition(reg[j].begin(), reg[j].end(), cmp) - reg[j].begin();
			if(d == 0 || d == reg[j].size()) continue;
			reg.push_back(vi(reg[j].begin()+d, reg[j].end()));
			reg[j].resize(d);
		}
		if(reg.size() == p+n+1) cout<<"PROTECTED"<<endl;
		else cout<<"VULNERABLE"<<endl;
	}
	return 0;
}
