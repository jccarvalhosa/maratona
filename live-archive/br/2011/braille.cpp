#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <iostream>
using namespace std;

int main() {
	map<string, char> B;
	map<char, string> S;
	B["*....."] = '1';
	B["*.*..."] = '2';
	B["**...."] = '3';
	B["**.*.."] = '4';
	B["*..*.."] = '5';
	B["***..."] = '6';
	B["****.."] = '7';
	B["*.**.."] = '8';
	B[".**..."] = '9';
	B[".***.."] = '0';
	S['1'] = "*.....";
	S['2'] = "*.*...";
	S['3'] = "**....";
	S['4'] = "**.*..";
	S['5'] = "*..*..";
	S['6'] = "***...";
	S['7'] = "****..";
	S['8'] = "*.**..";
	S['9'] = ".**...";
	S['0'] = ".***..";
	int N, i, j;
	char c, s[100];
	string b[100];
	while(scanf("%d", &N) && N) {
		scanf(" %c ", &c);
		if(c == 'S') {
			for(i=0;i<N;i++) scanf("%c", &s[i]);
			for(i=0;i<3;i++) {
				for(j=0;j<N;j++) {
					if(j) printf(" ");
					cout << S[s[j]].substr(2*i, 2);
				}
				printf("\n");
			}
		}
		if(c == 'B') {
			for(i=0;i<N;i++) b[i] = "";
			for(i=0;i<3;i++) for(j=0;j<N;j++) {
				string aux;
				cin >> aux;
				b[j] += aux;
			}
			for(i=0;i<N;i++) printf("%c", B[b[i]]);
			printf("\n");
		}
	}
	return 0;
}
