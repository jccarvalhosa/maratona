#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> v[500];

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		int n;
		cin>>n;
		getchar();
		for(int i=0;i<n;i++) {
			string line;
			getline(cin, line);
			stringstream ss;
			ss<<line;
			v[i].clear();
			while(!ss.eof()) {
				string s;
				ss>>s;
				v[i].push_back(s);
			}
		}
		int sol = 1e9;
		for(int vis=0;vis<1<<n;vis++) {
			int c0 = (vis & 1) ? 1 : 2;
			int c1 = (vis & 2) ? 1 : 2;
			if(c0 != 1 || c1 != 2) continue;
			int aux=0;
			map<string, int> lang;
			for(int i=0;i<n;i++) {
				int c = (vis & (1<<i)) ? 1 : 2;
				for(int pos=0;pos<v[i].size();pos++) {
					if((lang[v[i][pos]] & c) == c) continue;
					if((lang[v[i][pos]] |= c) == 3) aux++;
				}
			}
			sol = min(sol, aux);
		}
		cout << "Case #"<<t<<": "<<sol<<endl; 
	}
	return 0;
}
