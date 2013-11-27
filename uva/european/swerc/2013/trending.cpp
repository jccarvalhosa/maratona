#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

map<string, int> m, day[1001], week;

int main() {
	string s;
	int d=0;
	vector<int> v;
	while(cin>>s && !cin.eof()) {
		if(s == "<text>") {
			while(cin>>s && s != "</text>") if(s.size() >= 4) day[d][s]++;
			if(d>=7) for(map<string, int>::iterator it=day[d-7].begin(); it != day[d-7].end(); it++) week[it->first] -= it->second;
			for(map<string, int>::iterator it=day[d].begin(); it != day[d].end(); it++) week[it->first] += it->second;
			v.clear();
			for(map<string, int>::iterator it=week.begin(); it != week.end(); it++) v.push_back(it->second);
			d++;
		}
		else {
			int p;
			cin>>p;
			cin>>s;
			p = min(p, (int)v.size());
			nth_element(v.begin(), v.begin()+p-1, v.end(), greater<int>());
			int x = v[p-1];
			vector<pair<int, string> > ans;
			for(map<string, int>::iterator it=week.begin(); it != week.end(); it++) if(it->second >= x && it->second != 0) {
				ans.push_back(make_pair(-it->second, it->first));
			}
			sort(ans.begin(), ans.end());
			cout << "<top "<<p<<">"<<endl;
			for(int i=0;i<ans.size();i++) cout<<ans[i].second<<" "<<-ans[i].first<<endl;
			cout<<"</top>"<<endl;
		}
	}
	return 0;
}
