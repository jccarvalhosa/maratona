#include <cstdio>
#include <vector>
#include <iostream>
#define INF 1000000000
using namespace std;

int n, c, val[11111];
int child[11111][2];

void dfs_pre(int a, int b) {
    int i = c;
    int v = val[c];
    c++;
    if(c!=n && val[c] < v && val[c] > a) {
        child[i][0] = c;
        dfs_pre(a, v);
    }
    if(c!=n && val[c] > v && val[c] < b) {
        child[i][1] = c;
        dfs_pre(v, b);
    }
}

void dfs_pos() {
    int i = c;
    int v = val[c];
    c++;
    if(child[i][0] != -1) dfs_pos();
    if(child[i][1] != -1) dfs_pos();
    cout<<v<<endl;
}

int main() {
    n=0;
    while(scanf("%d", &val[n]) != EOF) n++;
    for(int i=0;i<n;i++) child[i][0] = child[i][1] = -1;
    c=0;
    dfs_pre(-INF, INF);
    c=0;
    dfs_pos();
    return 0;
}
