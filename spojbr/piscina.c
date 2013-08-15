#include <stdio.h>
#include <string.h>

int p, m, g;
int up, um, ug;

int converte(char* str)
{
	int i, val, n, ord;
	n = strlen(str);
	if(n != 3 && n != 4) return 0;
	val = (str[n-1] - '0') * 10 + (str[n-3] - '0') * 100;
	if(n == 4) val += (str[n-4] - '0') * 1000;
	return val;
}
	
int arruma(int x, int y)
{
	int x0;
	while(y >= 30)
	{
		x0 = x;
		while(x0 >= 30 && g)
		{
			ug++;
			g--;
			x0 -= 30;
		}
		while(x0 >= 15 && m >= 2)
		{
			um += 2;
			m -= 2;
			x0 -= 15;
		}
		while(x0 >= 5 && p >= 6)
		{
			up += 6;
			p -= 6;
			x0 -= 5;
		}
		if(x0 != 0) return 0;
		else y -= 30;
	}
	while(y >= 15)
	{
		x0 = x;
		while(x0 >= 15 && m)
		{
			um++;
			m--;
			x0 -= 15;
		}
		while(x0 >= 5 && p >= 3)
		{
			up += 3;
			p -= 3;
			x0 -= 5;
		}
		if(x0 != 0) return 0;
		else y -= 15;
	}
	while(y >= 5)
	{
		x0 = x;
		while(x0 >= 5 && p)
		{
			up++;
			p--;
			x0 -= 5;
		}
		if(x0 != 0) return 0;
		else y -= 5;
	}
	return 1;
}

int main()
{
	char strx[10], stry[10], strz[10];
	int x, y, z;
	while(scanf("%s %s %s", strx, stry, strz))
	{
		x = converte(strx);
		y = converte(stry);
		z = converte(strz);
		if(x == 0 || y == 0 || z == 0) break;
		scanf("%d%d%d", &p, &m, &g);
		up = um = ug = 0;
		if(!arruma(x, y)) printf("impossivel\n");
		else if(!arruma(x, z)) printf("impossivel\n");
		else if(!arruma(x, z)) printf("impossivel\n");
		else if(!arruma(y, z)) printf("impossivel\n");
		else if(!arruma(y, z)) printf("impossivel\n");
		else printf("%d %d %d\n", up, um, ug);
	}
	return 0;
}
