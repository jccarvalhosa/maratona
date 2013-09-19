#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#define EPS 1e-12
using namespace std;

double dp[111][111];
string op[111];
int n, T;

int conv(string s) {
    stringstream ss(s);
    int delta; ss>>delta;
    return delta;
}

double play(int pos, int turn) {
    if(pos >= n) return 1;
    if(op[pos] == "L") {
        if(turn == T) return 0;
        return dp[pos][turn+1];
    }
    int delta = conv(op[pos]);
    return dp[pos+delta][turn];
}

int main() {
    int tests;
    cin>>tests;
    while(tests--) {
        cin>>n>>T;
        n++;
        for(int i=1;i<n;i++) cin>>op[i];
        for(int i=0;i<n;i++) dp[i][T] = 0;
        dp[n][T] = 1;
        for(int i=T-1;i>=0;i--) for(int j=0;j<n;j++) dp[j][i] = (play(j+1, i+1) + play(j+2, i+1)) / 2;
        double ans = dp[0][0];
        if(ans < 0.5 - EPS) printf("Bet against. %.4lf\n", ans);
        else if(ans > 0.5 + EPS) printf("Bet for. %.4lf\n", ans);
        else printf("Push. %.4lf\n", ans);
    }
    return 0;
}
