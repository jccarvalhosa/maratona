#include <stdio.h>
#include <string.h>

int vr[1002][1002], vl[1002][1002], minr[1002][1002], minl[1002][1002], nr[1002], nl[1002];
int aproxr[1002], aproxl[1002];

int min2(int a, int b) { return a < b ? a : b; }
int max2(int a, int b) { return a > b ? a : b; }
int min3(int a, int b, int c) { return min2(a, min2(b, c)); }

int main()
{
	int N, i, j, vmax, kmax, jmax;
	char senha[1002];
	while(1)
	{
		scanf("%s", senha);
		if(senha[0] == '*') break;
		N = strlen(senha);
		for(i=0;i<N;i++)
		{
			nr[i] = ('z' - senha[i] + 1) % 26;
			nl[i] = (senha[i] - 'a');
		}
		aproxr[0] = nr[0];
		aproxl[0] = nl[0];
		for(i=1;i<N;i++)
		{
			aproxr[i] = min2(aproxr[i-1] + max2(nr[i] - nr[i-1], 0), aproxl[i-1] + nr[i]);
			aproxl[i] = min2(aproxl[i-1] + max2(nl[i] - nl[i-1], 0), aproxr[i-1] + nl[i]);
		}
		vmax = min2(aproxr[N-1], aproxl[N-1]);
		kmax = vmax / 26;
		vr[0][0] = minr[0][0] = nr[0];
		vr[0][1] = minr[0][1] = nr[0] + 26;
		vr[0][2] = minr[0][2] = nr[0] + 52;
		vl[0][0] = minl[0][0] = nl[0];
		vl[0][1] = minl[0][1] = nl[0] + 26;
		vl[0][2] = minl[0][2] = nl[0] + 52;
		for(i=1;i<N;i++) 
		{
			vr[i][0] = min3(minl[i-1][0] + nr[i], 
							vr[i-1][0] + max2(nr[i] - nr[i-1], 0), 
							minr[i-1][1]
						);
			vl[i][0] = min3(minr[i-1][0] + nl[i], 
							vl[i-1][0] + max2(nl[i] - nl[i-1], 0), 
							minl[i-1][1]
						);
			jmax = min2(i, kmax);
			for(j=1;j<=jmax;j++)
			{
				vr[i][j] = min3(
							vr[i-1][j-1] + 26 - nr[i-1] + nr[i],
							vr[i-1][j] + max2(nr[i] - nr[i-1], 0), 
							minr[i-1][j+1]
							);
				vl[i][j] = min3(vl[i-1][j-1] + 26 - nl[i-1] + nl[i],
								vl[i-1][j] + max2(nl[i] - nl[i-1], 0), 
								minl[i-1][j+1]
							);
			}
			j--;
			vr[i][j+1] = minr[i][j+1] = vr[i][j] + 26;
			vr[i][j+2] = minr[i][j+2] = vr[i][j] + 52;
			vl[i][j+1] = minl[i][j+1] = vl[i][j] + 26;
			vl[i][j+2] = minl[i][j+2] = vl[i][j] + 52;
			while(j>=0)
			{
				minr[i][j] = min2(minr[i][j+1], vr[i][j]);
				minl[i][j] = min2(minl[i][j+1], vl[i][j]);
				j--;
			}
		}                                 
		printf("%d\n", min2(minr[N-1][0], minl[N-1][0]));
	}
	return 0;
}
