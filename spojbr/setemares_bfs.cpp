#include <stdio.h>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int N, M;
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, 1, 1, -1};

int delta(int a, int b) { 
    if(a == b) return 0;
    if(a > b) return -1;
    return 1;
}

int BFS(vs game) {
    int i, j, x, y, nx, ny, mx, my;
    queue<vs> q;
    set<vs> vis;
    vpii enem;
    pii mypos;
    q.push(game);
    vis.insert(game);
    while(!q.empty()) {
        game = q.front();
        q.pop();
        enem.clear();
        for(i=0;i<N;i++) for(j=0;j<M;j++) {
            if(game[i][j] == 'E') enem.push_back(make_pair(i, j));
            if(game[i][j] == 'S') mypos = make_pair(i, j);
        }
        if(enem.empty()) return 1;
        
        for(i=0;i<8;i++) {
            int nx = mypos.first + dx[i];
            int ny = mypos.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M || game[nx][ny] != '.') continue;
            vs newgame = game;
            newgame[nx][ny] = 'S';
            newgame[mypos.first][mypos.second] = '.';
            mx = nx; my = ny;
            for(j=0;j<enem.size();j++) newgame[enem[j].first][enem[j].second] = '.';
            for(j=0;j<enem.size();j++) {
                x = enem[j].first;
                y = enem[j].second;
                nx = x + delta(x, mx);
                ny = y + delta(y, my);
                if(nx == mx && ny == my) break;
                if(newgame[nx][ny] == '.') newgame[nx][ny] = 'E';
                else newgame[nx][ny] = '#';
            }
            if(j != enem.size()) continue;
            if(!vis.count(newgame)) {
                vis.insert(newgame);
                q.push(newgame);
            }
        }
    }
    return 0;
}

int main()
{
    int T, i;
    string line;
    vs game;
    N = 9; M = 8;
    scanf("%d", &T);
    while(T--) {
        game.clear();
        for(i=0;i<N;i++) {
            cin >> line;
            game.push_back(line);
        }
        if(BFS(game)) printf("I'm the king of the Seven Seas!\n");
        else printf("Oh no! I'm a dead man!\n");
    }
    return 0;
}

