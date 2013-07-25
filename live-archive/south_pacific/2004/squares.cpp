#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string rotate(string s, int i, int d) {
	int aux = s[i];
	if(d==0) {
		s[i] = s[i+3];
		s[i+3] = s[i+4];
		s[i+4] = s[i+1];
		s[i+1] = aux;
	}
	else {
		s[i] = s[i+1];
		s[i+1] = s[i+4];
		s[i+4] = s[i+3];
		s[i+3] = aux;
	}
	return s;
}

int check(string s) {
	int sum = s[0] + s[4] + s[8];
	if(sum != s[2] + s[4] + s[6]) return 0;
	for(int i=0;i<3;i++) if(sum != s[3*i] + s[3*i+1] + s[3*i+2]) return 0;
	for(int i=0;i<3;i++) if(sum != s[i] + s[i+3] + s[i+6]) return 0;
	return 1;
}

int fat[10];

int lex(string s) {
	int ret=0;
	for(int i=0;i<s.size();i++) {
		int k=0;
		for(int j=i+1;j<s.size();j++) if(s[j] < s[i]) k++;
		ret += fat[s.size()-i-1]*k;
	}
	return ret;
}

int vis[555555];
vector<string> magic;

void find_all() {
	queue<string> q;
	for(int i=0;i<magic.size();i++) {
		vis[lex(magic[i])]=1;
		q.push(magic[i]);
	}
	while(!q.empty()) {
		string v = q.front();
		int d = vis[lex(v)];
		q.pop();
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) {
			string u = rotate(v, 3*j+i, k);
			int x = lex(u);
			if(!vis[x]) {
				vis[x] = d+1;
				q.push(u);
			}
		}
	}
}

void precalc() {
	int pos[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	fat[0]=1;
	for(int i=1;i<10;i++) fat[i] = i*fat[i-1];
	do {
		string s;
		for(int i=0;i<9;i++) s += '0'+pos[i];
		if(check(s)) magic.push_back(s);
	} while(next_permutation(pos, pos+9));
	find_all();
}

int main() {
	string s;
	precalc();
	while(1) {
		cin>>s;
		if(s=="END") break;
		if(vis[lex(s)]) cout<<vis[lex(s)]-1<<" moves"<<endl;
		else cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}
