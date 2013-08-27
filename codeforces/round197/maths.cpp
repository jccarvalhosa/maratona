#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<char> v;

int main() {
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++) if(isdigit(s[i])) v.push_back(s[i]);
	sort(v.begin(), v.end());
	if(v.size() >= 1) cout<<v[0];
	for(int i=1;i<v.size();i++) cout<<"+"<<v[i];
	cout<<endl;
	return 0;
}
