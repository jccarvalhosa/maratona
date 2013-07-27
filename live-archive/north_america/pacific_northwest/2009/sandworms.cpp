#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> vp;
typedef pair<vp, int> pvi;
#define pb push_back
#define all(v) v.begin(), v.end()

vector<string> tab;
int n, m;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

int valid(vp v) {
    if(v[0].first < 0) return 0;
    if(v[0].second < 0) return 0;
    if(v[0].first >= n) return 0;
    if(v[0].second >= m) return 0;
    int c[10];
    memset(c, 0, sizeof(c));
    for(int i=0;i<n;i++) c[ tab[v[i].first][v[i].second] - '0' ]++;
    for(int i=0;i<10;i++) if(c[i]>1) return 0;
    return 1;
}

int bfs() {
    queue<pvi> q;
    set<vp> vis;
    vp v;
    for(int i=0;i<n;i++) v.pb(pii(i, 0));
    q.push(pvi(v, 0));
    vis.insert(v);
    reverse(all(v));
    q.push(pvi(v, 0));
    vis.insert(v);
    while(!q.empty()) {
        v = q.front().first;
        int d = q.front().second;
        if(v[0]==pii(0, m-1) && v[n-1]==pii(n-1, m-1)) return d;
        if(v[n-1]==pii(0, m-1) && v[0]==pii(n-1, m-1)) return d;
        q.pop();
        for(int j=0;j<2;j++) {
            if(j==1) reverse(all(v));
            for(int i=0;i<4;i++) {
                pii h;
                h.first = v[0].first + dx[i];
                h.second = v[0].second + dy[i];
                vp u;
                u.pb(h);
                for(int k=0;k<n-1;k++) u.pb(v[k]);
                if(!valid(u)) continue;
                if(!vis.count(u)) q.push(pvi(u, d+1));
                vis.insert(u);
                reverse(all(u));
                if(!vis.count(u)) q.push(pvi(u, d+1));
                vis.insert(u);
            }
        }
    }
    return -1;
}

char str[222];
int main() {
    string s;
    while(1) {
        while(1) {
            scanf("%[^\n]", str);
            getchar();
            s = str;
            if(s == "end") break;
            if(str[0]=='\0') break;
            tab.push_back(s);
            str[0]='\0';
        }
        if(s == "end") break;
        n = tab.size();
        m = tab[0].size();
        cout << bfs() << endl;
        tab.clear();
    }
}
