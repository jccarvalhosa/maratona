#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Filtering {
	vector<int> designFilter(vector<int> sizes, string outcome) {
		vector<int> valid(101, -1);
		for(int i=0;i<outcome.size();i++) {
			if(outcome[i] == 'A') {
				valid[sizes[i]] = 1;
			}
			else {
				valid[sizes[i]] = 0;
			}
		}
		int m=100, M=-1;
		for(int i=1;i<=100;i++) if(valid[i]==1) m=min(m, i), M=max(M, i);
		for(int i=m;i<=M;i++) if(valid[i]==0) return vector<int>();
		vector<int> ans;
		ans.push_back(m);
		ans.push_back(M);
		return ans;
	}
};
