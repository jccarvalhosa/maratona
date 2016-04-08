#include <cstdio>

/*
    Solução para o problema Run Luke, run!
    Problema de: Jonathan Carvalhosa
	Solução de: Geraldo Avelino
	
	Esse é um problema bastante simples de ser resolvido. Dadas as suas restrições,
	n<=100 e m<=100, a solução é simplesmente marcar no grid todas as posições
	que Luke não pode passar e após esse passo verificar se é possível que Luke
	chegue até a célula destino (utilizando-se por exemplo uma busca em profundidade)
	Complexidade: O(n^3)
*/

int n, m;
char star[111][111], cant[111][111], vis[111][111];
int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};

bool in(int x, int y) { return (x>=0 && x<n && y>=0 && y<m); }

int dfs(int x, int y)
{
    int Dx, Dy, i;
    vis[x][y]=1;
    if(x==n-1 && y==m-1) return 1;
    for(i=0; i<4; i++)
    {
        Dx=x+dx[i];
        Dy=y+dy[i];
        if(in(Dx, Dy) && !vis[Dx][Dy] && !cant[Dx][Dy] && dfs(Dx, Dy)) return 1;
    }
    return 0;
}

int main()
{
	int i, j, k, l, x, y;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++) scanf("%s", star[i]);
	for(i=0; i<n; i++) for(j=0; j<m; j++)
	{
        if(star[i][j]=='#') cant[i][j]=1;
        if(star[i][j]=='D')
        {
            cant[i][j]=1;
            for(k=0; k<4; k++) for(x=i+dx[k], y=j+dy[k]; in(x, y) && star[x][y]!='#'; x+=dx[k], y+=dy[k]) cant[x][y]=1;
        }
    }
    printf("%s", dfs(0, 0) ? "Run Luke, run" : "May the force be with you");
	return 0;
}
