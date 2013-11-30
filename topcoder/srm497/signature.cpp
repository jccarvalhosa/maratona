#include <vector>
#include <string>
using namespace std;

struct PermutationSignature {
	vector<int> reconstruct(string s) {
		vector<int> ans;
		int p=0, i=0;
		while(i<s.size()) {
			for(;i<s.size();i++) if(s[i] == 'I') break;
			int np = i+1;
			for(int j=np;j>p;j--) ans.push_back(j);
			p = np;
			if(i==s.size()-1) ans.push_back(p+1);
			i++;
		}
		return ans;
	}
};
