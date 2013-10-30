#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pp;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n, m, c;
		cin>>n>>m>>c;
		vector<vector<int> > comp(n);
		vector<int> cc(n);
		for(int i=0;i<n;i++) {
			cc[i] = i;
			comp[i].push_back(i);
		}
		
		vector<pp> E(m);
		for(int i=0;i<m;i++) {
			int a, b, r;
			cin>>a>>b>>r;
			E[i] = pp(r, pii(a-1, b-1));
		}
		sort(E.begin(), E.end());
		
		vector<int> F;
		int nc=n;

		for(int i=m-1;i>=0;i--) {
			int a = cc[E[i].second.first];
			int b = cc[E[i].second.second];
			int r = E[i].first;
			if(a == b) F.push_back(r);
			else {
				nc--;
				if(comp[a].size() < comp[b].size()) swap(a, b);
				for(int j=0;j<comp[b].size();j++) {
					cc[comp[b][j]] = a;
					comp[a].push_back(comp[b][j]);
				}
			}
		}
		
		sort(F.begin(), F.end());

		int nadd, nchange=0, cost=0;
		for(int i=0;i<F.size() && i<nc-1 && F[i] <= c; i++) {
			cost += F[i];
			nchange++;
		}
		nadd = nc-1-nchange;
		cost += c*nadd;

		cout << nadd << " " << nchange << " " << cost << endl;
		
	}
	return 0;
}
