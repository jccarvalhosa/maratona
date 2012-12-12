#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#define EPS 1e-9
#define INF 1000000000

using namespace std;

typedef vector<pair<double, double> > vpdd;
typedef pair<double, double> pdd;

vpdd f[4], resp[4], l, c;
int X, Y; 
double r[1000], at[2], bt[2], ct[2], reta[4][3], coord[4][6];

void tangentes(double xp, double yp, double xc, double yc, double r)
{
    double a = (xc-xp)*(xc-xp) - r*r;
    double b = -2*(xc-xp)*(yc-yp);
    double c = (yc-yp)*(yc-yp) - r*r;
    if(a == 0)
    {
        at[0] = 1;
        bt[0] = 0;
        ct[0] = -xp;
        at[1] = c;
        bt[1] = b;
        ct[1] = -(at[1]*xp+bt[1]*yp);
    }
    else
    {
        at[0] = b+sqrt(b*b-4*a*c);
        at[1] = b-sqrt(b*b-4*a*c);
        bt[0] = bt[1] = 2*a;
        ct[0] = -(at[0]*xp+bt[0]*yp);
        ct[1] = -(at[1]*xp+bt[1]*yp);
    }
}

double dpr(pdd p, double *r) { return fabs(r[0]*p.first + r[1]*p.second + r[2]) / sqrt(r[0]*r[0]+r[1]*r[1]); }

void intercepta(int a, int i, int j)
{
    double ini, fim, dl, dc;
    dl = dpr(l[i], reta[a]);
    dc = dpr(c[j], reta[a]);
    if(dl < dc - r[j] + EPS) return;
    if(reta[a][0] < EPS)
    {
        if(fabs(at[0]) > EPS) ini = (bt[0]*reta[a][2]/reta[a][1] - ct[0]) / at[0];
        else if(l[i].first < c[j].first) ini = INF;
        else ini = -INF;
        if(fabs(at[1]) > EPS) fim = (bt[1]*reta[a][2]/reta[a][1] - ct[1]) / at[1];
        else if(l[i].first < c[j].first) fim = INF;
        else fim = -INF;
    }
    else
    {
        if(fabs(bt[0]) > EPS) ini = (at[0]*reta[a][2]/reta[a][0] - ct[0]) / bt[0];
        else if(l[i].second < c[j].second) ini = INF;
        else ini = -INF;
        if(fabs(bt[1]) > EPS) fim = (at[1]*reta[a][2]/reta[a][0] - ct[1]) / bt[1];
        else if(l[i].second < c[j].second) fim = INF;
        else fim = -INF;
    }
    if(ini > fim) swap(ini, fim);
    if(dl < dc + r[j] - EPS)
    {
        if((reta[a][0] < EPS && l[i].first < c[j].first) || reta[a][0] > EPS && l[i].second < c[j].second)
        {
            ini = fim;
            fim = INF;
        }
        else
        {
            fim = ini;
            ini = -INF;
        }
    }
    if(ini > coord[a][3]) return;
    if(fim < coord[a][0]) return;
    if(ini < coord[a][0]) ini = coord[a][0];
    if(fim > coord[a][3]) fim = coord[a][3];
    f[a].push_back(make_pair(ini, fim));
}

void bloqueia(int i, int j)
{   
    tangentes(l[i].first, l[i].second, c[j].first, c[j].second, r[j]);
    for(int n=0;n<4;n++) intercepta(n, i, j);
}

vpdd join(vpdd v)
{
    vpdd u;
    if(v.empty()) return v;
    sort(v.begin(), v.end());
    u.push_back(v[0]);
    for(int i=1;i<v.size();i++)
    {
        if(v[i].first > u[u.size()-1].second) u.push_back(v[i]);
        else u[u.size()-1].second = max(u[u.size()-1].second, v[i].second);
    }
    return u;
}

vpdd reverse(vpdd v, double m)
{
    vpdd u;
    if(v.empty()) u.push_back(make_pair(0, m));
    else
    {
        if(v[0].first > 0) u.push_back(make_pair(0, v[0].first));
        for(int i=1;i<v.size();i++) u.push_back(make_pair(v[i-1].second, v[i].first));
        if(v[v.size()-1].second < m) u.push_back(make_pair(v[v.size()-1].second, m));
    }
    return u;
}

int main()
{
    int L, C, i, j, k, z;
    double x, y, p;
    memset(coord, 0, sizeof(coord));
    memset(reta, 0, sizeof(reta));
    reta[0][1] = reta[1][0] = reta[2][1] = reta[3][0] = 1;
    while(scanf("%d%d%d%d", &L, &C, &X, &Y) && L)
    {
        l.clear(); c.clear(); 
        for(i=0;i<4;i++) resp[i].clear();
        reta[1][2] = -X;
        reta[2][2] = -Y;
        coord[0][3] = coord[0][4] = coord[1][1] = coord[1][4] = coord[2][3] = coord[2][4] = X;
        coord[1][3] = coord[1][5] = coord[2][2] = coord[2][5] = coord[3][3] = coord[3][5] = Y;
        for(i=0;i<L;i++)
        {
            scanf("%lf%lf", &x, &y);
            l.push_back(make_pair(x, y));
        }
        for(i=0;i<C;i++)
        {
            scanf("%lf%lf%lf", &x, &y, &r[i]);
            c.push_back(make_pair(x, y));
        }
        for(i=0;i<L;i++)
        {
            for(k=0;k<4;k++) f[k].clear();
            for(j=0;j<C;j++) bloqueia(i, j);
            for(k=0;k<4;k++)
            {
                f[k] = reverse(join(f[k]), k % 2 ? Y : X);
                for(z=0;z<f[k].size();z++) resp[k].push_back(f[k][z]);
            }
        }
        p = 0;
        for(i=0;i<4;i++)
        {
            resp[i] = join(resp[i]);
            for(j=0;j<resp[i].size();j++) p += resp[i][j].second - resp[i][j].first;
        }
        printf("%.4lf\n", p);
    }
    return 0;
}
