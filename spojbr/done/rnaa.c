#include <stdio.h>
#include <string.h>

int main()
{
	char R[302];
	char pilha[302];
	int n, soma, i;
	while(scanf("%s", R) != EOF)
	{
		n = -1;
		soma = 0;
		for(i=0;i<strlen(R);i++)
		{
			pilha[++n] = R[i];
			if(n > 0)
			{
				if((pilha[n] == 'B' && pilha[n-1] == 'S') || (pilha[n] == 'S' && pilha[n-1] == 'B') || (pilha[n] == 'C' && pilha[n-1] == 'F') || (pilha[n] == 'F' && pilha[n-1] == 'C'))
				{
					n -= 2;
					soma++;
				}
			}
		}
		printf("%d\n", soma);		
	}
	return 0;
}
