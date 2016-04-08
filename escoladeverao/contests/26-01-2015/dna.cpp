#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int M=1e6+10;
char s[M];

int main() {
	int t;
	cin>>t;
	while(t--) {
		scanf("%s", s);
		int n = strlen(s);
		vector<int> pos;
		pos.push_back(-1);
		for(int i=0;i<n;i++) if(s[i] == 'C' || s[i] == 'T') pos.push_back(i);
		pos.push_back(n);
		if(pos.size() == 2) {
			cout << n << " " << 0 << endl;
			continue;
		}
		if(pos.size() == n+2) {
			cout << 0 << " " << n << endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<pos.size()-1;i++) ans = max(ans, pos[i+1]-pos[i-1]-2);
		int found=0;
		for(int i=1;i<pos.size()-1;i++) if(pos[i]+1==pos[i+1] && (pos[i+2] - pos[i-1] - 3) == 2*ans) {
			cout << 2*ans << " " << 2 << endl;
			found=1;
			break;
		}
		if(!found) cout << ans << " " << 1 << endl;
	}
	return 0;
}
