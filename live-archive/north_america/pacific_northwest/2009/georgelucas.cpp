#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[1<<7];

int main() {
	int n;
	string s;
	while(1) {
		cin>>s;
		if(s=="0") break;
		n = s.size();
		for(int i=0;i<1<<n;i++) v[i].clear();
		for(int i=0;i<n;i++) v[1<<i].push_back(s[i]-'0');
		for(int i=1;i<1<<n;i++) {
			for(int a=1;a<i;a++) {
				int j, b=0;
				for(j=0;j<n;j++) {
					if(i & (1<<j)) {
						if((a & (1<<j)) == 0) b += 1<<j;
					} else {
						if(a & (1<<j)) break;
					}
				}
				if(j<n) continue;
				for(int ii=0;ii<v[a].size();ii++) for(int jj=0;jj<v[b].size();jj++) {
					int x = v[a][ii];
					int y = v[b][jj];
					if(x<y) swap(x, y);
					v[i].push_back(x+y);
					v[i].push_back(x-y);
					v[i].push_back(x*y);
					if(y!=0) v[i].push_back(x/y);
				}
			}
			sort(v[i].begin(), v[i].end());
			v[i].resize(distance(v[i].begin(), unique(v[i].begin(), v[i].end())));
		}
		int x = (1<<n) - 1;
		if(v[x][0] > 1) cout<<1<<endl;
		else {
			int i;
			for(i=1;i<v[x].size();i++) if(v[x][i] != v[x][i-1] + 1) {
				cout<<v[x][i-1]+1<<endl;
				break;
			}
			if(i==v[x].size()) cout<<v[x][i-1]+1<<endl;
		}
	}
	return 0;
}
