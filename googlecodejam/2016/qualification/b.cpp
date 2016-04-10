#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int dp[105][2];

int main() {
  int T;
  cin>>T;
  for (int t=1; t <= T; t++) {
    string s;
    cin>>s;
    int n = s.size();
    for (int i=0; i < n; i++) {
      if (s[i] == '+') {
        dp[i+1][1] = dp[i][0] + 1;
        dp[i+1][0] = dp[i][0];
      }
      else {
        dp[i+1][0] = dp[i][1] + 1;
        dp[i+1][1] = dp[i][1];
      }
    }
    printf("Case #%d: %d\n", t, dp[n][0]);
  }
  return 0;
}
