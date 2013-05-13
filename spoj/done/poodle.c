#include <stdio.h>

int main()
{
	int N, P;
	int numero;
	while(scanf("%d%d", &N, &P) && N)
	{
		numero = N / P;
		if(N % P > 0) numero++;
		if(numero <= 6) numero = 0;
		else if(numero >= 20) numero = 14;
		else numero -= 6;
		
		printf("Poo");
		while(numero--) printf("o");
		printf("dle\n");
	}
	return 0;
}
