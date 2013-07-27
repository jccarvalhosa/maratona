#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
typedef pair<int, int> pt;
#define x first
#define y second
#define INF 1e15
#define L 1000000
#define mp make_pair
typedef long long ll;

int mod(int a) { return a>0?a:-a; }

double abs(pt a, pt b) { return hypot(a.x - b.x, a.y - b.y); }

ll cross(pt a, pt b) { return 1ll*a.x*b.y - 1ll*a.y*b.x; }

int colinear(pt a, pt b, pt c) { return cross(b, c) - cross(a, c) + cross(a, b) == 0; }

int main() {
    int x1, y1, x2, y2;
    int n, i, j;
    while(1) {
        cin>>x1>>y1>>x2>>y2>>n;
        if(n==0) break;
        vector<pair<double, pt> > v;
        for(i=-n;i<=n;i++) for(j=-n;j<=n;j++) {
            if(mod(i) + mod(j) > n) continue;
            int nx, ny;
            if(i%2==0) nx = i*L + x2;
            else nx = i*L + (L-x2);
            if(j%2==0) ny = j*L + y2;
            else ny = j*L + (L-y2);
            double d = abs(pt(nx, ny), pt(x1, y1));
            v.push_back(mp(d, pt(nx, ny)));
        }
        sort(v.begin(), v.end());
        double best=INF;
        for(i=0;i<v.size();i++) {
            for(j=i+1;j<v.size();j++) if(!colinear(v[i].second, pt(x1, y1), v[j].second)) break;
            if(j < v.size()) best = min(best, v[j].first-v[i].first);
        }
        printf("%.5lf\n", best);
    }
    return 0;
}
