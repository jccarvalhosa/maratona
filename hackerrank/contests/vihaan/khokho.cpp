#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n, k, i, ans=0;
		cin>>n>>k;
		vector<vector<int> > v(k);
		for(i=0;i<n;i++) {
			int x;
			cin>>x;
			v[i%k].push_back(x);
		}
		for(i=0;i<k;i++) {
			for(int j=0;j<v[i].size();j++) {
				int jj=j-1;
				while(jj>=0 && v[i][jj] > v[i][jj+1]) {
					swap(v[i][jj], v[i][jj+1]);
					jj--;
					ans++;
				}
			}
		}
		vector<int> w(n), pos(k, 0);
		for(i=0;i<n;i++) w[i] = v[i%k][pos[i%k]++];
		for(i=1;i<n;i++) if(w[i] < w[i-1]) break;
		if(i==n) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
