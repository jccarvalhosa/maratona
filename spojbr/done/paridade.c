#include <stdio.h>

int main()
{
	unsigned int i, j;
	int a, uns;

	while(scanf("%d", &i) && i)
	{
		uns = 0;
		printf("The parity of ");
		for (j = 2147483648; j > 0; j >>= 1)
		{
			if (i & j)
			{
				printf("1");
				uns++;
			}
			else
				if (uns)
					printf("0");
		}
		printf(" is %d (mod 2).\n", uns);
	}
	return 0;
}

