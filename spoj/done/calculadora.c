#include <stdio.h>

int main()
{
	int i, n;
	char c;
	double resposta = 1.0, a;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%lf %c", &a, &c);
		if(c == '*') resposta *= a;
		if(c == '/') resposta /= a;
	}
	printf("%.0lf\n", resposta);
	return 0;
}

