#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
#include <string>
using namespace std;

char clower(char c) { return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c; }
char cupper(char c) { return (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c; }

string lower(string s) {
	for(int i=0;i<s.size();i++) s[i] = clower(s[i]);
	return s;
}

int main() {
	int N, E, F, i, ini, fim;
	scanf("%d", &N);
	while(N--) {
		set<string> vis;
		string s, aux;
		scanf("%d%d", &E, &F);
		for(i=0;i<E;i++) {
			cin >> s;
			vis.insert(lower(s));
		}
		getchar();
		for(i=0;i<F;i++) {
			getline(cin, s);
			for(ini=fim=0;fim<s.size();fim++) if(s[fim] == ' ' || s[fim] == ':' || s[fim] == '-') {
				if(s[ini] != ' ' && s[ini] != ':' && s[ini] != '-') {
					aux = lower(s.substr(ini, fim-ini));
					if(vis.count(aux)) { 
						if(ini != 0) printf("%c", aux[0]); 
					}
					else printf("%c", cupper(aux[0]));
				}
				ini = fim+1;
			}
			if(s[ini] != ' ' && s[ini] != ':' && s[ini] != '-' && ini != s.size()) {
				aux = lower(s.substr(ini, s.size()-ini));
				if(vis.count(aux)) { if(ini != 0) printf("%c", aux[0]); }
				else printf("%c", cupper(aux[0]));
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
