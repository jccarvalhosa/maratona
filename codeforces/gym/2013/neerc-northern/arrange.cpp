#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	ifstream in("arrange.in");
	ofstream out("arrange.out");
	int n;
	while(in>>n && !in.eof()) {
		int v[27]={0};
		for(int i=0;i<n;i++) {
			string s; in>>s;
			char c = s[0];
			if(c >= 'a' && c <='z') v[c-'a']=1;
			if(c >= 'A' && c <='Z') v[c-'A']=1;
		}
		int i;
		for(i=0;i<26;i++) if(!v[i]) break;
		out << i << endl;
	}
	return 0;
}
