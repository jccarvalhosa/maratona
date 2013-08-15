#include <stdio.h>

int main()
{
	int N;
	int i, certo;
	long long int M, x, y, d;
	char c;

	scanf("%d%lld", &N, &M);
	x = 0;
	y = 0;
	certo = 1;
	for(i=0;i<N;i++)
	{
		scanf(" %c ", &c);
		scanf("%lld", &d);
		if(c == 'N') x += d;
		if(c == 'S') x -= d;
		if(c == 'L') y += d;
		if(c == 'O') y -= d;
		if(x*x + y*y > M*M) certo = 0;
	}
	if(certo) printf("0\n");
	else printf("1\n");

	return 0;
}
