#include <stdio.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int N, atual, i, delta;
	int vis[300], pos[300];
	string carta;
	map<int, string> nome;
	scanf("%d", &N);
	atual = -1;
	for(i=0;i<N;i++) vis[i] = 0;
	i = N;
	while(i--)
	{
		cin >> carta;
		nome[i] = carta;
		delta = 0;
		while(delta != carta.size())
		{
			atual = (atual + 1) % N;
			if(!vis[atual]) delta++;
		}
		pos[atual] = i;
		vis[atual] = 1;
	}
	for(i=0;i<N;i++) cout << nome[pos[i]] << endl;
	return 0;
}
