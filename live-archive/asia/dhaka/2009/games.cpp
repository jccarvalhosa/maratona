#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

string play(string s, int p) {
	int q[32];
	int vis[32];
	memset(vis, 0, sizeof(vis));
	int i=0, f=1;
	q[0]=p;
	vis[p]=1;
	while(i!=f) {
		p=q[i++];
		if(p%4!=0 && !vis[p-1] && s[p-1]==s[p]) {
			vis[p-1] = 1;
			q[f++] = p-1;
		}
		if(p%4!=3 && !vis[p+1] && s[p+1]==s[p]) {
			vis[p+1] = 1;
			q[f++] = p+1;
		}
		if(p>=4 && !vis[p-4] && s[p-4]==s[p]) {
			vis[p-4] = 1;
			q[f++] = p-4;
		}
		if(p<=11 && !vis[p+4] && s[p+4]==s[p]) {
			vis[p+4] = 1;
			q[f++] = p+4;
		}
	}
	for(i=0;i<f;i++) s[q[i]]=' ';
	for(int i=0;i<4;i++) {
		for(int j=3;j>=0;j--) if(s[i+4*j]==' ') {
			int x;
			for(x=j-1;x>=0;x--) if(s[i+4*x]!=' ') break;
			if(x>=0) swap(s[i+4*j], s[i+4*x]);
		}
	}
	return s;
}

map<string, int> vis;

int go(string s) {
	int i;
	for(i=0;i<16;i++) if(s[i]=='R' || s[i]=='B') break;
	if(i==16) return 0;
	if(vis.count(s)) return vis[s];
	int x=0;
	for(i=0;i<16;i++) if(s[i]!=' ') {
		string u = play(s, i);
		int y = go(u);
		if(y==0) x=1;
		else if(y>0) {
			if(x>0) continue;
			y = -y;
			x=min(x, y-1);
		}
		else {
			y = -y;
			if(x>0) x = min(x, y+1);
			else x = y+1;
		}
	}
	return vis[s]=x;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		string s="", aux;
		for(int i=0;i<4;i++) cin>>aux, s+=aux;
		int v=go(s);
		cout<<"Case "<<t<<": ";
		if(v>0) cout<<"win "<<v<<endl;
		if(v<0) cout<<"loss "<<-v<<endl;
	}
	return 0;
}
