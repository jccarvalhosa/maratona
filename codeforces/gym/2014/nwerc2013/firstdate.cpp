#include <bits/stdc++.h>
using namespace std;

int days[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	int y, m, d, i;
	while(scanf("%d-%d-%d", &y, &m, &d)!=EOF)
	{
		int leap=11, f=0;
		for(i=1582; i<y; i++) if(i%100==0 && i%400!=0) leap++;
		if(y%100==0 && y%400!=0)
		{
			if(m>2) leap++;
			if(m == 2 && d == 29) leap++;
		}
		while(leap)
		{
			if(((y%4==0 && y%100!=0) || y%400==0) && m==2 && d==28) d++;
			else
			{
				d++;
				if(d>days[m-1])
				{
					d=1;
					m++;
					if(m==13)
					{
						m=1;
						y++;
					}
				}
			}
			leap--;
		}
		printf("%d-%.2d-%.2d\n", y, m, d);
	}
	return 0;
}
