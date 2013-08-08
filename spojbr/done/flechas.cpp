#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

int mod(int a) { return a > 0 ? a : -a; }

int N, G[10][10], S[10][10];
int sum, perd, cont;
int d0[] = {4, 5, 6};
int d1[] = {6, 7, 8};
int d2[] = {1, 2, 8};
int d3[] = {2, 3, 4};

string conv(int a) {
    switch(a) {
        case 0: return "  ";
        case 1: return " N";
        case 2: return "NE";
        case 3: return " E";
        case 4: return "SE";
        case 5: return " S";
        case 6: return "SW";
        case 7: return " W";
        case 8: return "NW";
    }
}

int valid() {
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(G[i][j] != S[i][j]) return 0;
    return 1;
}

int loopv(int a, int b, int v) { 
    if(b % (N+1) == 0) return 0;
    int i, ret=1;
    for(i=1;i<=N;i++) {
        S[i][b] += v;
        if(S[i][b] > G[i][b]) ret=0;
    }
    return ret;
}

int looph(int a, int b, int v) { 
    if(a % (N+1) == 0) return 0;
    int i, ret=1;
    for(i=1;i<=N;i++) {
        S[a][i] += v;
        if(S[a][i] > G[a][i]) ret=0;
    }
    return ret;
}

int loopd1(int a, int b, int v) { 
    int d=mod(a-b), i, ret=1;
    if(d % N == 0) return 0;
    for(i=1;i+d<=N;i++) {
        if(a > b) {
            S[i+d][i] += v;
            if(S[i+d][i] > G[i+d][i]) ret=0;
        } else {
            S[i][d+i] += v;
            if(S[i][d+i] > G[i][d+i]) ret=0;
        }
    }
    cont += v*d; 
    if(cont > perd) return 0;
    return ret;
}

int loopd2(int a, int b, int v) { 
    int d=a+b, i, ret=1;
    if(d > N) d = 2*(N+1) - d;
    if(d % N == 1) return 0;
    for(i=1;i<d;i++) {
        if(a+b <= N) {
            S[d-i][i] += v;
            if(S[d-i][i] > G[d-i][i]) ret=0;
        } else {
            S[N+1-i][N+1-d+i] += v;
            if(S[N+1-i][N+1-d+i] > G[N+1-i][N+1-d+i]) ret=0;
        }
    }
    cont += v*(N-d+1); 
    if(cont > perd) return 0;
    return ret;
}

int mark(int a, int b, int v) {
    int i, j, ret=1;
    if(G[a][b] == 1 || G[a][b] == 5) return loopv(a, b, v);
    if(G[a][b] == 2 || G[a][b] == 6) return loopd2(a, b, v);
    if(G[a][b] == 3 || G[a][b] == 7) return looph(a, b, v);
    if(G[a][b] == 4 || G[a][b] == 8) return loopd1(a, b, v);
}

int dfs(int a, int b, int dir)
{
    int *d, i;
    int na=a, nb=b, ndir=dir;
    if(dir == 0) {
        d = d0;
        if(nb == N+1) na++, ndir=1;
        else nb++;
    }
    else if(dir == 1) {
        d = d1;
        if(na == N+1) nb--, ndir=2;
        else na++;
    }
    else if(dir == 2) {
        d = d2;
        if(nb == 0) na--, ndir=3;
        else nb--;
    }
    else if(dir == 3) {
        d = d3;
        if(na == 0) return valid();
        else na--;
    }
    if((a % (N+1) == 0) && (b % (N+1) == 0)) return dfs(na, nb, ndir);
    for(i=0;i<3;i++) {
        G[a][b] = *(d+i);
        if(mark(a, b, 1) && dfs(na, nb, ndir)) return 1;
        mark(a, b, -1);
    }
    G[a][b] = 0;
    return 0;
}

int main()
{
    int i, j, teste=1;
    while(scanf("%d", &N) && N) 
    {
        memset(G, 0, sizeof(G));
        memset(S, 0, sizeof(S));
        sum = 0;
        for(i=1;i<=N;i++) for(j=1;j<=N;j++){
            scanf("%d", &G[i][j]);
            sum += G[i][j];
        }
        perd = 4*N*N-sum;
        cont=0;
        printf("Instancia #%d:\n", teste++);
        if(sum <= 4*N*N && sum >= 4*N && dfs(0, 0, 0)) {
            for(j=0;j<=N+1;j++) cout << conv(G[0][j]) << " ";
            printf("\n");
            for(i=1;i<=N;i++) {
                cout << conv(G[i][0]) << " ";
                for(j=1;j<=N;j++) printf(" %d ", G[i][j]);
                cout << conv(G[i][N+1]) << endl;
            }
            for(j=0;j<=N+1;j++) cout << conv(G[N+1][j]) << " ";
        }
        else printf("sem solucao");
        printf("\n\n");
    }
    return 0;
}
