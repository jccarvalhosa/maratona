#include <iostream>
#include <string>
using namespace std;

int main() {
	int t, sx, sy, ex, ey, cs=0, ce=0, cn=0, cw=0, i;
	string s;
	cin>>t>>sx>>sy>>ex>>ey>>s;
	if(ex>sx) ce = ex-sx;
	else cw = sx-ex;
	if(ey>sy) cn = ey-sy;
	else cs = sy-ey;
	if(ex==sx && ey==sy) cout << 0 << endl;
	else {
		for(i=0;i<t;i++) {
			if(s[i] == 'N' && cn) cn--;
			if(s[i] == 'S' && cs) cs--;
			if(s[i] == 'W' && cw) cw--;
			if(s[i] == 'E' && ce) ce--;
			if(!cs && !cn && !cw && !ce) break;
		}
		if(i == t) cout << -1 << endl;
		else cout << i+1 << endl;
	}
	return 0;
}
