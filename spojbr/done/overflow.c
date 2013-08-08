#include <stdio.h>

int main()
{
	int N, A, B, P;
	char c;
	scanf("%d", &N);
	scanf("%d", &A);
	getchar();
	scanf("%c", &c);
	scanf("%d", &B);
	if(c == '+') P = A + B;
	if(c == '*') P = A * B;
	if(P <= N) printf("OK\n");
	else printf("OVERFLOW\n");
	return 0;
}
