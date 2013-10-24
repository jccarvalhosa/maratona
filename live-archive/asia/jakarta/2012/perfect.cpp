#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

string s[1111];

bool check(int a, int b) {
	string sum = s[a] + s[b];
	for(int i=0;i<sum.size()/2;i++) if(sum[i] != sum[sum.size()-1-i]) return 0;
	return 1;
}

int main() {
	int T, n, ans;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cout << "Case #" << t << ": ";
		cin >> n;
		ans = 0;
		for(int i=0;i<n;i++) cin>>s[i];
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				if(check(i,j)) ans++;
				if(check(j,i)) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
