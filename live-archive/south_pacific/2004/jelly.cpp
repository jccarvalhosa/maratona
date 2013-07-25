#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	while(1) {
		cin>>n;
		if(n==0) break;
		vector<pair<int, string> > v(n);
		for(int i=0;i<n;i++) {
			string s;
			int a, b, c;
			cin>>s>>a>>b>>c;
			v[i] = make_pair(a*b*c, s);
		}
		pair<int, string> a = *min_element(v.begin(), v.end());
		pair<int, string> b = *max_element(v.begin(), v.end());
		if(a.first == b.first) cout << "No child has lost jelly." << endl;
		else cout << a.second << " has lost jelly to " << b.second << "." << endl;
	}
	return 0;
}
