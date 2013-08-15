#include <stdio.h>
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main()
{
	int i, j, n, m, volta, soma;
	priority_queue<pair<int, int> > corredores;
	scanf("%d%d", &n, &m);
	while(!corredores.empty()) corredores.pop();
	for(i=1;i<=n;i++)
	{
		soma = 0;
		for(j=1;j<=m;j++)
		{
			scanf("%d", &volta);
			soma += volta;
		}
		corredores.push(make_pair(-soma, i));
	}
	for(i=1;i<=3;i++)
	{
		printf("%d\n", corredores.top().second);
		corredores.pop();
	}
	return 0;
}
