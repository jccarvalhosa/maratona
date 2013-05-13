#include <stdio.h>
#include <string>
#include <iostream>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

char ophor(char c) {
	if(c == 'p') return 'q';
	if(c == 'q') return 'p';
	if(c == 's') return 'r';
	if(c == 'r') return 's';
}

char opver(char c) {
	if(c == 'p') return 's';
	if(c == 's') return 'p';
	if(c == 'q') return 'r';
	if(c == 'r') return 'q';
}

int main()
{
	int N, i;
	string s, aux;
	scanf("%d", &N);
	while(N--)
	{
		cin >> s;
		
		for(i=s.size()-1;i>=0;i--) if(s[i] == 's' || s[i] == 'r') break;
		if(i == -1) printf("<none> ");
		else {
			aux = s;
			for(; i < s.size();i++) {
				aux[i] = opver(aux[i]);
			}
			cout << aux << " ";
		}

		for(i=s.size()-1;i>=0;i--) if(s[i] == 'p' || s[i] == 'q') break;
		if(i == -1) printf("<none> ");
		else {
			aux = s;
			for(; i < s.size();i++) {
				aux[i] = opver(aux[i]);
			}
			cout << aux << " ";
		}

		for(i=s.size()-1;i>=0;i--) if(s[i] == 'q' || s[i] == 'r') break;
		if(i == -1) printf("<none> ");
		else {
			aux = s;
			for(; i < s.size();i++) {
				aux[i] = ophor(aux[i]);
			}
			cout << aux << " ";
		}

		for(i=s.size()-1;i>=0;i--) if(s[i] == 'p' || s[i] == 's') break;
		if(i == -1) printf("<none> ");
		else {
			aux = s;
			for(; i < s.size();i++) {
				aux[i] = ophor(aux[i]);
			}
			cout << aux << " ";
		}
		printf("\n");
	}
	return 0;
}
