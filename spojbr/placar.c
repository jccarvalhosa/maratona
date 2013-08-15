#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define INF 1000000

int min(int a, int b) { return a < b ? a : b;}
int max(int a, int b) { return a > b ? a : b;}

struct Time{
	int num;
	int erros;
	int tempo;
	int pen;
} t[100];

int compare(const void * a, const void * b)
{
	if(((struct Time *) a)->num == ((struct Time *) b)->num) return ((struct Time *) a)->pen - ((struct Time *) b)->pen;
	return ((struct Time *) a)->num - ((struct Time *) b)->num;
}

int main()
{
	int n, p, i, j, len, sep, a, s;
	int tnum, ttempo, terros, kmin, kmax, dtempo, derros;
	char frase[10];
	while(scanf("%d%d", &n, &p) && n)
	{
		for(i=0;i<n;i++)
		{
			tnum = terros = ttempo = 0;
			for(j=0;j<p;j++)
			{
				getchar();
				scanf("%s", frase);
				len	= strlen(frase);
				sep=0;
				while(frase[sep] != '/') sep++;
				if(frase[sep+1] != '-')
				{
					if(sep == 1) a = frase[0] - '0';
					else if(sep == 2) a = (frase[0] - '0') * 10 + frase[1] - '0';
					else a = 100;
					if(len - sep == 2) s = frase[sep+1] - '0';
					else if(len - sep == 3) s = (frase[sep+1] - '0') * 10 + frase[sep+2] - '0';
					else if(len - sep == 4) s = (frase[sep+1] - '0') * 100 + (frase[sep+2] - '0') * 10 + frase[sep+3] - '0';
					if(a != 0)
					{
						tnum++;
						terros += (a - 1);
						ttempo += s;
					}
				}
			}
			t[i].num = tnum;
			t[i].erros = terros;
			t[i].tempo = ttempo;
			t[i].pen = ttempo + 20 * terros;
		}
		qsort(t, n, sizeof(struct Time), compare);
		kmax = INF;
		kmin = 1;
		for(i=1;i<n;i++) if(t[i].num == t[i-1].num && t[i].erros != t[i-1].erros)
		{
			derros = t[i].erros - t[i-1].erros;
			dtempo = t[i].tempo - t[i-1].tempo;
			if(t[i].pen == t[i-1].pen)
			{
				kmin = kmax = 20;
				break;
			}
			if(dtempo > 0 && derros < 0) kmax = min(kmax, (1 - dtempo) / derros);
			if(dtempo < 0 && derros > 0) kmin = max(kmin, ceil((1 - dtempo) / (float)derros));
		}
		if(kmax == INF) printf("%d *\n", kmin);
		else printf("%d %d\n", kmin, kmax);
	}
	return 0;
}
