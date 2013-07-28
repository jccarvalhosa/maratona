#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, x, y;
string s;

void read() {
	for(int i=0;i<=n;i++) {
		int v1=0, v2=0;
		for(int j=0;j<n;j++) {
			int k=0;
			if(s[i+j]=='B') k=1;
			v1 += k*(1<<j);
			v2 += (1-k)*(1<<j);
		}
		x = min(x, min(v1, v2));
		y = max(y, max(v1, v2));
	}
}

int main() {
	while(1) {
		cin>>s;
		if(s=="END") break;
		n=s.size();
		s += s;
		x = 1<<30;
		y = 0;
		read();
		reverse(s.begin(), s.end());
		read();
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
