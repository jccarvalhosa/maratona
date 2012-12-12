#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

typedef vector<string> vs;

int N, M, G[5][20];
vector<string> nome(5), num(5);

int validline(int line) {
    int i, sum = 0;
    for(i=0;i<M-1;i++) sum += G[line][i];
    return sum == G[line][M-1];
}

int validcol(int col) {
    int i, sum=0;
    for(i=0;i<N-1;i++) sum += G[i][col];
    return sum == G[N-1][col];
}

int conv(string s) {
    int i, n=0, b=1;
    for(i=s.size()-1;i>=0;i--) {
        n += b*(s[i] - '0');
        b *= 10;
    }
    return n;
}

int corta(int a, int b) {
    int i, j, sl=0, sc=0;
    for(i=a;i<N-1;i++) sl += G[i][b];
    if(sl > G[N-1][b]) return 1;
    for(j=b;j<M-1;j++) sc += G[a][j];
    if(sc > G[a][M-1]) return 1;
    return 0;
}

int dfs(int a, int b, int ind) {
    if(b < 0) {
        if(ind <= 0 && validline(a)) return dfs(a-1, M-1, a > 0 ? num[a-1].size()-1 : -1);
        return 0;
    }
    if(a < 0) {
        for(int j=0;j<M;j++) if(!validcol(j)) return 0;
        return 1;
    }
    string val = "";
    for(int i=ind;i>=0;i--) {
        val = num[a][i] + val;
        if(a != N-1 && b != M-1 && ind - i > 2) break;
        if(num[a][i] == '0' && i != ind) continue;
        G[a][b] = conv(val);
        if(corta(a, b)) break;
        if(b == M-1 && dfs(a, b-1, i-1)) return 1;
        else if(dfs(a, b-1, i-1)) return 1;
    }
    return 0;
}

int main()
{
    int C, i, j;
    string s;
    scanf("%d", &C);
    while(C--) {
        cin >> s;
        N = 0; M = 1;
        num.clear(); nome.clear();
        for(i=0;i<s.size();i++) if(s[i] == 'P') M++;
        for(i=0;true;i++) {
            cin >> s;
            N++;
            nome[i] = num[i] = "";
            for(j=0; s[j] > '9' || s[j] < '0'; j++) nome[i] += s[j];
            for(; j < s.size(); j++) num[i] += s[j];
            if(s[0] == 'T' && s[1] == 'P') break;
        }
        for(i=1;i<M;i++) printf("P%d ", i);
        printf("Totals\n");
        dfs(N-1, M-1, num[N-1].size()-1);
        for(i=0;i<N;i++) {
            cout << nome[i];
            for(j=0;j<M;j++) printf(" %d", G[i][j]);
            printf("\n");
        }
    }
    return 0;
}
