#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> vis;

void go(string s, int p, int q, int r, int dep) {
	if(p%2==0 && q%2==0 && r%2==0) {
		vis.insert(s);
	}
	if(dep==12) return;
	if(p) {
		swap(s[0], s[1]);
		go(s, p-1, q, r, dep+1);
		swap(s[0], s[1]);
	}
	if(q) {
		swap(s[0], s[2]);
		go(s, p, q-1, r, dep+1);
		swap(s[2], s[0]);
	}
	if(r) {
		swap(s[1], s[2]);
		go(s, p, q, r-1, dep+1);
	}
}

int main() {
	int p, q, r;
	int a=0, b=0, c=0;
	string s;
	cin>>p>>q>>r;
	cin>>s;
	go("RGB", p, q, r, 0);
	if(vis.count(s)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
