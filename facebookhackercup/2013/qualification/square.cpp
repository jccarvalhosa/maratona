#include <iostream>
#include <algorithm>
using namespace std;
		
int n;
string s[222];

int valid() {
	int x=222, y=222, X=-1, Y=-1, sum=0;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(s[i][j] == '#') {
		x = min(x, i);
		y = min(y, j);
		X = max(X, i);
		Y = max(Y, j);
		sum++;
	}
	if(X-x != Y-y) return 0;
	return sum == (X-x+1)*(Y-y+1);
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n;
		for(int i=0;i<n;i++) cin>>s[i];
		cout<<"Case #"<<t<<": "<<(valid() ? "YES" : "NO")<<endl;
	}
	return 0;
}
