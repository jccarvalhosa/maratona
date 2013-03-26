#include <iostream>
#include <string>
using namespace std;

string s[4];

int main() {
	int i, j, flag=0, cont;
	for(i=0;i<4;i++) cin>>s[i];
	for(i=0;i<3;i++) for(j=0;j<3;j++) {
		cont=0;
		if(s[i][j] == '#') cont++;
		if(s[i][j+1] == '#') cont++;
		if(s[i+1][j] == '#') cont++;
		if(s[i+1][j+1] == '#') cont++;
		if(cont!=2) flag=1;
	}
	cout<<(flag?"YES":"NO")<<endl;
	return 0;
}
