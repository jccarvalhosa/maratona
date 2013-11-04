#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int left, i, n;
	ll ans=0;
	string s;
	ifstream in("energy.in");
	ofstream out("energy.out");
	in >> left >> s;
	int q[3]={0};
	for(i=0; i<s.size(); i++) {
		if(s[i]=='2') {
			if(left>=2) {
				left-=2;
				q[2]++;
			}
		}
		else {
			if(left>=1) {
				left--;
				q[1]++;
			}
			else if(q[2]) {
				q[2]--;
				q[1]++;
				left++;
			}
		}
		ans+=(q[1]+q[2]);
	}
	out << ans << endl;
	return 0;
}
