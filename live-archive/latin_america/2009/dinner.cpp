#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
using namespace std;

vector<pair<string, char> > v;

int main()
{
    char t[10], c;
    int N, i, cont, resp, ne, nx, ni;
    while(scanf("%d", &N) && N) {
        v.clear();
        ne = nx = ni = 0;
        for(i=0;i<N;i++) {
            scanf("%s %c ", t, &c);
            if(c == 'E') ne++;
            if(c == 'X') nx++;
            if(c == '?') ni++;
            v.pb(mp(t, c));
        }
        sort(all(v));
        cont = resp = 0;
        for(i=0;i<N;i++) {
            if(v[i].second == 'E') cont++;
            if(v[i].second == 'X') cont--;
            if(v[i].second == '?') {
                ni--;
                if(ne+1 <= nx + ni) cont++, ne++;
                else cont--, nx++;
            }
            if(resp < cont) resp = cont;
        }
        printf("%d\n", resp);
    }
    return 0;
}
