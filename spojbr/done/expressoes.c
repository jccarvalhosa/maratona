#include <stdio.h>

int main()
{
	int T;
	char A[100002], pilha[100002];
	int i, n, ok;
	scanf("%d", &T);
	getchar();
	while(T--)
	{
		i = 0;
		n = -1;
		ok = 1;
		scanf("%s", A);
		while(1)
		{
			if(A[i] == '(' || A[i] == '[' || A[i] == '{') pilha[++n] = A[i]; 
			else if(A[i] == ')')
			{
				if(pilha[n] == '(') n--;
				else ok = 0;
			}
			else if(A[i] == ']')
			{
				if(pilha[n] == '[') n--;
				else ok = 0;
			}
			else if(A[i] == '}')
			{
				if(pilha[n] == '{') n--;
				else ok = 0;
			}
			else break;
			i++;
		}
		if(n >= 0) ok = 0;
		if(ok) printf("S\n");
		else printf("N\n");
	}
	return 0;
}
