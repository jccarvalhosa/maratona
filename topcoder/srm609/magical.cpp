#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct MagicalStringDiv1 {
	int getLongest(string s) {
		int n = s.size();
		vector<int> c1(n+2, 0);
		vector<int> c2(n+2, 0);
		for(int i=1;i<=n;i++) {
			c1[i] = c1[i-1];
			if(s[i-1] == '>') c1[i]++;
		}
		for(int i=n;i>=1;i--) {
			c2[i] = c2[i+1];
			if(s[i-1] == '<') c2[i]++;
		}
		int ans=0;
		for(int i=1;i<n;i++) ans = max(ans, min(c1[i], c2[i+1]));
		return 2*ans;
	} 
};
