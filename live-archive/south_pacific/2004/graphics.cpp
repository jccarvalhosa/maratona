#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char ov(char c) {
	if(c=='1') return '4';
	if(c=='4') return '1';
	if(c=='2') return '3';
	if(c=='3') return '2';
}

char oh(char c) {
	if(c=='1') return '2';
	if(c=='2') return '1';
	if(c=='3') return '4';
	if(c=='4') return '3';
}

string next(string pos, char c) {
	int i, n=pos.size();
	if(c=='U') {
		for(i=n-1;i>=0;i--) if(pos[i]=='4' || pos[i]=='3') break;
		if(i==-1) return "OUT";
		for(;i<n;i++) pos[i] = ov(pos[i]);
	}
	if(c=='D') {
		for(i=n-1;i>=0;i--) if(pos[i]=='1' || pos[i]=='2') break;
		if(i==-1) return "OUT";
		for(;i<n;i++) pos[i] = ov(pos[i]);
	}
	if(c=='L') {
		for(i=n-1;i>=0;i--) if(pos[i]=='2' || pos[i]=='3') break;
		if(i==-1) return "OUT";
		for(;i<n;i++) pos[i] = oh(pos[i]);
	}
	if(c=='R') {
		for(i=n-1;i>=0;i--) if(pos[i]=='1' || pos[i]=='4') break;
		if(i==-1) return "OUT";
		for(;i<n;i++) pos[i] = oh(pos[i]);
	}
	return pos;
}

int main() {
	string pos, mov;
	while(1) {
		cin>>pos;
		if(pos=="END") break;
		cin>>mov;
		for(int i=0;i<mov.size();i++) {
			pos = next(pos, mov[i]);
			if(pos == "OUT") break;
		}
		cout<<pos<<endl;
	}
	return 0;
}
