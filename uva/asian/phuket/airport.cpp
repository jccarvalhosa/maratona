#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int M = 22222;
int n, p[M], s[M], t[M];

void add(int x, int v) { for(;x<=n;x+=x&-x) t[x]+=v; }
int sum(int x) { int ret=0; for(;x;x-=x&-x) ret += t[x]; return ret; }

int main() {
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++) {
		int k, x=0, y=0;
		cin>>n>>k;
		for(int i=0;i<n;i++) { cin>>p[i]; p[i]--; }
		for(int i=0;i<n;i++) {
			int ii = p[i]/k*k;
			int ff = ii+k-1;
			if(i < ii) y = max(y, ii-i);
			if(i > ff) y = max(y, i-ff);
		}
		int m = (n+k-1)/k;
		vector<vector<int> > v(m);
		for(int i=0;i<n;i++) v[p[i]/k].push_back(i);
		for(int i=0;i<M;i++) t[i]=s[i]=0;
		for(int i=0;i<n;i++) {
			int ii = v[i/k][s[i/k]++];
			x += ii + sum(n) - sum(ii+1) - i;
			add(ii+1, 1);
		}
		cout<<"Case "<<tt<<": "<<x-y<<endl;
	}
	return 0;
}
