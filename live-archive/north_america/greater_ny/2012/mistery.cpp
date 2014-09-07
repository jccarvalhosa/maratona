#include <bits/stdc++.h>
using namespace std;

char s[1111111];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int T, cur=0, n;
		scanf("%d", &T);
		getchar();
		scanf("%[^\n]", s);
		getchar();
		scanf("%d", &n);
		printf("%d ", T);
		int sz=strlen(s);
		for(int i=0; i<n; i++) {
			int a;
			scanf("%d", &a);
			cur=(cur+a+sz)%sz;
			printf("%c", s[cur]);
		}
		printf("\n");
	}
	return 0;
}
