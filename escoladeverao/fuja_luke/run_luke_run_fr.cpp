#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

/*
    Problema de: Jonathan Carvalhosa
    Solução de: Felipe Rasinhas
    Solução bem direta. Para cada ponto do grid verifica se ele pode ser atacado
    por algum droid e o marca como inválido. Depois verificar se há um caminho do
    início ao fim sem passar por paredes ou células inválidas. Para este passo é 
    usada uma busca em profundidade (dfs)
    Complexidade: o(N^3)
*/

int n, m;
string ds[111];
int vis[111][111];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int in(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < m); }

void is_valid(int r, int c)
{
    for(int i=0;i<4;i++)
    {
        int k = 1;
        while(1)
        {
            if(!in(r+k*dx[i],c+k*dy[i])) break;
            if(ds[r+k*dx[i]][c+k*dy[i]] == '#') break;
            if(ds[r+k*dx[i]][c+k*dy[i]] == 'D')
            {
                ds[r][c] = 'X';
                return;
            };
            k++;
        }
    }
}

int dfs(int r, int c)
{
    if(r == n-1 && c == m-1) return 1;
    vis[r][c] = 1;
    for(int i=0;i<4;i++)
    {
        int nr = r+dx[i], nc = c+dy[i];
        if(in(nr,nc) && ds[r][c] == '.' && !vis[nr][nc] && dfs(nr,nc)) return 1;
    }
    return 0;
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> ds[i];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(ds[i][j] == '.') is_valid(i,j);
    cout << (dfs(0,0) == 1 ? "Run Luke, run" : "May the force be with you") << endl; 
    return 0;
}
