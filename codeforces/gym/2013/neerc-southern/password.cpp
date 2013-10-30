#include <cstdio>
#include <cstring>

char s[5555];
int dp[5555][27];

int main() {
	int i, j, n, f=0, sz;
	char c;
	scanf("%d %s", &n, s);
	sz=strlen(s);
	for(int c=0;c<n;c++) dp[sz][c]=1;
	for(int i=sz-1;i>=0;i--) {
		if(s[i]=='=') { for(int c=0;c<n;c++) dp[i][c] = dp[i+1][c]; }
		if(s[i]=='>') {
			int ini;
			for(ini=0;ini<n;ini++) if(dp[i+1][ini]) break;
			for(int c=ini+1;c<n;c++) dp[i][c]=1;
		}
		if(s[i]=='<') {
			int ini;
			for(ini=n-1;ini>=0;ini--) if(dp[i+1][ini]) break;
			for(int c=ini-1;c>=0;c--) dp[i][c]=1;
		}
	}
	int pos, valid=0;
	for(pos=0;pos<n;pos++) if(dp[0][pos]) valid=1;
	if(!valid) printf("-1");
	else {
		for(pos=0;pos<n;pos++) if(dp[0][pos]) break;
		printf("%c", 'a'+pos);
		for(int i=1;i<sz;i++) {
			if(s[i-1]=='<') {
				for(int j=pos+1;j<n;j++) {
					if(dp[i][j]) {
						pos=j;
						break;
					}
				}
			}
			if(s[i-1]=='>') {
				for(int j=pos-1;j>=0;j--) {
					if(dp[i][j]) {
						pos=j;
						break;
					}
				}
			}
			printf("%c", 'a'+pos);
		}
		if(s[sz-1]=='<') printf("%c\n", 'a'+pos+1);
		if(s[sz-1]=='>') printf("%c\n", 'a'+pos-1);
		if(s[sz-1]=='=') printf("%c\n", 'a'+pos);
	}
	return 0;
}
