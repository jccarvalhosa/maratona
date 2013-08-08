#include <stdio.h>

int R, C;
char cine[500][500];
int vr[300][300], vc[300][300], vp[300][300];

int min(int a, int b) { return a < b ? a : b; }

int vago(char c)
{
	if(c == '.') return 1;
	else return 0;
}

int count(int ri, int ci, int rf, int cf)
{
	if(ri == 0 && ci == 0) return vp[rf][cf];
	if(ri == 0) return vp[rf][cf] - vp[rf][ci-1];
	if(ci == 0) return vp[rf][cf] - vp[ri-1][cf];
	return vp[rf][cf] - vp[rf][ci-1] - vp[ri-1][cf] + vp[ri-1][ci-1];
}

int main()
{
	int K, i, j, ini, fim, area;
	while(scanf("%d%d%d", &R, &C, &K) && R)
	{
		area = R * C;
		for(i=0;i<R;i++) scanf("%s", cine[i]);
		for(i=0;i<R;i++)
		{
			vr[i][0] = vago(cine[i][0]);
			for(j=1;j<C;j++) vr[i][j] = vr[i][j-1] + vago(cine[i][j]);
		}
		for(j=0;j<C;j++)
		{
			vc[j][0] = vago(cine[0][j]);
			for(i=1;i<R;i++) vc[j][i] = vc[j][i-1] + vago(cine[i][j]);
		}
		for(j=0;j<C;j++) vp[0][j] = vr[0][j];
		for(i=1;i<R;i++) for(j=0;j<C;j++) vp[i][j] = vp[i-1][j] + vr[i][j];
		for(i=0;i<R;i++)
		{
			if(vp[i][C-1] < K) continue;
			if(area == K) break;
			for(j=0;j<=i;j++)
			{
				if(count(j, 0, i, C-1) < K) continue;
				ini = fim = 0;
				while(fim != C)
				{
					if(count(j, ini, i, fim) >= K)
					{
						area = min(area, (i-j+1)*(fim-ini+1));
						ini++;
					}
					else fim++;
				}
			}
		}
		printf("%d\n", area);
	}
	return 0;
}
