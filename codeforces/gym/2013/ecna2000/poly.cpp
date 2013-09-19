#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, l[111], p[111];
vector<int> v[111];

void print(int x) {
    cout<<x<<":";
    vector<int> ans;
    for(int i=0;i<n;i++) if(binary_search(v[i].begin(), v[i].end(), x)) ans.push_back(l[i]);
    cout<<ans[0];
    for(int i=1;i<ans.size();i++) cout<<" "<<ans[i];
    cout<<endl;
}

int main() {
    while(1) {
        cin>>n;
        if(n==0) break;
        for(int i=0;i<n;i++) cin>>l[i];
        int s;
        cin>>s;
        for(int i=0;i<n;i++) {
            v[i].clear();
			ll x=0;
			for(ll k=1;;k++) {
				x += l[i]-1 + (k-2)*(l[i]-2);
				if(x > INT_MAX) break;
				if(x >= s) v[i].push_back(x);
			}
        }
		for(int i=0;i<n;i++) p[i]=0;
		int t=0;
		while(t!=5) {
			int c, m = INT_MAX;
			for(int i=0;i<n;i++) if(p[i] != v[i].size()) {
				int x = v[i][p[i]];
				if(m > x) m=x, c=1;
				else if(m==x) c++;
			}
			if(c!=1) print(m), t++;
			for(int i=0;i<n;i++) if(p[i] != v[i].size() && v[i][p[i]] == m) p[i]++;
		}
		cout<<endl;
    }
    return 0;
}
