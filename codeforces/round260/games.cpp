#include <iostream>
#include <string>
#include <map>
using namespace std;

struct trie {
	map<char, trie> child;
	int win, lose, isroot;

	void add(string &s, int pos) { if(pos != s.size()) child[s[pos]].add(s, pos+1); }
	
	void calc() {
		if(child.empty()) {
			win = 1;
			lose = 0;
		}
		else {
			if(isroot) {
				win = 0;
				lose = 0;
			}
			else {
				win = 1;
				lose = 1;
			}
			for(map<char, trie>::iterator it = child.begin(); it != child.end(); it++) {
				trie t = (*it).second;
				t.calc();
				if(isroot) {
					if(t.win) win = 1;
					if(t.lose) lose = 1;
				}
				else {
					if(t.win) win = 0;
					if(t.lose) lose = 0;
				}
			}
		}
	}
};

trie root;

int main() {
	int n, k;
	root.isroot = 1;
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		root.add(s, 0);
	}
	root.calc();
	if(!root.win) cout << "Second" << endl;
	else if(root.lose) cout << "First" << endl;
	else if(k & 1) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}
