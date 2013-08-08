#include <stdio.h>
	
int count[100000], first[100000], last[1000000], next[100000], set[100000];

void join(int a, int b)
{
	int i, maior, menor;
	if(count[set[a]] < count[set[b]]) menor = set[a], maior = set[b];
	else menor = set[b],	maior = set[a];
	count[maior] += count[menor];
	next[last[maior]] = first[menor];
	last[maior] = last[menor];
	for(i=first[menor]; i!=-1; i=next[i]) set[i] = maior;
}

int main()
{
	int N, K, i, a, b;
	char c;

	scanf("%d%d", &N, &K);
	for(i=0;i<N;i++)
	{
		count[i] = 1;
		next[i] = -1;
		first[i] = last[i] = set[i] = i;
	}
	while(K--)
	{
		scanf(" %c %d%d", &c, &a, &b);
		a--; b--;
		if(c == 'C') printf("%c\n", set[a] == set[b] ? 'S' : 'N');
		if(c == 'F' && set[a] != set[b]) join(a, b);
	}
	return 0;

}
