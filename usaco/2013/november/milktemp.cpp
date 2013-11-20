#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream in("milktemp.in");
	ofstream out("milktemp.out");
	vector<int> v, vs, ve;
	int n, x, y, z;
	in>>n>>x>>y>>z;
	for(int i=0;i<n;i++) {
		int a, b;
		in>>a>>b;
		vs.push_back(a);
		ve.push_back(b);
		v.push_back(a);
		v.push_back(b);
	}
	sort(v.begin(), v.end());
	sort(vs.begin(), vs.end());
	sort(ve.begin(), ve.end());
	int ans=0;
	for(int i=0;i<v.size();i++) {
		int n1 = lower_bound(ve.begin(), ve.end(), v[i]) - ve.begin();
		int n2 = vs.end() - upper_bound(vs.begin(), vs.end(), v[i]);
		ans = max(ans, z*n1 + y*(n-n1-n2) + x*n2);
	}
	out<<ans<<endl;
	return 0;
}
