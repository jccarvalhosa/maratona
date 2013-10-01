#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
typedef pair<int, int> pii;

int mod(int a) { return a>0?a:-a; }

pii b[111111];
bool cmp(pii a, pii b) { return mod(a.first) + mod(a.second) < mod(b.first) + mod(b.second); }

int main() {
	int n, ans=0;
	cin>>n;
	stringstream ss;
	for(int i=0;i<n;i++) {
		int x, y;
		cin>>x>>y;
		b[i] = pii(x, y); 
	}
	sort(b, b+n, cmp);
	for(int i=0;i<n;i++) {
		int x = b[i].first;
		int y = b[i].second;
		if(x == 0) {
			ans += 4;
			if(y > 0) ss << 1 << " " << y << " U" << endl << 2 << endl << 1 << " " << y << " D" << endl << 3 << endl; 
			if(y < 0) ss << 1 << " " << -y << " D" << endl << 2 << endl << 1 << " " << -y << " U" << endl << 3 << endl; 
		}
		else if(y == 0) {
			ans += 4;
			if(x > 0) ss << 1 << " " << x << " R" << endl << 2 << endl << 1 << " " << x << " L" << endl << 3 << endl; 
			if(x < 0) ss << 1 << " " << -x << " L" << endl << 2 << endl << 1 << " " << -x << " R" << endl << 3 << endl; 
		}
		else {
			ans += 6;
			if(x > 0) ss << 1 << " " << x << " R" << endl;
			if(x < 0) ss << 1 << " " << -x << " L" << endl;
			if(y > 0) ss << 1 << " " << y << " U" << endl << 2 << endl << 1 << " " << y << " D" << endl; 
			if(y < 0) ss << 1 << " " << -y << " D" << endl << 2 << endl << 1 << " " << -y << " U" << endl; 
			if(x > 0) ss << 1 << " " << x << " L" << endl << 3 << endl;
			if(x < 0) ss << 1 << " " << -x << " R" << endl << 3 << endl;
		}
	}
	cout<<ans<<endl<<ss.str();
	return 0;
}
