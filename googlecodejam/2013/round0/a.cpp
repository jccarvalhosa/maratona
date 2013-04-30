#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s[4];

int main() {
	int T, t, i, j, x, o, c;
	cin>>T;
	for(t=1;t<=T;t++) {
		for(i=0;i<4;i++) cin>>s[i];
		x=o=0;
		c=1;
		for(i=0;i<4;i++) for(j=0;j<4;j++) if(s[i][j] == '.') c=0;
		for(i=0;i<4;i++) {
			for(j=0;j<4;j++) if(s[i][j] != 'X' && s[i][j] != 'T') break;
			if(j==4) x=1;
			for(j=0;j<4;j++) if(s[j][i] != 'X' && s[j][i] != 'T') break;
			if(j==4) x=1;

			for(j=0;j<4;j++) if(s[i][j] != 'O' && s[i][j] != 'T') break;
			if(j==4) o=1;
			for(j=0;j<4;j++) if(s[j][i] != 'O' && s[j][i] != 'T') break;
			if(j==4) o=1;
		}
		for(i=0;i<4;i++) if(s[i][i] != 'X' && s[i][i] != 'T') break;
		if(i==4) x=1;
		for(i=0;i<4;i++) if(s[i][3-i] != 'X' && s[i][3-i] != 'T') break;
		if(i==4) x=1;

		for(i=0;i<4;i++) if(s[i][i] != 'O' && s[i][i] != 'T') break;
		if(i==4) o=1;
		for(i=0;i<4;i++) if(s[i][3-i] != 'O' && s[i][3-i] != 'T') break;
		if(i==4) o=1;
		printf("Case #%d: ", t);
		if(x) cout<<"X won"<<endl;
		else if(o) cout<<"O won"<<endl;
		else if(c) cout<<"Draw"<<endl;
		else cout<<"Game has not completed"<<endl;
	}
	return 0;
}
