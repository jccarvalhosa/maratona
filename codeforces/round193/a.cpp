#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main() {
	int n;
	string s;
	cin>>n>>s;
	int v=0;
	for(int i=3;i<s.size();i++) {
		if(i%n==0) {
			if(s[i-1] == s[i-2] && s[i-2] == s[i-3]) v++;
		}
	}
	cout<<v<<endl;
	return 0;
}
