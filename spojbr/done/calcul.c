#include <stdio.h>
#include <string.h>

int main()
{
	int N, n;
	int i, cont[10], resp;
	char c;
	memset(cont, 0, sizeof(cont));
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d", &n);
		scanf(" %c ", &c);
		if(c == '*') cont[n]++;
		if(c == '/') cont[n]--;
	}
	cont[2] += 2 * cont[4] + cont[6] + 3 * cont[8];
	cont[3] += cont[6] + 2 * cont[9];
	resp = 1;
	while(cont[2]--) resp *= 2;
	while(cont[3]--) resp *= 3;
	while(cont[5]--) resp *= 5;
	while(cont[7]--) resp *= 7;
	printf("%d\n", resp);
	return 0;
}
