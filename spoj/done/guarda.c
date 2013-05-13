#include <stdio.h>

int main()
{
	int D, Vf, Vg;
	while(scanf("%d%d%d", &D, &Vf, &Vg) != EOF)
	{
		if(Vf * Vf * (144 + D * D) <= 144 * Vg * Vg) printf("S\n");
		else printf("N\n");
	}
	return 0;
}
