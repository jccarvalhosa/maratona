#include <stdio.h>
#define MAX 1025

int main()
{
	int primos[MAX], n, i, j, num, aux, exp[4], teste=1;
	for(i=0;i<MAX;i++) primos[i] = i % 2;
	primos[1]=0;
	primos[2]=1;
	for(i=3;i<MAX;i+=2) if(primos[i] && i < 1024) for(j=i*i;j<MAX;j+=i) primos[j] = 0;
	while(scanf("%d", &num) != EOF)
	{
		n=0;
		for(i=2;i<1025 && num > 1 && n < 4;i++) if(primos[i])
		{
			aux = 0;
			while(num % i == 0){
				num /= i;
				aux++;
			}
			if(aux > 0) exp[n++] = aux;
		}
		if(num > 1024 || primos[num]) exp[n++] = 1;
		printf("Instancia %d\n", teste++);
		if(n > 3) printf("sim\n\n");
		else if(n == 3)
		{
			if(exp[0] + exp[1] + exp[2] > 3) printf("sim\n\n");
			else printf("nao\n\n");
		}
		else if(n == 2)
		{
			if(exp[0] > 1 && exp[1] > 1) printf("sim\n\n");
			else if(exp[0] > 4 || exp[1] > 4) printf("sim\n\n");
			else printf("nao\n\n");
		}
		else if(n == 1 && exp[0] > 7) printf("sim\n\n");
		else printf("nao\n\n");
	}	
	return 0;
}



