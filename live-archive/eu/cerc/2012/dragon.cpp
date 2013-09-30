#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int x[55555], y[55555];
ll a[111], b[111], c[111];

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
		vi v;
		vector<vi> space;
		for(int i=0;i<m;i++) v.push_back(i);
		space.push_back(v);
		int i;
		for(i=0;i<n;i++) {
			vector<vi> newspace;
			for(int j=0;j<space.size();j++) {
				vi u1, u2, v = space[j];
				for(int jj=0;jj<v.size();jj++) {
					int k = v[jj];
					if(a[i]*x[k] + b[i]*y[k] + c[i] > 0) u1.push_back(k);
					else u2.push_back(k);
				}
				if(!u1.empty()) newspace.push_back(u1);
				if(!u2.empty()) newspace.push_back(u2);
			}
			space = newspace;
		}
		if(space.size() == p+n+1) cout<<"PROTECTED"<<endl;
		else cout<<"VULNERABLE"<<endl;
	}
	return 0;
}
