#include <stdio.h>
#include <string.h>
#include <utility>
#include <algorithm>
#include <cmath>
#define INF 1000000

using namespace std;

int B, T, botao[1000];
double pd[1000][15];

pair<int, int> desmembra(char c)
{
	int dif;
	if(c == ' ') return make_pair(11, 1);
	dif = c - 'a';
	if(dif < 18) return make_pair(2 + dif / 3, 1 + dif % 3);
	else if(dif == 18) return make_pair(7, 4);
	else if(dif < 25) return make_pair(2 + (dif-1) / 3, 1 + (dif-1) % 3);
	else if(dif == 25) return make_pair(9, 4);
}

int computa(pair<int, int> novo, int antigo)
{
	if(novo.first == antigo)
	{
		botao[B++] = 12;
		T++;
	}
	botao[B++] = novo.first;
	T += novo.second;
	return novo.first;
}

double tempo(int a, int b)
{
	return sqrt(((a-1) / 3 - (b-1) / 3) * ((a-1) / 3 - (b-1) / 3) + ((a-1) % 3 - (b-1) % 3) * ((a-1) % 3 - (b-1) % 3));
}

int main()
{
	int N, i, j, pos;
	double soma;
	pair<int, int> novo;
	char msg[200];
	while(scanf("%[^\n]", msg) != EOF)
	{
		getchar();
		N = strlen(msg);
		B = T = 0;
		pos = 0;
		for(i=0;i<N;i++)
		{
			novo = desmembra(msg[i]);
			pos = computa(novo, pos);
		}
		for(i=0;i<B;i++) for(j=2;j<=12;j++) pd[i][j] = INF;
		pd[0][4] = tempo(6, botao[0]);
		pd[0][6] = tempo(4, botao[0]);
		for(i=1;i<B;i++) for(j=2;j<=12;j++)
		{
			pd[i][j] = min(pd[i][j], tempo(botao[i-1], botao[i]) + pd[i-1][j]);
			pd[i][botao[i-1]] = min(pd[i][botao[i-1]], tempo(j, botao[i]) + pd[i-1][j]);
		}
		soma = pd[B-1][2];
		for(j=3;j<=12;j++) soma = min(soma, pd[B-1][j]);
		printf("%.2lf\n", soma / 30.0 + 0.2 * T);
	}
	return 0;
}
