#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <string>
typedef unsigned long long ull;
typedef long long ll;

char s[111];
int n;

int go(int pos) {
	if(pos==n) return 1;
	int i;
	for(i=0;i<pos;i++) if(s[i] == s[pos]) break;
	if(i==pos && go(pos+1)) return 1;
	for(char c=s[pos]+1;c!='G';c++) {
		if(c==('9'+1)) c='A';
		s[pos]=c;
		for(i=0;i<pos;i++) if(s[i] == c) break;
		if(i != pos) continue;
		for(int j=pos+1;j<n;j++) s[j]='0';
		if(go(pos+1)) return 1;
	}
	return 0;
}

int main() {
	ull x;
	while(scanf("%llx", &x) != EOF) {
		x++;
		sprintf(s, "%llx", x);
		n = strlen(s);
		for(int i=0;i<n;i++) s[i] = toupper(s[i]);
		if(go(0)) printf("%s\n", s);
		else {
			memset(s, '0', sizeof(s));
			s[0]='1';
			n++;
			go(0);
			s[n]='\0';
			printf("%s\n", s);
		}
	}
	return 0;
}
