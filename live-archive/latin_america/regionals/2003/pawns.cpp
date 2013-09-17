#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <utility>
#define INF 1e9

using namespace std;

set<string> vis;

int delta[] = {-25, -23, -14, -10, 10, 14, 23, 25};

string move(string tab) {
    for(int i=143;i>=0;i--) if(tab[i] == 'P') {
            tab[i] = '.';
            if(i/12+1 == 9) tab[i+12] = 'R';
            else tab[i+12] = 'P';
    }
    return tab;
}

int bfs(string tab) {
    queue<pair<string, int> > q;
    int i, steps, pawns, kings, pos, npos, aux;
    q.push(make_pair(tab, 0));
    while(!q.empty()) {
        tab = q.front().first;
        steps = q.front().second;
        q.pop();
        if(vis.count(tab)) continue;
        vis.insert(tab);
        pawns = kings = 0;
        pos = -1;
        for(i=0;i<144;i++) {
            if(tab[i] == 'P') pawns++;
            if(tab[i] == 'R') kings++;
            if(tab[i] == 'C') pos = i;
        }
        if(pos == -1) continue;
        if(!pawns && !kings) return steps;
        if(kings == 1) {
            for(i=0;i<8;i++) {
                npos = pos + delta[i];
                if(tab[npos] == 'R') {
                    tab[npos] = 'C';
                    tab[pos] = '.';
                    q.push(make_pair(move(tab), steps+1));
                    break;
                }
            }
        }
        else if(!kings) {
            for(i=0;i<8;i++) {
                npos = pos + delta[i];
                if(npos % 12 >= 2 && npos % 12 <= 9 && npos / 12 >= 2 && npos / 12 <= 9) {
                    aux = tab[npos];
                    tab[npos] = 'C';
                    tab[pos] = '.';
                    q.push(make_pair(move(tab), steps+1));
                    tab[pos] = 'C';
                    tab[npos] = aux;
                }
            }
        }
    }
    return INF;
}

int main()
{
    string tab;
    int P, i, pos, resp, x, y;
    while(scanf("%d", &P) && P)
    {
        vis.clear();
        tab = "";
        for(i=0;i<144;i++) tab += ".";
        for(i=0;i<P;i++) {
            scanf("%d", &pos); pos--;
            x = pos % 8 + 2;
            y = pos / 8 + 2;
            tab[y * 12 + x] = y == 9 ? 'R' : 'P';
        }
        scanf("%d", &pos); pos--;
        x = pos % 8 + 2;
        y = pos / 8 + 2;
        tab[y * 12 + x] = 'C';
        resp = bfs(tab);
        if(resp == INF) printf("impossible\n");
        else printf("%d\n", resp);
    }
    return 0;
}
