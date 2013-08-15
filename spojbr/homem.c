#include <stdio.h>

typedef struct
{
	int h;
	int e;
	int r;
	int pending;
} interval;

interval M[1000000];

void get_children_values(int node)
{
	M[node].h = M[2*node].h + M[2*node+1].h;
	M[node].e = M[2*node].e + M[2*node+1].e;
	M[node].r = M[2*node].r + M[2*node+1].r;
}

void shift_values(int node)
{
	int auxh;	
	auxh=M[node].h;
	if(M[node].pending == 1)
	{
		M[node].h=M[node].r;
		M[node].r=M[node].e;
		M[node].e=auxh;
	}
	else
	{
		M[node].h=M[node].e;
		M[node].e=M[node].r;
		M[node].r=auxh;
	}
}

void fix_pending(int node, int b, int e)
{
	if(!M[node].pending) return;
	shift_values(node);
	if(b != e)
	{
		M[2*node].pending = (M[2*node].pending + M[node].pending) % 3;
		M[2*node+1].pending = (M[2*node+1].pending + M[node].pending) % 3;
	}
	M[node].pending = 0;
}

void propagate_pending_count(int node, int b, int e)
{
	if(!M[node].pending) return;
	M[2*node].pending = (M[2*node].pending + M[node].pending) % 3;
	M[2*node+1].pending = (M[2*node+1].pending + M[node].pending) % 3;
	M[node].pending = 0;
}

interval join(interval i1, interval i2)
{
	interval aux;
	aux.h=i1.h+i2.h;
	aux.e=i1.e+i2.e;
	aux.r=i1.r+i2.r;
	return aux;
}

interval query(int node, int b, int e, int i, int j)
{
	interval p1, p2;
	fix_pending(node, b, e);
	if(j<b || i>e)
	{
		p1.h = -1;
		return p1;
	}
	if(i<=b && j>=e) return M[node];
	else
	{
		p1=query(2*node, b, (b+e)/2, i, j);
		p2=query(2*node+1, (b+e)/2+1, e, i, j);
		if(p1.h==-1) return p2;
		if(p2.h==-1) return p1;
		return join(p1, p2);
	}
}

void update(int node, int b, int e, int i, int j)
{
	if(i<=b && j>=e)
	{
		M[node].pending = (M[node].pending + 1) % 3;
		fix_pending(node, b, e);
		return;
	}
	if(j<b || i>e) fix_pending(node, b, e);
	else
	{
		propagate_pending_count(node, b, e);
		update(2*node, b, (b+e)/2, i, j);
		update(2*node+1, (b+e)/2+1, e, i, j);
		get_children_values(node);
	}
}

interval initialize(int node, int b, int e)
{
	M[node].pending = 0;
	if(b == e) 
	{
		M[node].h = 1;
		M[node].e = M[node].r = 0;
	}
	else
	{
		initialize(2*node, b, (b+e)/2);
		initialize(2*node+1, (b+e)/2+1, e);
		get_children_values(node);
	}
}

int main()
{
	int N, M, a, b;
	char c;
	interval resp;
	while(scanf("%d %d", &N, &M) != EOF)
	{
		initialize(1, 1, N);
		while(M--)
		{
			scanf(" %c %d %d", &c, &a, &b);
			if(c == 'M') update(1, 1, N, a, b);
			else
			{
				resp=query(1, 1, N, a, b);
				printf("%d %d %d\n", resp.h, resp.e, resp.r);
			}
		}
		printf("\n");
	}
	return 0;	
}
