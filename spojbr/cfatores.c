#include <stdio.h>
#define MAX 1001

int main()
{
	int primos[MAX], n, i, j, num, numero;
	for(i=0;i<MAX;i++) primos[i] = i % 2;
	primos[1]=0;
	primos[2]=1; 
	for(i=3;i<MAX;i+=2) if(primos[i] && i < 1000) for(j=i*i;j<MAX;j+=i) primos[j] = 0;
	while(scanf("%d", &num) && num)
	{
		numero = num;
		i=2;
		n=0;
		while(i*i < numero)
		{
			if((numero % i == 0) && primos[i])
			{
				numero /= i;
				n++;
				while(numero % i == 0) numero /= i;
			}
			i++;
		}
		if(numero > 1000 || primos[numero]) n++;
		printf( "%d : %d\n", num,  n);
	}	
	return 0;
}
