#include <stdio.h>
#include <algorithm>
#define INF 1e9

using namespace std;

int N, Q, S, v[100], val[3], vs[3];
int preju[100][502][502], soma[100], mprej;

int calcprej(int a, int b, int c) { return max(0, a-Q) + max(0, b-Q) + max(0, c-Q); }

void dfs(int pos) {
    int i, a, b, c, msol, disp=0;
    for(i=0;i<3;i++) vs[i] = val[i];
    sort(vs, vs+3);
    a = min(vs[0], Q+1);
    b = min(vs[1], Q+1);
    if(preju[pos][a][b] == INF) {
        for(i=0;i<3;i++) disp += max(0, Q-val[i]);
        c = calcprej(val[0], val[1], val[2]);
        msol = c + max(0, soma[pos] - disp);
        if(msol < mprej) {
            vs[0] += soma[pos];
            preju[pos][a][b] = calcprej(vs[0], vs[1], vs[2]);
            mprej = min(mprej, preju[pos][a][b]);
            if(pos+1 < N) {
                for(i=0;i<3;i++) {
                    val[i] += v[pos+1];
                    dfs(pos+1);
                    val[i] -= v[pos+1];
                }
            }
        }
    }
}

int main()
{
    double A;
    int i, j, k, p, S;
    scanf("%d%d%lf", &N, &Q, &A);
    for(i=S=0;i<N;i++) {
        scanf("%d", &v[i]);
        S+=v[i];
        soma[i]=S;
    }
    for(i=0;i<N;i++) soma[i] = S - soma[i];
    mprej = INF;
    if(S > 6*Q) mprej = S - 3*Q;
    else {
        for(i=0;i<N;i++) for(j=0;j<=Q+1;j++) for(k=0;k<=Q+1;k++) preju[i][j][k] = INF;
        val[0] = v[0];
        val[1] = val[2] = 0;
        dfs(0);
    }
    printf("%.2lf\n", A*mprej/100);
}
