#include <bits/stdc++.h>

using namespace std;

set<string> vis;
char words[100000];

int main() {
	int T;
	cin>>T;
	while(T--) {
		getchar();
		scanf("%[^\n]", words);
		char *p;
		p = strtok(words, " ");
		vector<string> v;
		while(p != NULL) {
			v.push_back(p);
			p = strtok(NULL, " ");
		}
		set<string> vis;
		while(1) {
			getchar();
			scanf("%[^\n]", words);
			if(!strcmp(words, "what does the fox say?")) {
				vector<string> ans;
				for(int i=0;i<v.size();i++) if(!vis.count(v[i])) ans.push_back(v[i]);
				cout<<ans[0];
				for(int i=1;i<ans.size();i++) cout<<" "<<ans[i];
				cout<<endl;
				break;
			}
			else {
				p = strtok(words, " ");
				while(1) {
					string s = p;
					p = strtok(NULL, " ");
					if(p == NULL) {
						vis.insert(s);
						break;
					}
				}
			}
		}
	}
	return 0;
}
