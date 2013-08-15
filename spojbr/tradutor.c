#include <stdio.h>
#include <string.h>

char N[200], S[200000];
int tamN, tamS;

int valido(int ini, int fim)
{
	int tam, i;
	if(S[ini] == '0') return 0;
	tam = fim - ini + 1;
	if(tam < tamN) return 1;
	if(tam > tamN) return 0;
	for(i=0;i<tam;i++)
	{
		if(N[i] < S[ini+i]) return 0;
		if(N[i] > S[ini+i]) return 1;
	}
	return 1;
}

int main()
{
	int i, j;
	int max[200000];
	scanf("%s", N);
	tamN = strlen(N);
	scanf("%s", S);
	tamS = strlen(S);
	max[tamS] = 1;
	for(i=tamS-1;i>=0;i--)
	{
		max[i] = 0;
		for(j=i;j<tamS;j++)
		{
			if(valido(i, j)) max[i] = (max[i] + max[j+1]) % 1000000007;
			else break;
		}
	}
	printf("%d\n", max[0]);
	return 0;
}
