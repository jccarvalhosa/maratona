#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int v[3];
		cin>>v[0]>>v[1]>>v[2];
		sort(v, v+3);
		if(v[2] - v[0] >= 2) cout << 0 << endl;
		else if(v[0]==0) {
			if(v[1]==0) cout << 1 << endl;
			else cout << 2 << endl;
		}
		else if(v[0] == v[1] && v[1] == v[2]-1) cout << 2 << endl;
		else if(v[0] == v[1]-1 && v[1] == v[2]) cout << 2 << endl;
		else cout << 6 << endl;
	}
	return 0;
}
