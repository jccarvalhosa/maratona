#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int main() {
	ifstream in("bad.in");
	ofstream out("bad.out");
	int n, m;
	while(in>>n>>m && !in.eof()) {
		map<int, string> name;
		for(int i=0;i<n;i++) {
			string s; in>>s;
			name[i] = s;
		}
		name[n] = "Invalid";
		vector<int> v(n+1, 0);
		for(int i=0;i<m;i++) {
			string s; in>>s;
			int c=0, pos;
			for(int j=0;j<n;j++) if(s[j] == 'X') {
				pos=j;
				c++;
			}
			if(c!=1) v[n]++;
			else v[pos]++;
		}
		vector<pii> obj(n+1);
		for(int i=0;i<=n;i++) obj[i] = pii(-v[i], i);
		sort(obj.begin(), obj.begin()+n);
		for(int i=0;i<=n;i++) out << fixed << setprecision(2) << name[obj[i].second] << " " << 100.0*v[obj[i].second]/m+1e-5 << "%" << endl;
	}
	return 0;
}
