#include <stdio.h>
#include <string.h>

char a[1000010], b[1000010];

int main() {
	int A, B, flaga, flagb, i;
	scanf("%s %s", a, b);
	A = strlen(a);
	B = strlen(b);
	if(A != B) printf("NO");
	else {
		for(i=0;i<A && a[i]=='0';i++) ;
		flaga = (i==A);
		for(i=0;i<B && b[i]=='0';i++) ;
		flagb = (i==B);
		if(flaga == flagb) printf("YES");
		else printf("NO");
	}
	return 0;
}
