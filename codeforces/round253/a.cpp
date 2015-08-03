#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> pii;

int colors[] = {'R', 'G', 'B', 'Y', 'W'};

int used[6][6];

int valid(int maskc, int maskt) {
	for(int c=0;c<5;c++) if(maskc & (1<<c)) {
		int nt=0;
		for(int t=0;t<5;t++) if(used[c][t] && (maskt & (1<<t)) == 0) nt++;
		if(nt > 1) return 0;
	}
	int cont[5] = {0};
	for(int c=0;c<5;c++) if((maskc & (1<<c)) == 0) {
		for(int t=0;t<5;t++) if(used[c][t]) {
			cont[t]++;
		}
	}
	for(int t=0;t<5;t++) if(cont[t] > 1) return 0;
	int nt=0;
	for(int t=0;t<5;t++) if(cont[t] && (maskt & (1<<t)) == 0) nt++;
	if(nt > 1) return 0;
	return 1;
}

int main() {
	int maskc, maskt;
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		int c, t;
		for(c=0;c<5;c++) if(colors[c] == s[0]) break;
		t = s[1]-'1';
		used[c][t] = 1;
	}
	int ans = 66;
	for(int maskc=0;maskc<32;maskc++) for(int maskt=0;maskt<32;maskt++) {
		if(valid(maskc, maskt)) ans = min(ans, __builtin_popcount(maskc) + __builtin_popcount(maskt));
	}
	cout << ans << endl;
	return 0;
}
