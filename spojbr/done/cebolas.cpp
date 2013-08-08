#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#define EPS 1e-6
#define INF 1e9

using namespace std;

vector<pair<int, int> > vp;

int dist(int x1, int y1, int x2, int y2) { return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2); }

int prod(int x1, int y1, int x2, int y2, int x3, int y3) { return x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2); }

void convex_hull()
{
    int i, vis[2000];
    vector<pair<int, int> > aux;
    for(i=0;i<vp.size();i++) vis[i] = 0;
    int p, xmin=INF;
    for(i=0;i<vp.size();i++) if(vp[i].first < xmin) xmin = vp[i].first, p=i;
    int d, dmin, pos, newp;
    while(!vis[p]) {
        vis[p] = 1;
        newp = p;
        dmin = INF;
        for(i=0;i<vp.size();i++) if(i != p) {
            d = dist(vp[i].first, vp[i].second, vp[p].first, vp[p].second);
            pos = prod(vp[p].first, vp[p].second, vp[newp].first, vp[newp].second, vp[i].first, vp[i].second);
            if((pos == 0 && d < dmin) || pos > 0) {
                newp = i;
                dmin = d;
            }
        }
        p = newp;
    }
    for(i=0;i<vp.size();i++) if(!vis[i]) aux.push_back(vp[i]);
    vp = aux;
}

int main()
{
    int N, cam, x, y, i;
    while(scanf("%d", &N) && N)
    {
        for(i=0;i<N;i++) {
            scanf("%d%d", &x, &y);
            vp.push_back(make_pair(x, y));
        }
        i = vp.size();
        for(cam=1; true; cam++) {
            convex_hull();
            if(vp.size() == i) break;
            i = vp.size();
            if(vp.empty()) break;
        }
        if((cam % 2) == 0) printf("Do not take this onion to the lab!\n");
        else printf("Take this onion to the lab!\n");
    }
    return 0;
}
