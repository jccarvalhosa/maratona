#include <vector>
#include <algorithm>
using namespace std;

struct BinPackingEasy {
	int minBins(vector<int> v) {
		sort(v.begin(), v.end());
		int ans=0;
		int i=0, f=v.size()-1;
		while(f>=i) {
			if(f==i) {
				ans++;
				break;
			}
			if(v[f]+v[i] <= 300) {
				f--;
				i++;
				ans++;
			}
			else {
				f--;
				ans++;
			}
		} 
		return ans;
	}
};
