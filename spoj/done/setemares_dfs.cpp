#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef vector<string> vs;

set<vs> vis;

int N, M;
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, 1, 1, -1};

int delta(int a, int b) { 
    if(a == b) return 0;
    if(a > b) return -1;
    return 1;
}

int dfs(vs game) 
{
    int i, j, E, x, y, nx, ny;
    vpii enem;
    pii mypos;
    vis.insert(game);
    for(i=0;i<N;i++) for(j=0;j<M;j++) {
        if(game[i][j] == 'E') enem.push_back(make_pair(i, j));
        if(game[i][j] == 'S') mypos = make_pair(i, j);
    }
    E = enem.size();
    if(!E) return 1;
    for(i=0;i<8;i++) {
        int mx = mypos.first + dx[i];
        int my = mypos.second + dy[i];
        if(mx < 0 || my < 0 || mx >= N || my >= M || game[mx][my] != '.') continue;
        vs newgame = game;
        newgame[mx][my] = 'S';
        newgame[mypos.first][mypos.second] = '.';
        for(j=0;j<E;j++) newgame[enem[j].first][enem[j].second] = '.';
        for(j=0;j<E;j++) {
            x = enem[j].first;
            y = enem[j].second;
            nx = x + delta(x, mx);
            ny = y + delta(y, my);
            if(nx == mx && ny == my) break;
            if(newgame[nx][ny] == '.') newgame[nx][ny] = 'E';
            else newgame[nx][ny] = '#';
        }
        if(j != E) continue;
        if(!vis.count(newgame) && dfs(newgame)) return 1; 
    }
    return 0;
}

int main()
{
    int T, i, j;
    vs G;
    string s;
    pii mypos;
    N = 9; M = 8;
    scanf("%d", &T);
    while(T--)
    {
        G.clear();
        vis.clear();
        for(i=0;i<N;i++)
        {
            cin >> s;
            G.push_back(s);
        }
        if(dfs(G)) printf("I'm the king of the Seven Seas!\n");
        else printf("Oh no! I'm a dead man!\n");
    }
    return 0;
}
